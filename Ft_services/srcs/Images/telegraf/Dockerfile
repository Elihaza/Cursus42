FROM alpine
RUN apk update
RUN apk add bash

RUN	wget https://dl.influxdata.com/telegraf/releases/telegraf-1.14.0-static_linux_amd64.tar.gz ; \
	tar -C . -xvf telegraf-1.14.0-static_linux_amd64.tar.gz ; \
	chmod +x telegraf/* ; \
  cp telegraf/telegraf /usr/bin/ ; \
  rm -rf *.tar.gz* telegraf

COPY ./telegraf.conf /etc/telegraf.conf
COPY ./init.sh .
RUN chmod 777 ./init.sh
CMD ["./init.sh"]
