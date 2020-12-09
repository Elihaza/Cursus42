function servip()
{
	kubectl get services  | grep $1 | awk '{print $4}' | grep .
}

function sqlip()
{
	ip=$(servip wordpress)
	cat ./srcs/Images/mysql/mysql.sql > ./srcs/Images/mysql/new.sql
	echo "(1, 'siteurl', 'http://"$ip":5050', 'yes')," >> ./srcs/Images/mysql/new.sql
	echo "(2, 'home', 'http://"$ip":5050', 'yes')," >> ./srcs/Images/mysql/new.sql
	cat ./srcs/Images/mysql/2.sql >> ./srcs/Images/mysql/new.sql
}

function ftpsip()
{
	ip=$(servip wordpress)
	cat ./srcs/Images/ftps/vsftpd.conf1 > ./srcs/Images/ftps/vsftpd.conf 
	echo "pasv_address="$ip"" >> ./srcs/Images/ftps/vsftpd.conf
	cat ./srcs/Images/ftps/vsftpd.conf2 >> ./srcs/Images/ftps/vsftpd.conf
}

function deploy()
{
	docker build -t $1 ./srcs/Images/$1/.
	kubectl apply -f ./srcs/Services/$1.yaml
}

eval $(minikube docker-env)
docker system prune -f
deploy influxdb
deploy telegraf
deploy grafana
deploy nginx
deploy wordpress
deploy phpmyadmin
sqlip
deploy mysql
ftpsip
deploy ftps
