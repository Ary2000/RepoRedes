#!/bin/bash
ip route del default 
ip route add default via 10.0.1.10

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
cp -rp /etc/easy-rsa/pki/ca.crt /etc/openvpn/server/
cp -rp /etc/easy-rsa/pki/dh.pem /etc/openvpn/server/
cp -rp /etc/easy-rsa/pki/ta.key /etc/openvpn/server/
cp -rp /etc/easy-rsa/pki/crl.pem /etc/openvpn/server/
cp -rp /etc/easy-rsa/pki/issued /etc/openvpn/server/
cp -rp /etc/easy-rsa/pki/private /etc/openvpn/server/

cp /server.conf /etc/openvpn/server/

# Crear certificados y llaves de clientes
printf "zhong\n" | ./easyrsa build-client-full zhong nopass
printf "zhong\n" | ./easyrsa build-client-full mario nopass

mkdir /etc/openvpn/client/zhong
mkdir /etc/openvpn/client/mario

cp -rp /etc/easy-rsa/pki/ca.crt /etc/openvpn/client/zhong
cp -rp /etc/easy-rsa/pki/issued/zhong.crt /etc/openvpn/client/zhong
cp -rp /etc/easy-rsa/pki/private/zhong.key /etc/openvpn/client/zhong

cp -rp /etc/easy-rsa/pki/ca.crt /etc/openvpn/client/mario
cp -rp /etc/easy-rsa/pki/issued/mario.crt /etc/openvpn/client/mario
cp -rp /etc/easy-rsa/pki/private/mario.key /etc/openvpn/client/mario

# IP FORWARDING
sed -i 's/#net.ipv4.ip_forward=1/net.ipv4.ip_forward=1/' /etc/sysctl.conf

# Reboot
sysctl --system

iptables-legacy -A INPUT -i eth0 -m state --state NEW -p tcp --dport 8443 -j ACCEPT
iptables-legacy -A INPUT -i tun+ -j ACCEPT
iptables-legacy -A FORWARD -i tun+ -j ACCEPT
iptables-legacy -A FORWARD -i tun+ -o eth0 -m state --state RELATED,ESTABLISHED -j ACCEPT
iptables-legacy -A FORWARD -i eth0 -o tun+ -m state --state RELATED,ESTABLISHED -j ACCEPT
iptables-legacy -t nat -A POSTROUTING -s 10.0.1.0/24 -o eth0 -j MASQUERADE
iptables-legacy -A OUTPUT -o tun+ -j ACCEPT

tail -f /dev/null