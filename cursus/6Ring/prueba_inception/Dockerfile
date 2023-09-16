FROM debian:oldstable


RUN apt-get update && apt-get install -y \
	nginx \
	vim 

COPY nginx.conf /etc/nginx/nginx.conf
COPY my-site.crt /etc/ssl/certs/my-site.crt
COPY my-site.key /etc/ssl/private/my-site.key

CMD ["nginx", "-g", "daemon off;"]
