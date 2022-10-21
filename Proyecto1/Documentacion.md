# Instituto Tecnológico de Costa Rica  
## Escuela de Computación  
## IC 7602 - Redes - GR 2  
## Proyecto 1
## Profesor Gerardo Nereo Campos Araya  
## Estudiantes

- Ary-El Durán Ballestero | 2018102445
- Isaac David Ortega Arguedas | 2018189196
- Mario Fernández Robert | 2018163975
- Zhong Jie Liu Guo | 2018319114

## Fecha de Entrega 21/10/2022
---

## Objetivos
El objetotivo de este proyecto es el de implementar redes locales virtuales (VLAN) mediante la configuracipon de servicios de red.Esta red local debe contar con routers, servidores DHCP, servidor de DNS y servidor VPN. Además, implementa reglas de enrutamiento, reglas de firewall, implementa y configura un proxy reverso e instala Web Servers con sitios básicos.
El proyecto debe automatizar toda la configuración e instalación mediante Docker compese y Shell scripts. Así como utilizar herramientas de diagnóstico de redes.
## Descripción
Con el fin de lograr el objetivo, se debe implementar dos pequeñas redes virtuales que exponen diferentes servicios, toda la configuración debe ser implementada mediante Docker y Docker Compose.
### Redes 
Se cuenta con dos redes, cauna tiene se respectivo nombre, número de red y máscara.
### Routers
Se encargan de darle internet a su respectiva LAN Virtual, se encargan del tráfico de salida permitido. Permite el acceso externo mediante puertos especificados en la asignación.
### DNS
Implementa tres zonas. Cada componente en las redes tendrá una entrada en su respectiva zona. Como forwarder, se utilizarán los 8.8.8.8 y 8.8.4.4. Esto cambio se realizó pues se presentaron ciertos problemas que se arreglaron al cambiar el 8.8.8.9 por el 8.8.4.4
### DHCPs
Ambos componentes prestan el servicio de configuración dinámica de host en sus respectivas redes, entre 
los parámetros a ofrecer se encuentra el IP, configuración de red, DNS y default gateway. 
### Clientes
Al iniciar un cliente en alguna de las redes, estos deberán poder configurar su red automáticamente,
obtener un nombre de dominio y tener acceso a la red, también deben poder validar las reglas definidas 
por todos los demás componentes.
### Web Servers
Se deberán implementar un Web Server en Apache, el mismo expone una simple página.
### Proxy Reverso
Implementará un ruteo por hostname, cuando alguien ingrese a www.google.com/web1
mostrará la página de Web Server1 y cuando lo haga a la página www.google.com/web2 mostrará la 
página de Web Serever2.
### VPN
Se deberá implementar con la tecnología OpenVPN, el mismo permitirá acceder a los recursos internos de ambas redes y permitirá realizar el enrutamiento de todo el tráfico de Internet.
### Web Cache
Actuará como un Web Proxy Cache transparente, este mantendrá un cache con políticas de expiración de 
todo el trafico HTTP y HTTPs, estará configurado automáticamente para todos los clientes de la red.
## Diagramas 
### Diagramas de arquitectura
La base de este programa se tomó de la especificación del proyecto. Es bastante similar en el sentido de los puertos y las conexiones.
![image](./arquitectura)

## Prerequisitos
Para este proyecto, se asume que tiene instalado los siguientes programas:

- Docker Desktop(ver [link](https://www.docker.com/) )
- (Opcional) Lens (ver [link](https://k8slens.dev/))
## Manual de usuario
En este proyecto realmente solo se necesita correr un comando que seria "docker-compose up --build", este se debe correr en el archivo en donde se encuentre el archivo "docker-compose.yaml", ahora el comando se encargara de construir, o descargar las imagenes que se necesesiten para correr el programa y crear contenedores con estos, al final de este comando, ya se pueden entrar a las terminales de cualquier contenedor para correr las pruebas que se quieran.
## Pruebas unitarias
### Creación de PODS

Los pods se crean de manera exitosa y en el orden especificado por el profesor.
![Crear de PODs](./assets/Prueba%20Unitaria%20Creacion%20de%20PODs.png)
### Clientes reciben IPs correctos
### Corridas del comando PING en ambos clientes
- Cliente 1
![Corridas PING Cliente 1](./PING-cliente1.png)
- Cliente 2
![Corridas PING Cliente 2](./PING-cliente2.png)
### Corrida de TRACEROUTE para asegurarse de que se esten tomando las rutas correctamente
- Cliente 1
![Corridas TRACEROUTE Cliente 1](./traceroute-cliente1.png)
- Cliente 2
![Corridas TRACEROUTE Cliente 2](./traceroute-cliente2.png)
### Corridas del comando NSLOOKUP en ambos clientes
- Cliente 1
![Corridas NSLOOKUP Cliente 1](./nslookup-cliente1.png)
- Cliente 2
![Corridas NSLOOKUP Cliente 2](./nslookup-cliente2.png)
### Salvado de los CURLs en el web cachce
### Pruebas realizadas con TELNET
## Recomendaciones

1. Al momento de implementar zonas, se debe de tener cuidado al momento de realizar la configuracion de estas. Ya que es sencillo cometer un error y ser incapaz de encontrar el origen de este.
2. Utilizar traceroute si se desea saber si un componente, del cual conocemos su IP esta conectado a la red.
3. 

## Conclusiones

1. Este proyecto es de gran utilidad para conecer en mayor profundidad como funcionan las redes locales.
2. El uso del cache puede llegar a ser vastante provechoso ya que estos pueden ayudar a disminur el consumo de ancho de banda.
3. El equilibrio de carga puede ser util si se desea evitar sobrecargar una pagina y/o servidor. No obstante Round Robin no es el mejor metodo para esto. 

## Referencias bibliográficas

https://ubuntu.com/server/docs/service-domain-name-service-dns