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
	wp core install --url=localhost --title=inception --admin-user=kpoilly \
					--admin_password=kpoilly42 --admin_email=kpoilly@student.42.fr \
					--allow-root

	# wp core install --allow-root

	# sed -i "s/username_here/$MYSQL_USER/g" wp-config-sample.php
	# sed -i "s/password_here/$MYSQL_PASSWORD/g" wp-config-sample.php
	# sed -i "s/localhost/$MYSQL_HOSTNAME/g" wp-config-sample.php
	# sed -i "s/database_name_here/$MYSQL_DATABASE/g" wp-config-sample.php
	# cp wp-config-sample.php wp-config.php
fi

exec "$@"