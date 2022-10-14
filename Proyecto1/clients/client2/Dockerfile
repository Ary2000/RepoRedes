FROM ubuntu

RUN apt-get update
RUN apt-get -y install systemctl
RUN apt-get -y install isc-dhcp-server
RUN apt-get -y install iproute2
RUN apt-get install net-tools -y
RUN apt-get install traceroute -y
RUN apt-get install -y udhcpc
RUN apt-get install -y dnsutils
RUN apt-get install iputils-ping
RUN apt-get install -y curl

COPY ./script.sh ./
# limpia /r del script
RUN sed -i 's/\r$//' script.sh

CMD udhcpc;tail -f /dev/null