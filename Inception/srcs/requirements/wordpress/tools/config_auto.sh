#!/bin/sh

# if test -f "/var/www/html/wp-config.php";
# then
# 	echo "wordpress already set"
# else

mkdir /var/www/
mkdir /var/www/html
cd /var/www/html

wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

wp core download --allow-root
wp config create --allow-root \
					--dbname=$SQL_DATABASE \
					--dbuser=$SQL_USER \
					--dbpass=$SQL_PASSWORD \
					--dbhost=mariadb:3306 --path='/var/www/html'
wp core install --url=kpoilly.42.fr --title=inception --admin_user=kpoilly \
				--admin_password=kpoilly42 --admin_email=kpoilly@student.42.fr \
				--allow-root

chmod 755 -R /var/www/wordpress/wp-content
# fi

/usr/sbin/php-fpm7.3 -F
exec "$@"