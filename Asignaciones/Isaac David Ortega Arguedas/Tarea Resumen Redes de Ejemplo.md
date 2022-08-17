---
# Tecnológico de Costa Rica
## Ingenieria en Computación
### IC-7620 - Redes
### Isaac David Ortega Arguedas
### Carnet: 2018189196
### II Semestre 2022
---

# Redes de Ejemplo
Este capítulo cuenta con algunos ejemplos con el objetivo de dar una idea de la variedad que se puede tener en el área de la conectividad de redes.
## Internet
Es más bien un conjunto de redes diferentes que usan protocolos comunes y ofrecen servicios en común. No es común pues no se planeó y nadie lo controla. Para entenderlo mejor, se contará su inicio y el cómo y por qué se desarrolló.
- ARPANET
Empieza a finales de la década de 1950. Durante el auge de la Guerra Fría, el DoD quería una red de control y comando que pudiera sobrevivir una guerra nuclear. El motivo de esto es que se consideraban vulnerables as comunicaciones utilizadas en ese momento. 
En 1957, se funda el ARPA (Agencia de Proyectos de investigación Avanzada), cuyo director, en 1967, volvió su interés hacia las redes. Se puso en contactos con expertos para decidir qué hacer. Wesley Clark, sugirió la construcción de una subred de conmutación de paquetes, dando a cada host su propio enrutador. Tras ver que en Inglaterra se tenía algo similar funcionando, el director estaba determinado a construirlo. 
Cada nodo de la red iba a constar de un IMP y un host, en el mismo cuarto, conectados por un cable corto. Un host tendría la capacidad de enviar mensajes a su IMP, el cual los fragmentaría en paquetes y los reenviaría de manera independiente hacia el destino. Tras funcionar hizo una convocatoria para construir la subred. BBN fue la empresa escogida. También se debían encargar del software. 
Conforme crecía el escalamiento, encontrar hosts llegó a ser muy costoso, por lo que se creó el DNS (Sistema de Nombres de Dominio).
- NSFNET
NFS tras ver el impacto de la ARPANET, y ver que para utilizarla la universidad debía tener un contrato de investigación con el DoD, decidieron como respuesta diseñar el sucesor de la ARPANET el cual pudiera estar abierto a todos los grupos de investigación de las universidades. Fue un éxito instantáneo y pronto se saturo. Motivo por el cual se planeó un sucesor.
Al continuar creciendo se dieron cuenta de que el gobierno no podría financiar por siempre el uso de redes, a su vez empresas comerciales querían unirse, pero los estatutos de la NSF les prohibía utilizar las redes por las que la FNS había pagado. Debido a esto incitaron a MERIT, MCT e IBM a que formaran una corporación no lucrativa como el primer paso hacia la comercialización.

Tradicionalmente (1970 a 1990) Internet y sus predecesores tenían cuatro aplicaciones principales: correo electrónico, noticias, inicio remoto de sesión y transferencia de archivos.
## Redes orientadas a la conexión: X.25, Frame Relay y ATM
Proviene del mundo de las compañías telefónicas. Consiste en trazar una ruta por la cual van a pasar todos los paquetes y si algo falla, se termina la conexión. A pesar de eso, ofrece, calidad en el servicio facturación. Al establecer una conexión de antemano, la subred puede reservar recursos en los enrutadores. Cuando se establece una conexión, ésta da un buen servicio.
Otra razón por el que las compañías telefónicas prefieren este servicio es que están acostumbrados a cobrar por el tiempo de conexión.
- X.25 y Frame Relay
X.25 fe la primera red de datos pública. Se desplego en la década de 1970, cuando el servicio telefónico era un monopolio en todas partes y la compañía telefónica de cada país espera que hubiera una red de daos por país. Para utilizar X.25, una computadora establecía primero una conexión con la computadora remota, es decir, hacía una llamada telefónica. Funcionaron por casi diez años con resultados mixtos. 
En la década de 1980, las redes X.25 fueron reemplazadas ampliamente por un nuevo tipo de red llamada Frame Relay. Orientada a la conexión sin controles de error ni de flujo. Los paquetes se entregaban en orden.
- Modo de Transferencia Asincrónica (ATM)
Se diseñó a principios de la década de 1990 y se lanzó en medio de una gran exageración. Supuestamente iba a ser un sistema capas integrado que pudiera proporcionar todos los servicios para todas las necesidades.

## Ethernet
Internet y ATM se diseñaron para conectividad de área amplia. Sin embargo, muchas empresas, universidades y otras organizaciones tienen un gran número de computadoras que requieren interconexión. Esta necesidad dio origen a la red de área local. En esta sección diremos algo sobre la LAN más popular: Ethernet.
La historia empieza en Hawaii a principios de la década de 1970. En este tiempo no contaba con un sistema telefónico funcional. Norman Abramson y sus colegas de la Universidad de Hawaii, quienes estuvieron tratando de conectar usuarios de las islas remotas a la computadora principal de Honolulu. Conectar sus propios cables bajo el Océano Pacífico parecía imposible, de modo que buscaron una solución diferente. 
La primera que encontraron fueron los radios de onda corta, trabajaba muy bien en condiciones de bajo tráfico, pero se caía cuando el flujo de tráfico ascendente era pesado. Después, Bob Matcalfe junto con su colega David Boggs, diseñó e implementó la primera red de área local. Llamaron Ethernet al sistema, por lo de luminiferous ether, a través del cual se pensó alguna vez que se propagaba la radiación electromagnética. Aquí el medio de transmisión no era el vacío, sino un cable coaxial grueso (el éter) de más de 2.5 km de largo (con repetidoras cada 500 metros). El sistema podía contener hasta 256 máquinas por medio de transceptores acoplados al cable.
## LANs inalámbricas: 802.11
Casi al mismo tiempo que aparecieron las computadoras portátiles, muchas personas tuvieron el sueño de andar por la oficina y poder conectar a Internet su computadora. En consecuencia, varios grupos empezaron a trabajar para cumplir con esta meta. E l método más práctico es equipar las computadoras de la oficina y las portátiles con transmisores y receptores de radio de onda corta que les permitan comunicarse. Este trabajo condujo rápidamente a que varias empresas empezaran a comercializar las LANs inalámbricas.
El problema es que no había compatibilidad entre ninguna de ellas. Esta proliferación de estándares implicaba que una computadora equipada con un radio de marca X no funcionara en un cuarto equipado con una estación de base marca Y. Finalmente, la industria decidió que un estándar de LAN inalámbrica sería una buena idea, por lo que al comité del IEEE que estandarizó las LANs alámbricas se le encargó la tarea de diseñar un estándar para LANs inalámbricas. El estándar resultante se llamó 802.11. En la jerga común se le conoce como WiFi.

