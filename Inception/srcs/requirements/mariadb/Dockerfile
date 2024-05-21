FROM debian:buster

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install mariadb-server -y

RUN mkdir -p /var/run/mysqld \
&& chown -R mysql:mysql /var/run/mysqld \
&& chmod 777 /var/run/mysqld

EXPOSE 3306

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/.

COPY ./tools/mysql_setup.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/mysql_setup.sh
ENTRYPOINT ["/usr/local/bin/mysql_setup.sh"]

CMD ["mysqld"]