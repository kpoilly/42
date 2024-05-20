FROM debian:buster

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get -y install wget
RUN apt-get install -y php7.3 php-fpm \
	php-mysql mariadb-client

RUN wget https://fr.wordpress.org/wordpress-6.5.3-fr_FR.tar.gz -P /var/www
RUN cd /var/www && tar -xzf wordpress-6.5.3-fr_FR.tar.gz && rm wordpress-6.5.3-fr_FR.tar.gz
RUN	chown -R root:root /var/www/wordpress

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d
RUN mkdir /run/php

COPY ./tools/config_auto.sh /usr/local/bin
RUN chmod +x /usr/local/bin/config_auto.sh
ENTRYPOINT ["/usr/local/bin/config_auto.sh"]

WORKDIR /var/www/html
EXPOSE 9000

CMD ["/usr/sbin/php-fpm7.3", "-F"]