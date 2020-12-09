#! /bin/bash

php-fpm7
chmod 777 /var/run/php/sock
nginx
while [[ $(pgrep nginx) ]] && [[ $(pgrep php-fpm7) ]]; 
do 
	sleep 1 
done
pkill nginx
pkill php-fpm7