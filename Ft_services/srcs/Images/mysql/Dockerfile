FROM alpine
RUN apk update
RUN apk add mariadb mariadb-client

COPY ./user.sql .
COPY ./init.sh .
COPY new.sql /mysql.sql
COPY mariadb-server.cnf /etc/my.cnf.d/mariadb-server.cnf

RUN mkdir -p /run/mysqld
RUN chmod 777 ./init.sh 

EXPOSE 3306

CMD ["./init.sh"]
