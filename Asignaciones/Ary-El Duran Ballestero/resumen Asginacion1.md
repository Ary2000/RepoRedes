**Instituto Tecnológico de Costa Rica  
Escuela de Computación  
Redes GR 2  
Resumen del libro Computer Networks Sección 1.5  
Fecha de entrega: 9/8/2022**

# La internet

La internet se presenta no como una simple red, pero más bien como una colección de redes donde todas están usando protocolos y servicios similares.

## La APRANET

Durante la guerra fría se necesitaba algún medio de comunicación que no fuera tan vulnerable como eran las redes telefónicas públicas, la razón de esto es la cantidad de teléfonos conectados a las oficinas switches y estas conectadas a las oficinas de peaje, si alguna de estas oficinas, de switches o de peaje cayeran, puede cerrar la comunicación a varios teléfonos, cuál sería un gran desastre durante emergencias, aquí se presenta Paul Baran que presento un modelo tolerante a fallas donde las oficinas se encontraban con señales análogas, sino con comunicación digital de conmutación de paquetes, a los del pentágono les pareció la idea y puso a AT&T a construir un prototipo, pero por orgullo de ellos dijeron que era imposible de crear y botaron la idea.
Después el director del ARPA, Larry Roberts encontró un gran interés sobre las redes y después de consultar a varios expertos y descubrir una implementación en el Laboratorio Nacional de Física en Inglaterra, que citaba el trabajo de Baran, se fue a construir la ARPANET. Esta consistiría en microcomputadoras que se encontrarían conectadas a múltiples de la misma para asegurar de que si se cayera alguna de estes, no hubiera total caída de la comunicación.

## NSFNET

Viendo el éxito que la ARPANET estaba teniendo, la NFS busco crear un sucesor a la este porque había varias universidades que no podían aprovechar el uso de la APRANET porque se necesitaba un contrato, este iba a estar disponible a todos los grupos de investigación universitarios y para comenzar hicieron seis centros con una super computadora y una microcomputadora llamada fuzzball, mientras el hardware era similar el software era diferente. Este plan fue increíblemente exitoso, requiriendo de múltiples evoluciones de la red y cambios para el avance comercial.

## El uso de internet

El crecimiento de la internet fue increíblemente enorme, en especial cuando la NSFNET y la APRANET se interconectaron, esto fue gracias a el modelo de referencia y los protocolos TCP/IP. La definición usada en el libro de un dispositivo que se encuentre en la internet es uno que siga los protocolos pila del TCP/IP, tenga su propia dirección IP y que pueda enviar paquetes IP a otras máquinas que estén en la internet.
En 1990 la internet era usada principalmente por investigadores académicos, industriales y del gobierno pero con la aparición del www que realizaba ciertas características más fáciles de usar, esto con el navegador Mosaic que permitía la navegación de páginas por medio de clickear links y los ISP, causo mayor uso de este por todas las personas.

# Redes orientadas a la conexión

Esta es el tipo de conexión que se usa con los sistemas telefónicos, se debe formar la conexión antes de enviar los datos. Este tipo de conexión sufre problemas si se caen las redes telefónicas, ya que puede ser que corte la conexión por completo.
Los beneficios de este tipo de conexiones es que al armar la conexión de antemano se pueden reservar recursos para mantener la comunicación con alta calidad, también ya estaban acostumbrados de manipular la facturación con este modelo.

## X.25

Este tipo de conexión servía como una llamada telefónica, buscando una conexión donde de ahí pasaba los paquetes de datos usando un número de conexión, estos también tenían un header que contenía varias cosas como número de secuencia de paquete o número de confirmación.

## Frame Relay

Este reemplazo al X.25, donde quito los controles de flujo y de errores y permitió la interconexión de LANs en múltiples oficinas.
Modo de Transferencia Asíncrona
Este buscaba poder manejar varios tipos conectividad y telecomunicaciones, querían desarrollar un sistema que manejara todo esto, pero esto no resulto exitoso, termino siendo usado más en telefónicas.

## Circuitos virtuales de ATM

Un circuito virtual es una conexión y los recursos que se reservan, estas pueden ser permanentes.
Van a enviar paquetes pequeños llamados celdas, estas van a ser de tamaño fijo. Va a tener un encabezado que va a tener el identificador de la conexión. Las ventajas del ATM es que se puede preparar el hardware para correr el tamaño de una celda y que no bloquean las líneas por mucho tiempo. El orden de envió de las celdas siempre se van a ser respetados.

## El modelo de referencia ATM

Este modelo es dependiente del modelo de transporte. Esta formado por múltiples tipos de capas
Capa ATM: Encargada de las caldas y su transporte
Capa de Adaptación ATM: Interfaz que se encarga de segmentar paquetes que sean más grandes que una celda.
Plano de usuario: Se encarga del transporte datos, flujo, corrección de errores, entre otros.
Plano de control: Administrar conexiones.
Subcapa Dependiente del Medio Físico: Se encarga de interactuar con el cable y recibir la información que recibe de ella.

## Ethernet

Esta es una conexión diseñado e implementado por Bob Metcalfe y David Boggs en hawaii, lo que busca hacer es realizar una red de área local entre varias computadoras.
La comunicación se realizaba a través de un cable, el éter, que podía manejar múltiples computadoras al mismo tiempo, cada vez que se quería realizar una comunicación se tenia que revisar si el cable no se encontraba siendo usado, en el caso que si se esperaba hasta que se terminada la comunicación. En caso de que dos computadoras estuvieran en la cola, al enviar información detecta si hay interferencia, si la detecta, le da un tiempo aleatorio antes de volver a intentar comunicación.

## LANs inalámbricas: 802.11

El 802.11 es el estándar que se encargo hacer la IEEE para la cantidad de computadoras portátiles con maneras diferentes de conectarse a la internet. Este estándar propuso dos modos, uno donde hay estación base (Donde toda la comunicación pasa por el punto de acceso) y otro donde no hay (Comunicación directa).
El estándar también tenía que buscar varios problemas que pasaban por el uso del LAN inalámbrico, no había ethernet para revisar si ya hubiera una comunicación pasando, el desvanecimiento por múltiples trayectorias, la capacidad de mover la computadora a varios lugares y el de mover la computadora fuera del rango de comunicación.
Aunque los primeros estándares tenían varios problemas de comunicación, estos han avanzado para poder terminar siendo más veloces.
