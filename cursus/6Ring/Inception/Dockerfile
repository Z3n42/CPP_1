FROM debian:oldstable


RUN apt-get update && apt-get install -y \
	nginx

# COPY default.conf /etc/nginx/conf.d/default.conf
 

CMD ["nginx", "-g", "daemon off;"]
