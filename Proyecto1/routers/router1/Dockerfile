FROM ubuntu:latest

WORKDIR /router1

COPY ./script.sh ./

# limpia /r del script
RUN sed -i 's/\r$//' script.sh

# // https://www.hostinger.com/tutorials/iptables-tutorial
RUN apt-get update && \
      apt-get -y install sudo
RUN apt-get -y install curl
RUN apt-get install iptables sudo -y
RUN apt-get install iproute2 -y
RUN apt-get install net-tools -y
RUN apt-get install traceroute -y
RUN apt-get install -y iputils-ping

ENTRYPOINT [ "sh","script.sh" ]

#CMD [ "tail", "-f", "/dev/null" ]