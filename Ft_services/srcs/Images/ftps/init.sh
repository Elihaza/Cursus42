#! /bin/bash
USER=username
PASSWORD=password
adduser -D $USER
echo "$USER:$PASSWORD" | chpasswd
#mkdir /home/$USER/ftp
#chown $USER:$USER /home/$USER/ftp
#chmod a-w /home/$USER/ftp
#mkdir /home/$USER/ftp/test
#chown $USER:$USER /home/$USER/ftp/test
echo $USER > /etc/vsftpduserlist.conf
mkdir /var/run/vsftpd
mkdir /var/run/vsftpd/empty


/usr/sbin/vsftpd /etc/vsftpd.conf


while [[ $(pgrep vsftpd) ]]; 
do 
	sleep 1 
done