FROM debian:buster

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install mariadb-server -y

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d.50-server.cnf
RUN mkdir /var/run/mysqld

COPY ./tools/mysql_setup.sh /etc/mysql/mysql_setup.sh

# RUN chmod 777 /bin/mysql_setup.sh
# RUN /bin/mysql_setup.sh

CMD ["mysqld"]