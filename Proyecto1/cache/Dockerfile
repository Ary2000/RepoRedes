FROM ubuntu

RUN apt-get update
RUN apt-get -y install systemctl
RUN apt-get -y install iproute2
RUN apt-get -y install squid
RUN apt-get -y install ufw
RUN apt-get -y install iptables
RUN apt-get install nano
RUN apt-get install -y sudo

COPY ./script.sh ./

COPY ./squid.conf ./etc/squid/
RUN echo "5885" >> /run/squid.pid
#RUN iptables-legacy -A PREROUTING -s 10.0.0.0/24 -i eth0 -p tcp --dport 80 -j REDIRECT --to-port 3128
#   iptables-legacy -A INPUT -p tcp --dport 80 -j ACCEPT
#RUN iptables-legacy -A PREROUTING -s 10.0.0.0/24 -i eth0 -p tcp --dport 443 -j REDIRECT --to-port 3128
#RUN ufw allow 3128/tcp 

CMD systemctl restart squid;sh script.sh;tail -f /dev/null