FROM alpine
RUN apk update
RUN apk add influxdb bash
COPY ./init.sh .
COPY ./influxdb.conf /etc/influxdb.conf
RUN chmod 777 ./init.sh 
EXPOSE 8086
CMD ["./init.sh"]
