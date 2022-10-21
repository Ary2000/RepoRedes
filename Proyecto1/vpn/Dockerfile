FROM ubuntu:latest

RUN apt-get update
RUN apt-get install -y systemctl
RUN apt-get install -y wget
RUN apt-get install -y openvpn easy-rsa
RUN apt-get install -y iptables
RUN apt-get install iproute2 -y
RUN apt-get install net-tools -y
RUN apt-get install traceroute -y
RUN apt-get install curl -y
RUN apt-get install -y iputils-ping
RUN apt-get install -y syslog-ng
RUN apt-get install -y nano

COPY ./script.sh ./
# limpia /r del script
RUN sed -i 's/\r$//' script.sh

COPY ./server.conf ./
RUN sed -i 's/\r$//' server.conf

CMD sh script.sh; systemctl start syslog-ng; systemctl start openvpn-server@ ; tail -f /dev/null;
