cp ./srcs/Services/metallbT.yaml ./srcs/Services/metallb.yaml

baseip=$(minikube ip 2>&1)
endip=$(echo $baseip | sed 's/\.[0-9]*$/.0/' | rev | cut -c2- | rev 2>&1)
endip=$(echo "$endip"'245' 2>&1)
echo "$baseip""-""$endip" >> ./srcs/Services/metallb.yaml
cp ./srcs/Images/telegraf/telegrafT.conf ./srcs/Images/telegraf/telegraf.conf
echo "	url = \"https://""$baseip"":10250\"" >> ./srcs/Images/telegraf/telegraf.conf
