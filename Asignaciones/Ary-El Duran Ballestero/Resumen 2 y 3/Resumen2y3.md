**Instituto Tecnológico de Costa Rica  
Escuela de Computación  
Redes GR 2  
Resumen 2 y 3  
Profesor Gerardo Nereo Campos Araya  
Estudiante Ary-El Durán Balestero  
Fecha de entrega 30/08/2022**

# Estructura del sistema Telefónico

Hubo gran demanda para los teléfonos después de que Alexander Graham Bell patentó este, cuando comenzó la venta de estos, los teléfonos venían en pares, esto era para luego conectar estos por cable para que se comunicaran entre los dos, esto termino siendo muy redundante, causando grandes cantidades de cables, por eso Bell crep su compañía Bell Telephone Company, con esto creó las oficinas de conmutación donde un operador se encargaba de comunicar dos teléfonos usando un cable puenteador, pero siempre se cayó al mismo problema más llamadas de larga distancia, así que se creó un sistema jerárquico para las llamadas.
Oficina central local: Centro de telefónico de una región.
Circuito local: Conexión de dos alambres entre cualquier teléfono y la oficina central local.
Oficinas interurbanas: Centros de conmutación que se encuentran conectados con el local.
Troncales de conexión interurbanas: Conexiones entre la oficina local y las interurbanas.
En el pasado, el sistema telefónico era de manera analógica, esto pasaba un voltaje eléctrico como señal de voz, pero se comenzó a cambiar a señales digitales por la fibra óptica y por lo más sencillo y barato que resulto ser.

# El circuito local: módems, ADSL e inalámbrico

Circuito local: Las conexiones de hogares y de pequeñas empresas a la compañía telefónica, esta línea es analógica.

- Los problemas de las líneas de transmisión
  - Atenuación: Esta es la pérdida de energía de la señal mientras se dirige a su destino.
  - Distorsión: Esta es causada por las diferencias de velocidad de la señal.
  - Ruido: Las energías no deseadas que afectan la señal, como la térmica causada por los electrones y la diafonía.

Corriente Continua: Es la señalización tipo digital, es inadecuada porque le afecta mucho la atenuación y la distorsión.  
Portadora de onda senoidal: Este es un tono continuo para transmitir información en el rango de 1000 a 2000 Hz. Aquí la amplitud, frecuencia o fase se modula para poder lograr esta transmisión de datos.  
Modulación de amplitud: Se usan dos niveles diferentes de amplitud para representar el 1 y el 0.  
Modulación de frecuencia: Se usan dos niveles diferentes de frecuencia para representar el 1 y el 0.  
Modulación de fase: Se realizan desplazamientos de 0 o 180 grados por intervalos.  
Módem: Es el encargado de transforma señales analógicas a digitales y viceversa.
Ancho de banda: Rango de frecuencias que atraviesan algún tipo de medio, sea alámbrico o inalámbrico.  
Tasa de baudios: Envió de muestras por segundo. (Una muestra es una parte de la información que se quiere enviar)  
Tasa de bits: Bits enviados por el canal.  
Diagramas de constelación: Diagramas que presentan la amplitud y la fase permitidas. Si hay muchos puntos en este, puede ser que haya grandes cantidades de errores por el ruido, por eso se implementan corrección de errores usando bits adicionales, estos son los TCM (Modulación por Codificación de Malla).

- V.32
  - 4 bits de datos y 1 bit de paridad
  - 32 puntos en la constelación
  - Corre en 9600 bps
  - 2400 baudios
- V.32 bis
  - 6 bits de datos y 1 bit de paridad
  - 128 puntos en la constelación
  - Corre en 14400 bps
  - 2400 baudios
- V.34
  - 12 bits de datos
  - Corre a 28800 bps
  - 2400 baudios
- V.34
  - 14 bits de datos
  - Corre 33600 bps
  - 2400 baudios

Símples: Envió por solo una dirección.  
Semidúplex: Envió en ambas direcciones, pero solo una mientras la usa.  
Dúplex: Envio de información en ambas direcciones al mismo tiempo.  
xDSL(Línea Digital de Suscriptor): Cuando un cliente se suscribía al servicio se iba a quitar unfiltro para que tuviera disponible toda la capacidad del circuito local.  
ADSL: Se divide las bandas de frecuencia del circuito local en tres, estos serian los POTS (Servicio Telefónico Convencional), el canal ascendente y el canal descendente.

# Troncales y multiplexión

## FDM (Multiplexión por División de Frecuencia)

En este caso el espectro de frecuencia se divide en espacios llamados bandas de frecuencia, esto se le da al cliente que necesite transmitir algo.  
En este tipo de multiplexión se van a ver diferentes divisiones del espectro de frecuencias, estos serán los canales por donde van a pasar lo comunicado, estos van a tener sus límites para mantenerlos separados y luego a todos estos se les sube la frecuencia a todos de manera distinta.

## TDM (Multiplexión por División de Tiempo)

Aquí el cliente puede usar toda la banda pero solo por un tiempo limitado.
En este caso las señales analógicas se transforman usando un codec donde lo transforma a una serie 8 bits.

## WDM (Multiplexión por División de Longitud de Onda)

Este seria lo mismo que la FDM pero esta se encuentra presente en los canales de fibra óptica.

# Televisión por cable

## Televisión por antena comunal

Este consistía en una antena que atrapara las señales, un amplificador para ayudar la señal y un cable coaxial que se conectaba a las casas de los clientes.

## Internet a través de cable

Este consistía enviar las señales que necesitaban recorrer distancias largas por fibra y cables coaxiales para las casas.

## Asignación de espectro

Esto tiene que ver con la necesidad de que el cable de internet sea compartido con el de la televisión, así que se necesita dividir el espectro de estos cables para poder proveer ambos servicios.
![imagenEspectro](./Imagenes/Asignacion%20del%20expectro.png)

## Módems de cable

Se desarrollo un estándar para los módems de cable para poder bajar los costos de estos ya que antes era necesario usar uno específico de la compañía que provee la internet.  
El módem al inicializarse busca un paquete especial que va a contener la información de los sistemas enviado por el amplificador head end, luego le envía a este su existencia donde luego el amplificador head end le va a otorgar canales de ascendencia y descendencia. Luego se calcula la distancia entre el amplificador y el modem, esto es la alineación, después de esto se comienzan las actividades tipo minirranuras donde se le pide al ISP un IP, pasos de seguridad y la iniciación de sesión.

## ADSL en comparación con el cable

Para saber cual es mejor que el otro, se tiene que ver en la situación que se encuentra en el momento, hay muchos factores que pueden hacer percibir uno mejor que el otro. Por ejemplo, el de cable podría ser teóricamente más poderosos pero su ancho de banda es utilizado en muchas cosas inútiles mientras que el ADSL es más seguro pero puede que este disponible porque no tengan ese servicio en el lugar. Así que la respuesta siempre va a variar.
