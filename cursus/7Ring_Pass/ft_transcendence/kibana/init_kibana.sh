# Check if Kibana is ready
until $(curl -k --output /dev/null --silent --head --fail -u "${ELASTICSEARCH_DEFAULT}:${ELASTICSEARCH_PASSWORD}" "https://kibana:5601/api/status"); do
  printf '.'
  sleep 5
done
echo "Kibana server is ready."

# Function to import saved objects
import_kibana_objects() {
  local file_path=$1
  echo "Importing Kibana objects from $file_path..."
  until curl -k -u "${KIBANA_USER}:${ELASTICSEARCH_PASSWORD}" -X POST "https://kibana:5601/api/saved_objects/_import" \
  -H "kbn-xsrf: true" \
  -F file=@$file_path; do
    echo -e "\nFailed to import objects. Retrying in 5 seconds...\n"
    sleep 5
  done
  echo -e "\nObjects imported successfully.\n"
}

# Import all saved objects
import_kibana_objects "/usr/share/kibana/visualization/objects.ndjson"