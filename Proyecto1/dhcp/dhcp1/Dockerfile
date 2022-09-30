FROM ubuntu

RUN apt-get update
RUN apt-get -y install systemctl
RUN apt-get -y install isc-dhcp-server

RUN > /etc/default/isc-dhcp-server
RUN echo 'INTERFACESv4="eth0"\nINTERFACESv6=""' >> /etc/default/isc-dhcp-server
#RUN IP=$(curl ifconfig.me)

ARG IP=10.0.0.4
ARG IP_MIN=10.0.0.100
ARG IP_MAX=10.0.0.150
ARG ROUTER=10.0.0.1
ARG DNS=10.0.0.3
ARG BROADCAST=10.0.0.255

#RUN mkdir /etc/dhcp
#RUN touch dhcpd.conf
RUN > /etc/dhcp/dhcpd.conf
RUN echo 'subnet '${IP} 'netmask 255.255.255.0 {\n  range '${IP_MIN} ${IP_MAX}';\n  option domain-name-server '${DNS}';\n  option domain-name "example.org";\n  option subnet-mask 255.255.255.0;\n  option routers '${ROUTER}';\n  option broadcast-address '${BROADCAST}';\n  default-lease-time 600;\n  max-lease-time 7200;\n}' >> /etc/dhcp/dhcpd.conf

CMD ["tail", "-f", "/dev/null"]
#RUN systemctl restart isc-dhcp-server
#CMD ["systemctl", "restart isc-dhcp-server"]
#RUN sudo systemctl restart isc-dhcp-server

#Comando para revisar estado
#RUN sudo systemctl status isc-dhcp-server