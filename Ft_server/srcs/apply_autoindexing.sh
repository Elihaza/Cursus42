
rm -rf /etc/nginx/sites-enabled/nginx.conf
cp configs/nginx_autoindex.conf /etc/nginx/sites-enabled
service nginx restart
