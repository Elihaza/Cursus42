FROM alpine
RUN apk update
RUN apk add unzip nginx procps php php-fpm php-mbstring php-mysqli bash php7-json php7-session
RUN mkdir -p /run/nginx
RUN mkdir -p /run/php
RUN mkdir /www
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./nginx.conf /etc/nginx/.
COPY ./nginx.crt /etc/nginx/.
COPY ./nginx.key /etc/nginx/.
COPY ./www.conf /etc/php7/php-fpm.d/www.conf 
COPY ./init.sh .
COPY ./phpMyAdmin-5.0.2-all-languages.zip .
RUN unzip phpMyAdmin-5.0.2-all-languages.zip -d /www
COPY ./config.inc.php /www/phpMyAdmin-5.0.2-all-languages/config.inc.php
RUN chmod 777 ./init.sh 
EXPOSE 5000
CMD ["./init.sh"]