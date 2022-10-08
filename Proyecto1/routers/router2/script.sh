#!/bin/bash
sudo ip route del default 
sudo ip route add default via 10.0.0.10

#LOCAL
sudo iptables-legacy -A INPUT -i lo -j ACCEPT

sudo iptables-legacy -A INPUT -p tcp --dport 80 -j ACCEPT
sudo iptables-legacy -A INPUT -p udp --dport 80 -j ACCEPT
sudo iptables-legacy -A INPUT -p icmp -j ACCEPT

#MASQUERADE https://bobcares.com/blog/iptables-nat-masquerade/ 
echo 1 > /proc/sys/net/ipv4/ip_forward
sudo iptables-legacy -t nat -A POSTROUTING -o eth0 -j MASQUERADE

#FORWARD
sudo iptables-legacy -A FORWARD -p tcp -s 10.0.0.0/24 --dport 80 -j ACCEPT
sudo iptables-legacy -A FORWARD -p udp -s 10.0.0.0/24 --dport 80 -j ACCEPT
sudo iptables-legacy -A FORWARD -p tcp -s 10.0.1.0/24 -d 10.0.0.0/24 --dport 80 -j ACCEPT
sudo iptables-legacy -A FORWARD -p tcp -s 10.0.1.0/24 -d 10.0.0.0/24 --dport 443 -j ACCEPT
sudo iptables-legacy -A FORWARD -p icmp -s 10.0.1.0/24 -d 10.0.0.0/24 -j ACCEPT

#SALIDA
sudo iptables-legacy -A OUTPUT -p tcp -j ACCEPT
sudo iptables-legacy -A OUTPUT -p udp -j ACCEPT

# CMD para mantenerlo levantado
tail -f /dev/null