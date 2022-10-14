FROM ubuntu:latest

RUN apt-get update && apt-get upgrade
RUN apt-get install -y systemctl
RUN apt-get install -y openvpn
RUN apt-get install -y easy-rsa
RUN apt-get install -y iptables
RUN apt-get install iproute2 -y
RUN apt-get install net-tools -y
RUN apt-get install traceroute -y
RUN apt-get install -y iputils-ping

COPY ./script.sh ./

COPY ./server.conf ./

CMD ["sh", "script.sh"]

#CMD ["tail", "-f", "/dev/null"]
