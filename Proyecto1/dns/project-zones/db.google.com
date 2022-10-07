;
; BIND data file for local loopback interface
;
$TTL	604800
@	IN	SOA	google.com. root.google.com. (
			      4		; Serial
			 604800		; Refresh
			  86400		; Retry
			2419200		; Expire
			 604800 )	; Negative Cache TTL
;
@	IN	NS	ns.google.com.
@	IN	A	127.0.0.1
@	IN	AAAA	::1
ns	IN	A	10.0.0.20
www	IN	A	10.0.0.20
