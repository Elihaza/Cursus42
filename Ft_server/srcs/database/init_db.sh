echo "CREATE DATABASE wordpress;" | mysql -u root 
echo "CREATE USER 'wordpress'@'localhost' IDENTIFIED BY 'wpassword';" | mysql -u root
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'wordpress'@'localhost';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root
mysql wordpress -u root < /ft_server/database/database.sql
