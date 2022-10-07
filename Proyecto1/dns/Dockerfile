FROM ubuntu:latest

RUN apt-get update
RUN apt-get install bind9 -y
RUN apt-get install dnsutils -y
COPY ./project-zones/. /etc/bind/
CMD [ "tail", "-f", "/dev/null" ]


