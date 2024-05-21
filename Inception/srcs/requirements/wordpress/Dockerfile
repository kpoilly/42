FROM debian:buster

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get -y install wget
RUN apt-get install -y php php-fpm \
	php-cgi php-mysql mariadb-client \
	php-pdo php-gd php-cli

RUN mkdir /run/php
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/.

EXPOSE 9000

COPY ./tools/config_auto.sh /usr/local/bin
RUN chmod +x /usr/local/bin/config_auto.sh
CMD ["/usr/local/bin/config_auto.sh"]