#!/bin/bash
sudo ip route del default 
sudo ip route add default via 10.0.0.10
truncate -s0 /etc/resolv.conf
bash -c 'echo "domain lan02.io" >> /etc/resolv.conf' && bash -c 'echo "nameserver 10.0.0.3" >> /etc/resolv.conf'

#LOCAL
sudo iptables-legacy -A INPUT -i lo -j ACCEPT

sudo iptables-legacy -A INPUT -p tcp --dport 80 -j ACCEPT
sudo iptables-legacy -A INPUT -p udp --dport 80 -j ACCEPT
sudo iptables-legacy -A INPUT -p icmp -j ACCEPT

iptables-legacy -A INPUT -i eth0 -m state --state NEW -p tcp --dport 8443 -j ACCEPT
iptables-legacy -A INPUT -i tun+ -j ACCEPT


#MASQUERADE https://bobcares.com/blog/iptables-nat-masquerade/ 
echo 1 > /proc/sys/net/ipv4/ip_forward
sudo iptables-legacy -t nat -A POSTROUTING -o eth0 -j MASQUERADE

#FORWARD
iptables-legacy -A FORWARD -i tun+ -j ACCEPT
iptables-legacy -A FORWARD -i tun+ -o eth0 -m state --state RELATED,ESTABLISHED -j ACCEPT
iptables-legacy -A FORWARD -i eth0 -o tun+ -m state --state RELATED,ESTABLISHED -j ACCEPT
sudo iptables-legacy -A FORWARD -p tcp -s 10.0.0.0/24 --dport 80 -j ACCEPT
sudo iptables-legacy -A FORWARD -p udp -s 10.0.0.0/24 --dport 80 -j ACCEPT
sudo iptables-legacy -A FORWARD -p tcp -s 10.0.1.0/24 -d 10.0.0.0/24 --dport 80 -j ACCEPT
sudo iptables-legacy -A FORWARD -p tcp -s 10.0.1.0/24 -d 10.0.0.0/24 --dport 443 -j ACCEPT
sudo iptables-legacy -A FORWARD -p icmp -s 10.0.1.0/24 -d 10.0.0.0/24 -j ACCEPT

#DNS
truncate -s0 /etc/resolv.conf
echo "nameserver 10.0.0.3" >> /etc/resolv.conf

#SALIDA
iptables-legacy -A OUTPUT -o tun+ -j ACCEPT
sudo iptables-legacy -A OUTPUT -p tcp -j ACCEPT
sudo iptables-legacy -A OUTPUT -p udp -j ACCEPT

# CMD para mantenerlo levantado
tail -f /dev/null