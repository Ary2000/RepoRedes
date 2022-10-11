#!/bin/bash
ip route del default 
ip route add default via 10.0.0.10

#/usr/sbin/named -u bind -f
tail -f /dev/null