FROM debian:bookworm

RUN apt-get update && \
    apt-get install -y apache2 openssl && \
	apt-get clean

RUN a2enmod ssl proxy proxy_http rewrite headers

COPY conf/apache2.conf /etc/apache2/apache2.conf
COPY conf/000-default.conf /etc/apache2/sites-available/000-default.conf

EXPOSE 443

CMD ["apache2ctl", "-D", "FOREGROUND"]
