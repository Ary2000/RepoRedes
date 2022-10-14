#!/bin/bash
ip route add 10.0.1.0/24 via 10.0.0.2
truncate -s0 /etc/resolv.conf
bash -c 'echo "domain lan01.io" >> /etc/resolv.conf' && bash -c 'echo "nameserver 10.0.0.3" >> /etc/resolv.conf'

#LOCAL
sudo iptables-legacy -A INPUT -i lo -j ACCEPT
#ENTRADA
sudo iptables-legacy -A INPUT -p tcp --sport 80 -j ACCEPT
sudo iptables-legacy -A INPUT -p tcp --sport 443 -j ACCEPT
sudo iptables-legacy -A INPUT -p tcp --sport 3128 -j ACCEPT
sudo iptables-legacy -A INPUT -p tcp --sport 8443 -j ACCEPT
sudo iptables-legacy -A INPUT -p udp --sport 53 -j ACCEPT
sudo iptables-legacy -A INPUT -p tcp --sport 53 -j ACCEPT

sudo iptables-legacy -A INPUT -p tcp --dport 80 -j ACCEPT
sudo iptables-legacy -A INPUT -p tcp --dport 443 -j ACCEPT
sudo iptables-legacy -A INPUT -p tcp --dport 3128 -j ACCEPT
sudo iptables-legacy -A INPUT -p tcp --dport 8443 -j ACCEPT
sudo iptables-legacy -A INPUT -p udp --dport 53 -j ACCEPT
sudo iptables-legacy -A INPUT -p tcp --dport 53 -j ACCEPT

sudo iptables-legacy -A INPUT -p icmp -j ACCEPT
#NEGAR TODO LO DEMAS
sudo iptables-legacy -A INPUT -j DROP

#MASQUERADE https://bobcares.com/blog/iptables-nat-masquerade/
echo 1 > /proc/sys/net/ipv4/ip_forward
sudo iptables-legacy -t nat -A POSTROUTING -o eth0 -j MASQUERADE

sudo iptables-legacy -A FORWARD -i eth1 -o eth0 -j ACCEPT

#PROXY REVERSO
sudo iptables-legacy -A FORWARD -p tcp -s 10.0.0.20 --dport 80 -j ACCEPT
sudo iptables-legacy -A FORWARD -p tcp -s 10.0.0.20 --dport 443 -j ACCEPT

#WEB CACHE
sudo iptables-legacy -A FORWARD -p tcp -s 10.0.0.7 --dport 3128 -j ACCEPT

#VPN
sudo iptables-legacy -A FORWARD -p tcp -d 10.0.1.10 --dport 8443 -j ACCEPT 

#DNS
sudo iptables-legacy -A FORWARD -p udp -s 10.0.0.3 --dport 53 -j ACCEPT
sudo iptables-legacy -A FORWARD -p tcp -s 10.0.0.3 --dport 53 -j ACCEPT

sudo iptables-legacy -A FORWARD -p tcp -s 10.0.1.0/24 -j ACCEPT
sudo iptables-legacy -A FORWARD -p udp -s 10.0.1.0/24 -j ACCEPT

#SALIDA
sudo iptables-legacy -A OUTPUT -o lo -j ACCEPT
sudo iptables-legacy -A OUTPUT -p udp --sport 53 -j ACCEPT
sudo iptables-legacy -A OUTPUT -p tcp --sport 53 -j ACCEPT
sudo iptables-legacy -A OUTPUT -p tcp --sport 80 -j ACCEPT
sudo iptables-legacy -A OUTPUT -p tcp --sport 443 -j ACCEPT
sudo iptables-legacy -A OUTPUT -p tcp --sport 3128 -j ACCEPT
sudo iptables-legacy -A OUTPUT -p tcp --sport 8443 -j ACCEPT

# CMD para mantenerlo levantado
tail -f /dev/null