FROM ubuntu:latest

RUN apt-get update
RUN apt-get install bind9 -y
RUN apt-get install dnsutils -y
RUN apt-get -y install iproute2
RUN apt-get install net-tools -y
RUN apt-get install traceroute -y
RUN apt-get install -y systemctl

COPY ./script.sh ./
# limpia /r del script
RUN sed -i 's/\r$//' script.sh
COPY ./project-zones/. /etc/bind/

CMD ["sh", "script.sh"]