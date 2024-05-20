FROM debian:buster

RUN apt update -y
RUN apt upgrade -y
RUN apt install nginx -y
RUN mkdir -p /etc/nginx/ssl

RUN apt install openssl -y
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/kpoilly.crt\
 -keyout /etc/nginx/ssl/kpoilly.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=kpoilly.42.fr/UID=kpoilly"

COPY ./conf/nginx.conf /etc/nginx/

RUN mkdir -p /var/run/nginx
RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]