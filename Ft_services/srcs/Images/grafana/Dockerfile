FROM alpine
RUN apk update
RUN apk add tar bash
RUN apk add --no-cache grafana --repository=http://nl.alpinelinux.org/alpine/edge/testing
COPY ./init.sh .
COPY ./grafana.tar.gz .
RUN chmod 777 ./init.sh 
EXPOSE 3000
CMD ["./init.sh"]