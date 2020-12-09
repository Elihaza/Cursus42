#! /bin/sh

rm -rf /usr/share/grafana
tar -zxvf /grafana.tar.gz -C /usr/share/
grafana-server -homepath usr/share/grafana