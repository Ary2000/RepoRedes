#!/bin/bash
ip route del default 
ip route add default via 10.0.0.10
#truncate -s0 /etc/resolv.conf && bash -c 'echo "domain lan01.io" >> /etc/resolv.conf' && bash -c 'echo "nameserver 10.0.0.3" >> /etc/resolv.conf'

#systemctl restart bind9
#tail -f /dev/null
/usr/sbin/named -u bind -f