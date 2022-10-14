;
; BIND data file for local loopback interface
;
$TTL	604800
@	IN	SOA	lan02.io. root.lan02.io. (
		      202210061		; Serial
			 604800		; Refresh
			  86400		; Retry
			2419200		; Expire
			 604800 )	; Negative Cache TTL
;
@	IN	NS	ns.lan02.io.
@	IN	A	127.0.0.1
@	IN	AAAA	::1
ns	IN	A	10.0.1.0
router2	IN	A	10.0.1.10
dhcp2	IN	A	10.0.1.5
vpn	IN	A	10.0.1.15
apache	IN	A	10.0.1.21
www	IN	A	10.0.1.20
web	IN	A	10.0.1.21
