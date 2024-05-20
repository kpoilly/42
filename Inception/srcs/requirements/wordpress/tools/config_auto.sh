#!/bin/sh

sleep 10

if test -f "/var/www/html/wp-config.php";
then
	echo "wordpress already set"
else
	wp core download --allow-root
	wp config create --allow-root \
					 --dbname=$SQL_DATABASE \
					 --dbuser=$SQL_USER \
					 --dbpass=$SQL_PASSWORD \
					 --dbhost=mariadb:3306 --path='/var/www/wordpress'
	wp core install --url=kpoilly.42.fr --title=inception --admin-user=kpoilly \
					--admin_password=kpoilly42 --admin_email=kpoilly@student.42.fr \
					--allow-root

	chmod 755 -R /var/www/wordpress/wp-content
fi

exec "$@"