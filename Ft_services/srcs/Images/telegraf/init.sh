#! /bin/sh
mkdir /etc/telegraf
cp /etc/telegraf.conf /etc/telegraf/telegraf.conf
export TELEGRAF_CONFIG_PATH=/etc/telegraf.conf
/usr/bin/telegraf
