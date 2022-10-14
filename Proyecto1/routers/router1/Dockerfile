FROM ubuntu:latest

WORKDIR /router1

COPY ./script.sh ./

# limpia /r del script
RUN sed -i 's/\r$//' script.sh

# // https://www.hostinger.com/tutorials/iptables-tutorial
RUN apt-get update && \
      apt-get -y install sudo && \ 
      apt-get -y upgrade
RUN apt-get -y install curl
RUN apt-get install iptables sudo -y
RUN apt-get install iproute2 -y
RUN apt-get install net-tools -y
RUN apt-get install traceroute -y
RUN apt-get install -y iputils-ping
RUN apt-get install dnsutils -y

ENTRYPOINT [ "sh","script.sh" ]

#CMD [ "tail", "-f", "/dev/null" ]