#! /bin/bash
service nginx stop
sudo apt-get update -y
sudo apt-get -y dist-upgrade
sudo apt-get autoremove -y
sudo apt-get install docker.io
sudo systemctl start docker
sudo systemctl enable docker
sudo chown user42:user42 /var/run/docker.sock
sudo usermod -aG sudo $USER
sudo rm -rf /usr/local/bin/kubectl
sudo rm -rf /usr/local/bin/minikube
curl -LO https://storage.googleapis.com/kubernetes-release/release/$(curl -s https://storage.googleapis.com/kubernetes-release/release/stable.txt)/bin/linux/amd64/kubectl
chmod +x ./kubectl
sudo mv ./kubectl /usr/local/bin/kubectl
curl -Lo minikube https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64
chmod +x minikube
sudo mkdir -p /usr/local/bin/
sudo cp minikube /usr/local/bin && rm minikube
minikube delete
minikube start --driver=docker
minikube addons enable metallb
kubectl apply -f https://raw.githubusercontent.com/google/metallb/v0.8.1/manifests/metallb.yaml
./srcs/Scripts/metalip.sh
kubectl apply -f ./srcs/Services/metallb.yaml
minikube dashboard &
./srcs/Scripts/deploy.sh
