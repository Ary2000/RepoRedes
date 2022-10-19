FROM ubuntu:latest

WORKDIR /router1

COPY ./script.sh ./

# // https://www.hostinger.com/tutorials/iptables-tutorial
RUN apt-get update && \
      apt-get -y install sudo
RUN apt-get -y install curl
RUN apt-get install iptables sudo -y

ENTRYPOINT [ "./script.sh" ]