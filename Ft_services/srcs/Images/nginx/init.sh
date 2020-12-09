#! /bin/bash
ssh-keygen -A
adduser -D username
echo "username:password" | chpasswd
/usr/sbin/sshd
nginx

while [[ $(pgrep nginx) ]] && [[ $(pgrep sshd) ]]; 
do 
	sleep 1 
done

pkill nginx
pkill sshd