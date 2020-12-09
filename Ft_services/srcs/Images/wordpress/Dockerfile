FROM alpine
RUN apk update
RUN apk add nginx procps php php-fpm php-mbstring php-mysqli bash tar php7-json php7-session
RUN mkdir -p /run/nginx
RUN mkdir -p /run/php
RUN chmod -R 777 /var/log/nginx
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./nginx.conf /etc/nginx/.
COPY ./www.conf /etc/php7/php-fpm.d/www.conf 
RUN mkdir /www
COPY ./init.sh .
COPY ./wp-config.php /wp-config.php
COPY wordpress.tar.gz /wordpress.tar.gz
RUN tar -zxvf /wordpress.tar.gz -C /www
RUN chmod 777 ./init.sh 
EXPOSE 5050
CMD ["./init.sh"]