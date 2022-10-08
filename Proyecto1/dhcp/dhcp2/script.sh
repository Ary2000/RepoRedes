#!/bin/bash
ip route del default 
ip route add default via 10.0.1.10

tail -f /dev/null