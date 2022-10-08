FROM ubuntu

RUN apt-get update
RUN apt-get -y install systemctl
RUN apt-get -y install isc-dhcp-server
RUN apt-get -y install iproute2
RUN apt-get install net-tools -y
RUN apt-get install traceroute -y

COPY ./script.sh ./

RUN > /etc/default/isc-dhcp-server
# https://askubuntu.com/questions/696159/isc-dhcp-server-start-error-dhcpd-cant-create-pid-file-run-dhcp-server-dhc
RUN echo 'DHCPD_PID=/var/run/dhcp-server/dhcpd.pid\nINTERFACESv4="eth0"\nINTERFACESv6=""' >> /etc/default/isc-dhcp-server
#RUN IP=$(curl ifconfig.me)

ARG IP=10.0.1.0
ARG IP_MIN=10.0.1.200
ARG IP_MAX=10.0.1.250
ARG ROUTER=10.0.1.10
ARG BROADCAST=10.0.1.255

#RUN mkdir /etc/dhcp
#RUN touch dhcpd.conf
RUN > /etc/dhcp/dhcpd.conf
RUN echo 'subnet '${IP} 'netmask 255.255.255.0 {\n  range '${IP_MIN} ${IP_MAX}';\n  option domain-name "example.org";\n  option subnet-mask 255.255.255.0;\n  option routers '${ROUTER}';\n  option broadcast-address '${BROADCAST}';\n  default-lease-time 600;\n  max-lease-time 7200;\n}' >> /etc/dhcp/dhcpd.conf

RUN > /lib/systemd/system/isc-dhcp-server.service
RUN echo "[Unit]\nDescription=ISC DHCP IPv4 server\nDocumentation=man:dhcpd(8)\nWants=network-online.target\nAfter=network-online.target\nAfter=time-sync.target\nConditionPathExists=/etc/default/isc-dhcp-server\nConditionPathExists=|/etc/ltsp/dhcpd.conf\nConditionPathExists=|/etc/dhcp/dhcpd.conf\n\n[Service]\nEnvironmentFile=/etc/default/isc-dhcp-server\nRuntimeDirectory=dhcp-server\n# The leases files need to be root:dhcpd even when dropping privileges\nExecStart=/bin/sh -ec '\\ \n    CONFIG_FILE=/etc/dhcp/dhcpd.conf; \\ \n    if [ -f /etc/ltsp/dhcpd.conf ]; then CONFIG_FILE=/etc/ltsp/dhcpd.conf; fi; \\ \n    [ -e /var/lib/dhcp/dhcpd.leases ] || touch /var/lib/dhcp/dhcpd.leases; \\ \n    chown root:dhcpd /var/lib/dhcp /var/lib/dhcp/dhcpd.leases; \\ \n    chmod 775 /var/lib/dhcp ; chmod 664 /var/lib/dhcp/dhcpd.leases; \\ \n    exec dhcpd -user dhcpd -group dhcpd -f -4 -pf $DHCPD_PID -cf $CONFIG_FILE $INTERFACESv4'\n\n[Install]\nWantedBy=multi-user.target" >> /lib/systemd/system/isc-dhcp-server.service

RUN systemctl daemon-reload
#RUN systemctl restart isc-dhcp-server

CMD systemctl restart isc-dhcp-server; sh script.sh; tail -f /dev/null
#RUN systemctl restart isc-dhcp-server
#CMD ["systemctl", "restart isc-dhcp-server"]
#RUN sudo systemctl restart isc-dhcp-server

#Comando para revisar estado
#RUN sudo systemctl status isc-dhcp-server