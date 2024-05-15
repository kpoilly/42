FROM debian:buster
RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install mariadb-server -y

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d.50-server.cnf

COPY ./tools/mysql_setup.sh /bin
RUN chmod 777 /bin/mysql_setup.sh
RUN /bin/mysql_setup.sh