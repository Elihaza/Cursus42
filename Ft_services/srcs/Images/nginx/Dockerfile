FROM alpine
RUN apk update
RUN apk add nginx openssl openssh bash
COPY ./init.sh .
COPY ./nginx.conf /etc/nginx/.
COPY ./nginx.crt /etc/nginx/.
COPY ./nginx.key /etc/nginx/.
RUN chmod 777 ./init.sh 
RUN mkdir -p /run/nginx
RUN echo "Hello world" > /var/www/index.html
RUN chmod -R 777 /var/log/nginx
EXPOSE 80 443 22
CMD ["./init.sh"]
