#!/bin/bash
nslookup dns-interceptor >> temp.conf
sed -i 's/Address:/nameserver/g' temp.conf
truncate -s0 /etc/resolv.conf
tail -2 temp.conf >> temp1.conf
head -1 temp1.conf >> /etc/resolv.conf