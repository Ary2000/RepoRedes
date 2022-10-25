**Instituto Tecnológico de Costa Rica  
Escuela de Computación  
Redes GR 2  
Resumen 4 y 5  
Profesor Gerardo Nereo Campos Araya  
Estudiante Ary-El Durán Balestero  
Fecha de entrega 25/10/2022**

# 3.5 Verificación de los protocols

## 3.5.1 Modelos de Máquinas de Estado Finito

Como dice el nombre del modelo, este esta basado en las máquines de estado finito, esta va a estar conformado por varios estados y transiciones. En este caso los estados pueden ser principales y de transiciones. En el caso de las transiciones, estas pueden pasar cuando llega una trama, se envia una trama, ocurre una interrupción entre otras cosas.  
Uno de los estados que van a estar presentes es el "estado inicial", este es, obviamente, donde va a comenzar la máquina, y este va a apuntar a todos los estados que pueda acceder.
Análisis de asequibilidad: Técnica para ver cuantos otros estados son alcanzables.

- Conjuntos de estados y tramas  
   _ S: Estados que tienen los procesos y el canal
  _ M: Tramas que se intercambian a través del canal  
   _ I: Estados iniciales
  _ T: Transiciones entre estados  
  Bloqueos irreversibles: Situación donde el protocolo se queda atasacaso en una secuencia.

## 3.5.2 Modelos de red de Petro

Elementos básicos

- Lugar: Estado en donde puede estar parte del sistema.
- Transiciones: Movimientos.
- Arcos: Permite la comunicación con varias entradas y/o salidas.
- Tokens: Indica donde esta el sistema.

# 4.6 Bluetooth

## 4.6.1 Arquitectura de Bluetooth

Piconet: Tiene un nodo maestro y hasta 7 nodos esclavos. Los piconets se pueden conectar entre ellos mismos usando un nodo puente.  
Scat-ternet: Piconets interconectadas.  
El problema con este tipo de comunicacion es que todas las comunicaciones tienen que pasar por el esclavo, dejandole toda la carga a este.

## 4.6.2 Aplicaciones de Bluetooth

- Tipos de perfiles
  - Acceso genérico
  - Descubrimiento de servicios
  - Puerto serie
  - Intercambio genérico de objetos
  - Acceso a LAN
  - Accesp telefónico a redes
  - Fax
  - Telefonía inalámbrica
  - Intercom
  - Headset
  - Envío de objetos
  - Transferencia de archivos
  - Sincronización

## 4.6.3 La pila de protocolos de Bluetooth

Las capas que tiene el blutooth pueden tener uno o más tipos de protocolos adentro, la capa inferior es similar a los modelos OSI y 802, la capa de banda base es similar a la subcapa MAC, la siguiente incorpora L2CAP, la capa del middleware contiene 802 y RFcomm y por último la capa superior que utiliza usa los protocolos de las capas anteriores.

### 4.6.4 La capa de radio

Este es el que se encarga de la comunicación entre los esclavos y el maestro, divide el espectro es dividido en 79 canales de 1 MHz cada uno pero gran cantidad de este es consumido por la sobrecarga.

### 4.6.5 La capa de banda base de Bluetooth

Esta se encarga de transformas los bits puros en ranuras para la comunicación. Se van a tener múltiples ranuras donde las pares le pertenece al maestro mientras que las impares son para los esclavos.

### 4.6.6 La capa de L2CAP de bluetooth

Esta capa se encarga de tres actividades, la aceptación de bits provenientes de las capas superiores y transformarlas en tramos, multiplexión y desmultiplexión de paquetes y de la calidad de los requerimientos de servicio.

### 4.6.7 Estructura de la trama de Bluetooth

Hay multiples tipos de tramas, pero la más importante seria una que consisten de 72 bits para el código de acceso, 54 bits para el heading y de 0 a 2744 para los mismos datos.
