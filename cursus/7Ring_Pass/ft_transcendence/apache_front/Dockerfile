FROM debian:bookworm

RUN apt-get update && \
    apt-get install -y apache2 openssl && \
    apt-get clean

RUN a2enmod ssl rewrite

RUN update-ca-certificates

COPY conf/apache2.conf /etc/apache2/apache2.conf
COPY conf/000-default.conf /etc/apache2/sites-available/000-default.conf

EXPOSE 80
EXPOSE 443

CMD ["apachectl", "-D", "FOREGROUND"]
