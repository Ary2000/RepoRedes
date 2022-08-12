# Resumen 1 - 1.5. Redes de Ejemplo
## IC-7602 - Redes
## Zhong Jie Liu Guo
## Carnet: 2018319114
## Profesor Gerardo Nereo Campos Araya
## Escuela de Ingeniería en Computación - ITCR
## Fecha: 9 de agosto de 2022
## ------------------------------------------------

 
### *Internet*
Es un conjunto de redes diferentes. La primera iteración fue ARPANET
> ARPANET
- Agencia de Proyectos de Investifación Avanzada (ARPA)
- Las primeras ideas fueron de armar una subred de conmutación de paquetes.
- La subred estaría compuesta por IMPs (Procesadores de Mensajes de Interfaz), unas minicomputadoras interconectadas por líneas de transmisión de 56 kbps. Cada computadora estaría conectada a otros dos para garantizar confiabilidad
- Software y hardware encargado por BBN 
			- Honeywell DDP-316 con palabras de 16 bits y 12 KB de memoria central.
			- Software se dividió en dos:
				1. Subred: el extremo host de conexión jost a IMP, el protocolo host a host y el software de la aplicación.
				2. Host: Empezaron a aparecer desde las universidades y fueron creciendo.
- Se inventaron los protocolos TCP/IP para poder adecuar la comunicación entre redes diferentes.
- Surgieron los sockets para facilitar la conectividad de aplicaciones.
- Se creó el DNS (Sistema de Nombres de Dominio) para facilitar la búsqueda de hosts.

> Uso de Internet
- Correo electrónico
- Noticias
- Inicio remoto de sesión
- Transferencia de archivos
- WWW (World Wide Web)

> Arquitectura
- El modem transforma las señales digitales de un cliente a análogas para pasarlos al sistema telefónico.
- Las señales se transfieren al POP (Punto de Presencia) del ISP donde se mueven hacia la red regional del ISP de forma digital. Esta red está compuesta de enrutadores interconectados en una ciudad.

### *Redes orientadas a la conexión*
El campo orientado a la conexión trata de entablar una conexión con el destinatario y se acaba la conexión cuando se desee asegurando la calidad.
> X.25
- Una computadora hacía una conexión por medio de una llamada telefónica con otra computadora remota. Esta daba un número para utilizarlo en la transferencia de datos.
> Frame Relay
- Estos reemplazaron al X.25 y era red sin controles de error ni de flujo, parecida al LAN de área amplia.
- Los paquetes de datos se entregaban en orden.
> ATM (Modo de Transferencia Asíncrona)
- Primero se envía un paquete para establecer la conexión. En ese paso, los conmutadores dejan espacio en sus tablas internas para la futura conexión reservando recursos. 
- Cuando se establece la conexión, cada lado puede transmitir los datos por medio de celdas, paquetes pequeños de 53 bytes. Es tiene un header con los metadatos de los hosts emisor y receptor y los intermediarios. La conmutación se hace por medio del hardware.
- Una ventaja es que el hardware puede enviar una celda a diferentes líneas de salida y las celdas pequeñas no duran mucho en la línea.
> El modelo ATM
    - AAL (Capa de Adaptación ATM): recibe información para luego segmentar los paquetes en celdas y reensamblarlas en el otro extremo. Tiene las subcapas CS (de convergencia) y SAR (de segmentación y reensamble).
	- ATM: esta capa se encarga del control del flujo de las celdas, tanto el manejo de los headers o encabezados de las mismas, el establecimiento de la ruta a tomar y la multiplexión o desmultiplexión de las celdas.
	- La capa física posee las siguientes subcapas: 
	    - TC (de convergencia de transmisión): esta subcapa de encarga del desacoplamiento de proporción de celdas, la comprobación de los headers, la generación de las celdas, su enpaquetamiento/desempaque y la generación de tramas. 
		- PMD (dependiente del medio físico): se encarga de la temporización de bits y del acceso a la red física.

### *Ethernet*
- Red de área local.
- La transmisión se realizaba por medio de un cable coaxial grueso de más de 2.5 km de largo, el cual podía contener hasta 256 máquinas conectadas al cableado por medio de transceptores.
- Multidrop: un cable con múltiples máquinas en paralelo.

### *IEEE 802.11 (LANs inalámbricas)*
- Refiere al WiFi que trabajaba en dos modos:
	1. En presencia de una estación base: toda comunicación se hace en el punto de acceso (estación base).
	2. En ausencia de una estación base: Las computadoras podrían enviarse mensajes entre sí (red ah hoc).
- Este tuvo problemas para estandarizar su uso ante el Ethernet por varios problemas.
	1. Las computadoras en Ethernet siempre escuchaban el medio antes de transmitir, algo que el LAN no funcionaba de la misma forma.
	2. Puede darse un desvanecimiento por múltiples trayectorias ya que las señales de radio pueden ser reflejadas por los objetos sólidos, por lo que habría repetición de recepción de esos datos.
	3. El software solamente consideraba un grupo específico de dispositivos para su uso lo cual no sería útil al cambiar a un diferente entorno.
	4. En el caso donde una portátil esté lejos de la estación base en uso y cerca de una diferente, este requiere de un manejo.

