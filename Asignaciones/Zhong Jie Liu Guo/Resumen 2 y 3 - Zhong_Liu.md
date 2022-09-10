# Resumen 2 y 3
## IC-7602 - Redes
## Zhong Jie Liu Guo
## Carnet: 2018319114
## Profesor Gerardo Nereo Campos Araya
## Escuela de Ingeniería en Computación - ITCR
## Fecha: 30 de agosto de 2022
## ------------------------------------------------

### 2.5.1 Estructura del sistema telefónico.
- Modelo de conexión de cada teléfono con todos los demás
	- El primer modelo ideado por Alexander Graham Bell que se vendía en pares y le tocaba al cliente conectarlo con un alambre mientas los electrones regresaban por tierra. La desventaja es que si alguien se quería comunicar con una persona, se tenía que conectar con la casa. Por lo que si uno deseaba comunicarse con n casas, entonces se tenía que hacer n conexiones.
- Modelo de la oficina de conmutación
	- Se creó la primera oficina de conmutación llamada Bell Telephone Company. Este recibe los alambres de cada casa u oficina de los clientes. Luego, para hacer una llamada, el cliente daba vueltas a una manivela para producir un sonido distintivo que sirva para llamar la atención de la oficina para que pueda redirigir la llamada al receptor por un cable pueteador.
- Oficinas de conmutación de n-niveles
	- Como tener una sola oficina se volvió impráctico, se ideó el uso de oficinas intermediaras que conectaran otras oficinas para tener un sistema de jerarquías de hasta 5 niveles.
	- Cada teléfono tenía dos cables de cobre, de un largo de 1-10 km, que conectaban con una oficina central local de telefonía. Esta conexión se llamaba circuito local.
	- Si se da una llamada entre suscriptores en el circuito local, hay un mecanismo que establece una conexión directa eléctrica entre los dos que se mantiene hasta que termine.
	- Si están conectados en diferentes oficinas centrales, se usan las oficinas interurbanas con líneas entre ellas, llamadas **troncales de conexión interurbanas**, para establecer la conexión.
	- Si no hay una oficina interurbana en común, se revisa en una jerarquía más alta, que están conectadas también por troncales interurbanas de alto ancho de banda.
- En la actualidad, las transmisiones son digitales ya que hay más facilidad de identificar un 1 o 0 de una onda específica, solo el circuito local permanece análogo.

### 2.5.3 El circuito local: módems, ADSL e inalámbrico.   
- El modem realiza la conversión de datos, digitales a análogos y viceversa, para que las oficinas centrales lo conviertan en digitales y viceversa. 
- Las líneas de transmisión tienen 3 problemas principales:
	1. Atenuación: es la pérdida de energía cuando una señal viaja hacia su destino.
	2. Distorsión: esto pasa porque los componentes de Fourier pueden propagarse en diferentes velocidad por un cable.
	3. Ruido: Energía externas que no son pertenecientes a la transmisión.
- Modem
	- En la señalización de CA se usa un tono continuo en el rango de 1000-2000 Hz, llamado portadora de onda senoidal. Esta puede modular su amplitud, frecuencia o fase para transmitir información.
		* Amplitud: Para representar 0 y 1, se utilizan diferentes niveles de amplitud.
		* Desplazamiento de frecuencia: se usan dos (o más) tonos diferentes.
		* Fase: esta onda se deplaza de manera constante de 0 o 180 grados. Cuando hay una cambio de fase, este indica los límites del intervalo.
	- Un módem es un dispositivo que se conecta dentre la computadora y el sistema telefónico y tranforma una serie de bits de un medio al otro con los métodos anteriores.
	- Baudio: métrica de números de muestras por segundo
	- Símbolo: este es una información que se envía durante cada baudio
	- Dúplex total: La conexión que permite el tráfico bidireccional de forma simultánea.
	- Semidúplex: La conexión que permite el tráfico bidireccional, pero solo se permite su uso en un sentido a la vez.
	- Símplex: conexión de transmisión en una sola dirección.
- Líneas digitales de suscriptor (xDSL)
	- Los servicios cumplen varios objetivos
		1. Los servicios deben existir sobre los circuitos locales de par trenzado, CAT3.
		2. No deben afectar las máquinas de fax ni los teléfonos existentes.
		3. Deben superara por mucho los 56 kbps.
		4. Deben cobrar mensualmente, no por minuto.
	- Cuando un cliente se suscribe al servicio, este se conecta a un conmutador sin filtro, por lo que se le puede ofrecer más que el límite impuesto.

	- DMT (Multitono Discreto)
		- dividir el espectro de 1.1 MHz en 256 canales independientes de igual tamaño.
		- canal 0 se usaba para POTS.
		- canal 1-5 no se usan para evitar ruido.
		- un canal funciona para flujo ascendente y otro para el descendente, los demás se usan para datos del usuario.
	- DSL Asimétrica (ADSL)
		- divide en espectro en tres bandas de frecuencia:
			1. POTS (Servicio Telefónico Convencional).
			2. Canal ascendente (usuario a oficina central)
			3. Canal descendente (oficina centrala usuario)
		- este asigna de una forma desigual las proporciones de canales ascendentes y descendentes.
- Circuitos locales inalámbricos
	- WWL (Circuito Local Inalámbrico): alternatva antie los circuitos locales con cables de bajo costo.
	- MMDS (Servicio de Distribución  Multipunto y Multicanal): una MAN que utilizó los espectros de 198 MHz proevenientes de la televisión educativa. La ventaja es que el qeuipo se consigue con facilidad, pero las velocidades son moderadas.
 	- LMDS (Servicio Local de Distribución Multipunto): un servicio de WWL que se le asignó 1.3 GHz para la transmisión de ondas milimétricas usando circuitos integrados de arseniuro de galio.

### 2.5.4 Troncales y multiplexión.
- Multiplexión por División de Frecuencia (FDM): el espectro se divide en bandas de frecuencia y cada usuario tiene una banda asignada.
- Multiplexión por División de Longitud de Onda (WDM): en esta, en el emisor hay cuatro fibras (por el ejemplo) que se unen con un combinador. Estos viajan por una fibra compartida hasta que llegan a un divisor que manda las ondas a sus divisiones. En esas divisiones, hay un núcleo que filtra todas las longitudes excepto una. Cuando el número de canales es muy grande, se conoce como WDM Densa (DWDM).
- Multiplexión por División de Tiempo (TDM): se hace un round-robin y cada uno tiene su oportunidad de usar toda la banda por un tiempo.
	- Proceso de digitalizar señales analógicas y combinarlas en una sola troncal digital.
	- Modulación por Codificación de Impulsos (PCM): las señales digitales se digitalizan en la oficina central con el **codec (codificador-decodificador)** y se produce series de 8 bits. Se muestra 8000 por segundo. 

	- T1 o DS1: 24 canales de voz que se multiplexan juntos. Cada uno de los 24 inserta 8 bits de salida para hacer la salida digital. 7 de datos y 1 de control.
		- Una trama tiene 192 bits más uno extra para entramado. Este último sirve para sincronizar la trama y sigue el patrón 01010101...

### 2.7 Televisión por cable
- Televisión por antena comunal
	- Consistía en una antena grande en la cima de una colina para captar la señal, un amplificador para reforzar la señal y un cable coaxial que llega a las casas.
- Internet a través de cable
	- HFC (Red Híbrida de Fibra Óptica y Cable Coaxial): sistema con fibra y cable coaxial para las largas distancias.
	- Los nodos de fibra son convertidores que dan interacción entre las partes óptica y eléctrica del sistema. Este puede usarse como alimentador de múltiples cables coaxiales, más que un solo cable. 
- Asignación de espectro
	- Buscar una manera que en los cables puedan coexistir el internet y la televisión.
	- Introducir canales ascendentes en las banda de televisión y usar frecuencias en el extremo superior del rango dado para el flujo descendente.
- Módems de cable
	- Como antes el acceso a Internet requería un módem de cable, se pensó en crear un estándar llamado DOCSIS(Especificación de Interfaz para Servicio de Datos por Cable) para reemplazar los módems patentados.
- ADSL en comparación con el cable

|Cable|ADSL|
| --- | ---|
|Utiliza cable coaxial con extremo de cable coaxial. | Utiliza cable coaxial con extremo de par trenzado. |
|La capacidad de carga teórica es cien veces más que el par trenzado. | La capacidad de carga teórica es cien veces menos que el par trenzado. | 
|La capacidad máxima no está disponible para los usuarios. | La capacidad máxima está disponible para los usuarios. |
|No da ninguna indicación de capacidad efectiva ya que depende de las personas activas en el segmento del cable. | Se presentan una generalización de las capacidades de ancho de banda, dando un 80% de consistencia.|
|El rendimiento va a ser disminuir de acuerdo al incremento de clientes si no se hace algo al respecto. | El incremento de usuarios no afecta de manera significante el rendimiento.|
| Es menos seguro ya que cualquier usuario puede leer los paquetes que pasen por el cable. | Es más segura ya que es un medio de punto a punto. |
