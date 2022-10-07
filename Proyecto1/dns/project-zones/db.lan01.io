;
; BIND data file for local loopback interface
;
$TTL	604800
@	IN	SOA	lan01.io. root.lan01.io. (
		     2022100600		; Serial
			 604800		; Refresh
			  86400		; Retry
			2419200		; Expire
			 604800 )	; Negative Cache TTL
;
@	IN	NS	ns.lan01.io.
@	IN	A	127.0.0.1
@	IN	AAAA	::1
ns	IN	A	10.0.0.0
dhcp1	IN	A	10.0.0.4
router1	IN	A	10.0.0.10
nginx	IN	A	10.0.0.20
apache	IN	A	10.0.0.21
dns	IN	A	10.0.0.3
cache	IN	A	10.0.0.7
router2	IN	A	10.0.0.2
www	IN	A	10.0.0.20
web	IN	A	10.0.0.21
