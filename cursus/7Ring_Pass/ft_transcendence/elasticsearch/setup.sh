perform_curl() {
  local url=$1
  local method=$2
  local data=$3
  local success_message=$4
  local fail_message=$5
  local check_command=$6
  local max_attempts=5
  local attempt=1

  # Check if the action is necessary
  if eval "$check_command"; then
    echo "$success_message (already exists)"
    return 0
  fi

  until response=$(curl -k -s -u "${ELASTICSEARCH_DEFAULT}:${ELASTICSEARCH_PASSWORD}" -X $method "$url" -H "Content-Type: application/json" -d "$data"); do
    if [ $attempt -ge $max_attempts ]; then
      echo "$fail_message"
      return 1
    fi
    echo "Attempt $attempt/$max_attempts failed. Retrying..."
    attempt=$((attempt + 1))
    sleep 5
  done
  echo "$response"
  echo "$success_message"
  sleep 5
}

# Create the Kibana role with necessary permissions
perform_curl "${ELASTICSEARCH_URL}/_security/role/kibana_role" "PUT" '{
  "cluster": ["all"],
  "indices": [
    {
      "names": [".kibana*", ".reporting-*", ".kibana_task_manager*", ".apm-*", "traces-apm*", "metrics-apm*", "logs-apm*"],
      "privileges": ["all"],
      "allow_restricted_indices": true
    }
  ],
  "applications": [
    {
      "application": "kibana-.kibana",
      "privileges": ["all"],
      "resources": ["*"]
    }
  ]
}' "kibana_role created" "Failed to create kibana_role after 5 attempts" \
"curl -k -s -u \"${ELASTICSEARCH_DEFAULT}:${ELASTICSEARCH_PASSWORD}\" -X GET \"${ELASTICSEARCH_URL}/_security/role/kibana_role\" | grep -q '\"found\":true'"

# Create the dev_master user with the full access role
perform_curl "${ELASTICSEARCH_URL}/_security/user/${KIBANA_USER}" "POST" '{
  "password": "'${ELASTICSEARCH_PASSWORD}'",
  "roles": ["superuser", "kibana_role"]
}' "Elasticsearch user created" "Failed to create Elasticsearch user after 5 attempts" \
"curl -k -s -u \"${ELASTICSEARCH_DEFAULT}:${ELASTICSEARCH_PASSWORD}\" -X GET \"${ELASTICSEARCH_URL}/_security/user/${KIBANA_USER}\" | grep -q '\"found\":true'"

# Change password for logstash_system user
perform_curl "${ELASTICSEARCH_URL}/_security/user/logstash_system/_password" "POST" '{
  "password": "'${ELASTICSEARCH_PASSWORD}'"
}' "Password for logstash_system user changed" "Failed to change password for logstash_system user after 5 attempts" \
"curl -k -s -u \"${ELASTICSEARCH_DEFAULT}:${ELASTICSEARCH_PASSWORD}\" -X GET \"${ELASTICSEARCH_URL}/_security/user/logstash_system\" | grep -q '\"password\":'"

# Change password for kibana_system user
perform_curl "${ELASTICSEARCH_URL}/_security/user/kibana_system/_password" "POST" '{
  "password": "'${ELASTICSEARCH_PASSWORD}'"
}' "Password for kibana_system user changed" "Failed to change password for kibana_system user after 5 attempts" \
"curl -k -s -u \"${ELASTICSEARCH_DEFAULT}:${ELASTICSEARCH_PASSWORD}\" -X GET \"${ELASTICSEARCH_URL}/_security/user/kibana_system\" | grep -q '\"password\":'"

# Create logstash_writer role with full permissions
perform_curl "${ELASTICSEARCH_URL}/_security/role/logstash_writer" "PUT" '{
  "cluster": ["all"],
  "indices": [
    {
      "names": ["django-logs-*"],
      "privileges": ["all"],
      "allow_restricted_indices": false
    }
  ],
  "applications": [],
  "run_as": [],
  "metadata": {},
  "transient_metadata": {
    "enabled": true
  }
}' "Writer role created" "Failed to create writer role after 5 attempts" \
"curl -k -s -u \"${ELASTICSEARCH_DEFAULT}:${ELASTICSEARCH_PASSWORD}\" -X GET \"${ELASTICSEARCH_URL}/_security/role/logstash_writer\" | grep -q '\"found\":true'"

# Create a new user for logstash_writer role
perform_curl "${ELASTICSEARCH_URL}/_security/user/${LOGSTASH_USER}" "POST" '{
  "password": "'${ELASTICSEARCH_PASSWORD}'",
  "roles": ["logstash_writer"]
}' "logstash user created and assigned writer role" "Failed to create logstash user after 5 attempts" \
"curl -k -s -u \"${ELASTICSEARCH_DEFAULT}:${ELASTICSEARCH_PASSWORD}\" -X GET \"${ELASTICSEARCH_URL}/_security/user/${LOGSTASH_USER}\" | grep -q '\"found\":true'"

# Create an index template for django-logs
perform_curl "${ELASTICSEARCH_URL}/_template/django-logs-template" "PUT" '{
  "index_patterns": ["django-logs-*"],
  "settings": {
    "number_of_shards": 1,
    "number_of_replicas": 1,
    "refresh_interval": "30s"
  },
  "mappings": {
    "properties": {
      "@timestamp": {
        "type": "date"
      },
      "message": {
        "type": "text"
      },
      "timestamp": {
        "type": "date"
      }
    }
  },
  "aliases": {
    "django-logs-alias": {}
  }
}' "Index template 'django-logs-template' created" "Failed to create index template 'django-logs-template' after 5 attempts" \
"curl -k -s -u \"${ELASTICSEARCH_DEFAULT}:${ELASTICSEARCH_PASSWORD}\" -X GET \"${ELASTICSEARCH_URL}/_template/django-logs-template\" | grep -q '\"distro\":true'"

# Create Elasticsearch index with all necessary characteristics
perform_curl "${ELASTICSEARCH_URL}/django-logs" "PUT" '{
  "settings": {
    "number_of_shards": 1,
    "number_of_replicas": 0
  },
  "mappings": {
    "dynamic": "true",
    "properties": {
      "@timestamp": {
        "type": "date"
      },
      "log_level": {
        "type": "keyword"
      },
      "message": {
        "type": "text",
        "fields": {
          "keyword": {
            "type": "keyword",
            "ignore_above": 256
          }
        }
      }
    }
  }
}' "Elasticsearch index created successfully" "Failed to create Elasticsearch index after 5 attempts" \
"curl -k -s -u \"${ELASTICSEARCH_DEFAULT}:${ELASTICSEARCH_PASSWORD}\" -X GET \"${ELASTICSEARCH_URL}/django-logs\" | grep -q '\"acknowledged\":true'"
