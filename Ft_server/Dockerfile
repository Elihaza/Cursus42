FROM debian:buster

RUN apt-get -y update && apt-get -y upgrade && apt-get -y install nginx vim mariadb-server mariadb-client wget
RUN apt-get -y install php php-fpm php-gd php-mysql php-cli php-curl php-json 
RUN wget https://fr.wordpress.org/latest-fr_FR.tar.gz
RUN tar -zxvf latest-fr_FR.tar.gz
RUN mv wordpress /var/www/html/wordpress
RUN chown -R www-data:www-data /var/www/html/wordpress/
RUN chmod -R 755 /var/www/html/wordpress/
RUN rm latest-fr_FR.tar.gz
RUN rm var/www/html/index.nginx-debian.html && rm /var/www/html/wordpress/wp-config-sample.php
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN tar -zxvf phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN mv phpMyAdmin-4.9.0.1-all-languages /var/www/html/phpMyAdmin
RUN rm phpMyAdmin-4.9.0.1-all-languages.tar.gz

ADD ./srcs/php.ini ./etc/php/7.3/fpm/php.ini
ADD ./srcs/default ./etc/nginx/sites-available/default
ADD ./srcs/wordpress ./etc/nginx/sites-available/wordpress
ADD ./srcs/wp-config.php ./var/www/html/wordpress/wp-config.php
ADD ./srcs/create_database create_database
ADD ./srcs/localhost.crt /etc/ssl/certs/localhost.crt
ADD ./srcs/localhost.key /etc/ssl/private/localhost.key
ADD ./srcs/init.sh init.sh
ADD ./srcs/init_db.sh init_db.sh
ADD ./srcs/script.sh script.sh

RUN sh init_db.sh

CMD ["bash", "./script.sh"]
