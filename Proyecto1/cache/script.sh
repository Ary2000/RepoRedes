sudo truncate -s0 /etc/resolv.conf
sudo bash -c 'echo "domain lan01.io" >> /etc/resolv.conf' && bash -c 'echo "nameserver 10.0.0.3" >> /etc/resolv.conf'

#sudo iptables-legacy -A PREROUTING -s 10.0.0.0/24 -i eth0 -p tcp --dport 80 -j REDIRECT --to-port 3128

sudo iptables-legacy -t nat -A PREROUTING -s 10.0.0.0/24 -i eth0 -p tcp --dport 80 -j REDIRECT --to-port 3128

# CMD para mantenerlo levantado
tail -f /dev/null