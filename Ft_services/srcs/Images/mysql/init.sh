#! /bin/sh

if [[ $(ls /var/lib | grep lock) ]]; 
then
	echo "found the lock, not creating" >> /scriptlog
	mysqld --user=root --datadir=/var/lib/mysql
fi
	echo "lock not found, creating" >> /scriptlog
	touch /var/lib/lock
	mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql
	
	mysqld --user=root &


	sleep 5

	mysql -u root -ptoor < /user.sql
	mysql -u root -ptoor < /mysql.sql

	pkill mysqld

	mysqld --user=root
done