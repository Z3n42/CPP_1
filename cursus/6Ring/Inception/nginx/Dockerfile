FROM debian:oldstable


RUN apt-get update && apt-get install -y \
	nginx \
	# certbot \ 
	# python3-certbot-nginx \
	# wget \
	net-tools \
	openssl \
	procps \
	tini \
	vim \
	dnsmasq

# COPY nginx/nginx.conf /etc/nginx/conf.d/nginx.conf
# COPY nginx/default.conf /etc/nginx/conf.d/default.conf
# COPY nginx/cert.sh 	/tmp/cert.sh	

# RUN ["chmod", "+x", "/tmp/cert.sh"]
# RUN /tmp/cert.sh

# COPY nginx/my-site.crt /etc/ssl/certs/my-site.crt
# COPY nginx/my-site.key /etc/ssl/private/my-site.key
# RUN /tmp/init-letsencrypt.sh

# ENTRYPOINT ["/usr/bin/tini", "--"]
# ENTRYPOINT ["/tmp/cert.sh"]

COPY nginx/cert.sh /usr/src/app/entrypoint.sh
RUN ["chmod", "+x", "/usr/src/app/entrypoint.sh"]
# ENTRYPOINT /usr/src/app/entrypoint.sh
ENTRYPOINT ["/usr/bin/tini", "--"]
# CMD ["nginx", "-g", "daemon off;"]
CMD /usr/src/app/entrypoint.sh
