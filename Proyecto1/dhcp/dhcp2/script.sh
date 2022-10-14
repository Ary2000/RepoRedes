#!/bin/bash
ip route del default 
ip route add default via 10.0.1.10
truncate -s0 /etc/resolv.conf
bash -c 'echo "domain lan02.io" >> /etc/resolv.conf' && bash -c 'echo "nameserver 10.0.0.3" >> /etc/resolv.conf'
tail -f /dev/null