#!/bin/bash
ip route del default 
ip route add default via 10.0.1.10

truncate -s0 /etc/resolv.conf
bash -c 'echo "domain lan02.io" >> /etc/resolv.conf' && bash -c 'echo "nameserver 10.0.0.3" >> /etc/resolv.conf'

# Tomado de https://kifarunix.com/install-and-setup-openvpn-server-on-ubuntu-22-04/
cp -r /usr/share/easy-rsa /etc/
cd /etc/easy-rsa/
./easyrsa init-pki

# Genera el certificado CA y Key
printf "zhong\nzhong\nvpn\n" | ./easyrsa build-ca

# Genera parametros diffie Hellman
./easyrsa gen-dh

# Genera OpenVPN Server certificado y llave
printf "zhong\n" | ./easyrsa build-server-full server nopass

# Genera llave HMAC
openvpn --genkey secret /etc/easy-rsa/pki/ta.key

# Genera certificado de revocacion
printf "zhong\n" | ./easyrsa gen-crl

# Copiar certificados a directorio de server
cp -rp /etc/easy-rsa/pki/ca.crt /etc/openvpn/
cp -rp /etc/easy-rsa/pki/dh.pem /etc/openvpn/
cp -rp /etc/easy-rsa/pki/ta.key /etc/openvpn/
cp -rp /etc/easy-rsa/pki/crl.pem /etc/openvpn/
cp -rp /etc/easy-rsa/pki/issued /etc/openvpn/
cp -rp /etc/easy-rsa/pki/private /etc/openvpn/

cp /server.conf /etc/openvpn/

# IP FORWARDING
sed -i 's/#net.ipv4.ip_forward=1/net.ipv4.ip_forward=1/' /etc/sysctl.conf

# Reboot
systemctl daemon-reload

iptables-legacy -t nat -A POSTROUTING -s 10.8.0.0/24 -j MASQUERADE

iptables-legacy -A FORWARD -j ACCEPT