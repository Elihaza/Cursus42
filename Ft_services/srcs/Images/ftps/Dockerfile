FROM alpine
RUN apk update
RUN apk add vsftpd openssl bash
COPY ./vsftpd.conf /etc/vsftpd.conf
RUN mkdir /etc/certs
COPY ./vsftpd.pem /vsftpd.pem
COPY ./init.sh .
RUN chmod 777 ./init.sh 
EXPOSE	20
EXPOSE	21
EXPOSE  20010
EXPOSE  20011
CMD ["./init.sh"]
