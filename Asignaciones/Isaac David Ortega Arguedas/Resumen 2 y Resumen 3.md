
# Tecnológico de Costa Rica
## Ingenieria en Computación
### IC-7620 - Redes
### Isaac David Ortega Arguedas
### Carnet: 2018189196
### II Semestre 2022
---
# Resumen 2 y Resumen 3
## Estructura del sistema telefónico
Poco después de que Alexander Graham Bell patentara el teléfono, y gracias a la alta demanda de este invento, quedó claro que el modelo de conexión de cada teléfono con todos los demás, como la red totalmente interconectada, conmutador centralizado y jerarquía de dos niveles, no iba a funcionar.

Bell fue capaz de darse cuenta de esto y formó la Bell Telephone Company, la cual abrió su primera oficina de conmutación en 1878. Estas se encargaban de colocar un alambre en la casa u oficina de cada cliente, posteriormente los clientes al momento de realizar una llamada eran recibidos es la oficina de la compañía desde la cual un operador redirigía al receptor de la llamada, esto mediante un cable punteado.

Posteriormente las personas deseaban realizar llamadas a mayores distancias, en un principio se pensó en conectar las oficinas mediante cables, pero esto provocaba que el problema original volviera a surgir, por este motivo se decidió crear oficinas de conmutación de segundo nivel. Pronto se requerían nuevas oficinas de segundo nivel. Por último, la jerarquía creció hasta los cinco niveles.
En forma resumida, , el sistema telefonico consta de tres componentes principales:
1. Circuitos locales: son los cables de par trenzado que van hacia las casas y las empresas
2. Troncales: fibra óptica digital que conecta a las oficinas de conmutación.
3. Oficinas de conmutación: donde las llamadas pasan de una troncal a otra.
## El circuito local: módems, ADSL e inalámbrico
Cuando una computadora desea enviar datos digitales sobre una línea analógica de acceso telefónico, es necesario convertir primero los datos a formato analógico para transmitirlos sobre el circuito local. El dispositivo conocido como módem es quien realiza la conversión. Los datos se convierten a formato digital en la oficina central de la compañía telefónica para transmitirlos sobre las troncales que abarcan grandes distancias.
Si en el otro extremo hay una computadora con un módem, se debe realizar la conversión inversa para recorrer el circuito local del destino.

La señalización analógica consiste en la variación del voltaje con el tiempo para representar el flujo de información. Si los medios de transmisión fueron fueran perfectos, el receptor recibirá exactamente la misma señal enviada por el transmisor. Desafortunadamente este no es el caso. Si los datos son digitales, esta diferencia puede conducir a errores.
Las líneas de transmisión tienen tres problemas principales:
* Atenuación
Perdida de la energía conforme la señal se propaga hacia su destino. La cantidad de potencia perdida depende de la frecuencia.
* Distorsión
Los componentes de Fourier de la transmisión se propagan a distintas velocidades por el cable. Estas diferencias de velocidad provocan una distorsión en la señal que se recibe en el otro extremo.
* Ruido
Energía no deseada de fuentes distintas al transmisor. El movimiento al azar de los electrones en un cable causa el ruido y es inevitable. 
### Módems
Debido a los problemas ya mencionados es indeseable tener un rango amplio de frecuencias en la señal. Desgraciadamente, las ondas cuadradas, como las de los datos digita les, tienen un espectro amplio y por ello están sujetas a una fuerte atenuación y a distorsión por retardo. Estos efectos hacen que la señalización de banda base (CC, corriente continua) sea inadecuada, excepto a velocidades bajas y distancias corta.

La señalización de CA (corriente alterna) se utiliza para superar los problemas asociados a la señalización de CC, en especial en las líneas telefónicas.

Un módem (por modulador-demodulador) es un dispositivo que acepta un flujo de bits en serie como entrada y que produce una portadora modulada mediante uno (o más) de estos métodos (o viceversa). El módem se conecta entre la computadora (digital) y el sistema telefónico (analógico).
### Líneas digitales de suscriptor
Conforme el acceso a Internet se tornaba una parte importante de su negocio, las compañías telefónicas se dieron cuenta de que necesitaban un producto más competitivo. En respuesta comenzaron a ofrecer nuevos servicios digitales sobre el circuito local. 

En un principio había muchas ofertas que se traslapaban, todas bajo el nombre general de
xDSL (Línea Digital de Suscriptor), por diversos x. El más popular fue el ADSL(DSL Asimétrica).
La razón por la cual los módems son tan lentos es que los teléfonos fueron creados para transportar la voz humana y todo el sistema se ha optimizado cuidadosamente con este propósito. Los datos siempre han sido un aspecto secundario.
El truco para que xDSL funcione es que cuando un cliente se suscribe al servicio, la línea de entrada se conecta a un tipo distinto de conmutador, que no cuenta con el filtro, gracias a lo cual toda la capacidad del circuito local queda disponible. No obstante, la capacidad del circuito local depende de varios factores, entre ellos su longitud, espesor y calidad general.
### Circuitos locales inalámbricos
De cierta manera, un teléfono fijo que utiliza un circuito local inalámbrico se parece un poco a un teléfono móvil, pero existen tres diferencias técnicas importantes. Primera, el cliente del circuito local inalámbrico con frecuencia desea conectividad de alta velocidad a Internet, al menos similar a la de ADSL. Segunda, al nuevo cliente probablemente no le importe que un técnico de la CLEC tenga que instalar una gran antena direccional en su techo, la cual apunta a la oficina central de la CLEC. Tercera, el usuario no se mueve, con lo cual se evitan todos los problemas aso ciados a la movilidad y la transferencia de celdas (cell handoff).
	
Estamos ante el surgimiento de una nueva industria: la inalámbrica fija (teléfono local y servicio de Internet ofrecidos por CLECs sobre circuitos locales inalámbricos).

## Troncales y multiplexión
La economía de escala desempeña un papel importante en el sistema telefónico. Cuesta prácticamente lo mismo instalar y mantener una troncal de ancho de banda alto que una de ancho de banda bajo entre dos oficinas de conmutación (es decir, el gasto principal es la excavación de zanjas y no el cable de cobre o la fibra óptica). En consecuencia, las compañías telefónicas han desarrollado esquemas complejos para multiplexar muchas conversaciones en una sola troncal física. Es tos esquemas de multiplexión se pueden dividir en dos categorías principales:
* FDM (Multiplexión por División de Frecuencia)
El espectro de frecuencia se divide en bandas de frecuencia, y cada usuario posee exclusivamente alguna banda. 
* TDM (Multiplexión por División de Tiempo)
Los usuarios esperan su turno (en round-robin), y cada uno obtiene en forma periódica toda la banda durante un breve lapso de tiempo.
### Multiplexión por división de frecuencia
Los filtros limitan el ancho de banda utilizable a cerca de 3000 Hz por canal de calidad de voz. Cuando se multiplexan muchos canales juntos, se asignan 4000 Hz a cada canal para mantenerlos bien separados. Primero se eleva la frecuencia de los canales de voz, cada uno en una cantidad diferente, después de lo cual se pueden combinar, porque en ese momento no hay dos canales que ocupen la misma porción del espectro.

Los esquemas de FDM que se emplean en el mundo están normalizados hasta cierto punto. Un estándar muy difundido es el de 12 canales de voz a 4000 Hz multiplexados dentro de la banda de 60 a 108 kHz.
### Multiplexión por división de longitud de onda
Para los canales de fibra óptica se utiliza una variante de la multiplexión por división de frecuencia. Aquí, cuatro fibras se juntan en un combinador óptico, cada una con su energía presente a diferentes longitudes de onda. Los cuatro haces se combinan en una sola fibra compartida para transmisión a un destino distante. En el extremo distante, el haz se divide en tantas fibras como hayan entrado. Cada fibra saliente contiene un núcleo corto especialmente construido que filtra todas las longitudes de onda, excepto una. Las señales resultantes pueden enrutarse a su destino o recombinarse en diferentes formas para transporte adicional multiplexado.
### Multiplexión por división de tiempo
Aunque FDM aún se utiliza sobre cables de cobre o canales de microondas, requiere circuitos analógicos y no es fácil hacerla con una computadora. En contraste, TDM puede manejarse por completo mediante dispositivos digitales y a ello se debe su popularidad en los últimos años. Desgraciadamente, sólo se puede utilizar para datos digitales. 
Las señales analógicas se digitalizan en la oficina central con un dispositivo llamado codec (codificador-decodificador), con lo que se produce una serie de números de 8 bits. El codec toma 8000 muestras por segundo (125 μseg/muestra) porque el teorema de Nyquist dice que esto es suficiente para capturar toda la información del ancho de banda de 4 kHz del canal telefónico. A una velocidad de muestreo menor, la información se perdería; a una mayor, no se ganaría información extra. Esta técnica se llama PCM (Modulación por Codificación de Impulsos). La PCM es el corazón del sistema telefónico moderno. En consecuencia, virtualmente todos los intervalos de tiempo dentro del sistema telefónico son múltiplos de 125 μseg.

## Televisión por cable 
Una alternativa para la conectividad de redes fija que está tomando mucha importancia. Muchas personas ya tienen su teléfono y servicio de Internet a través de cable, y los operadores de cable están trabajando arduamente para incrementar su participación de mercado.
### Televisión por antena comunal
El sistema consistió inicialmente en una antena grande en la cima de una colina para captar la señal de televisión, un amplificador, llamado amplificador head end, para reforzarla y un cable coaxial para enviarla a las casas de las personas.

Era un negocio familiar; cualquiera que fuera hábil con la electrónica podía establecer un servicio para su comunidad, y los usuarios podían pagarlo en conjunto. Conforme el número de suscriptores crecía, se unían cables adicionales al cable original y se agregaban amplificadores.
### Internet a través de cable
A través de los años, el sistema de televisión por cable creció y los cables entre las distintas ciudades se reemplazaron por fibra de ancho de banda alto, de manera similar a lo que sucedió con el sistema telefónico.

En los años recientes, muchos operadores de cable han decidido entrar al negocio de acceso a Internet y con frecuencia también al de la telefonía. Cuando se emplea en la difusión de televisión, todos los programas se difunden a través del cable y no importa si hay diez o tres o 10,000 televidentes. Cuando el mismo cable se utiliza para el acceso a Internet, el hecho de que haya 10 o 10,000 usuarios tiene mucha importancia. Si un usuario decide descargar un archivo muy grande, ese ancho de banda se les resta a otros usuarios. Entre más usuarios haya, habrá más competencia por el ancho de banda.
### Asignación de espectro
Deshacerse de todos los canales de TV y utilizar la infraestructura de cable tan sólo para el ac ceso a Internet tal vez generaría una cantidad considerable de clientes iracundos, por lo que las compañías de cable dudan en hacer esto. Además, la mayoría de las ciudades regulan estrictamen te lo que hay en el cable, por lo que podría no permitirse que los operadores de cable hagan esto aunque realmente deseen hacerlo. Como consecuencia, necesitan encontrar una manera de que las televisiones e Internet coexistan en el mismo cable.

Ya que la parte baja de la banda no se utiliza, la solución elegida fue introducir canales ascendentes en la banda de 5–42 MHz (un poco más arriba en Europa) y utilizar las frecuencias en el extremo superior para el flujo descendente.
### Módems de cable
El acceso a Internet requiere un módem de cable, un dispositivo que tiene dos interfaces: una en la computadora y la otra en la red de cable. En los primeros años de Internet por cable, cada operador tenía un módem de cable patentado, que era instalado por un técnico de la compañía de cable. Sin embargo, pronto quedó claro que un estándar abierto podría crear un mercado de módems de cable competitivo y bajar los precios, con lo que se alentaría el uso del servicio. Además, al permitir que los clientes compren los módems de cable en tiendas y que los instalen ellos mismos (como lo hicieron con los módems de teléfono V.9x) se podrían eliminar los temidos camiones de la compañía de cable.
### ADSL en comparación con el cable
Los dos utilizan la fibra óptica en la red dorsal, pero difieren en el extremo. El cable utiliza cable coaxial; ADSL, cable de par trenzado. La capacidad de carga teórica del cable coaxial es de cientos de veces más que el cable de par trenzado. Sin embargo, la capacidad máxima del cable no está disponible para los usuarios de datos porque la mayor parte del ancho de banda del cable se desperdicia en cosas inútiles; por ejemplo, en programas de televisión.

En la práctica, es difícil generalizar acerca de la capacidad efectiva. Los proveedores de ADSL indican específicamente el ancho de banda (por ejemplo, flujo descendente de 1 Mbps, flujo ascendente de 256 kbps) y por lo general logran alrededor de 80% de manera consistente. Los pro veedores de cable no dan ninguna indicación pues la capacidad efectiva depende de cuántas personas estén actualmente activas en el segmento de cable del usuario.

Conforme un sistema ADSL adquiere usuarios, este incremento tiene muy poco efecto en los usuarios existentes, debido a que cada usuario tiene una conexión dedicada. Con el cable, con forme más personas se suscriban al servicio de Internet, el rendimiento de los usuarios existentes disminuirá.

La disponibilidad es un tema en el que ADSL y el cable difieren. Todas las personas tienen teléfono, pero no todos los usuarios están lo suficientemente cerca de su oficina central local para obtener ADSL. Por otro lado, no todos los usuarios tienen cable, pero si usted tiene cable y la compañía proporciona acceso a Internet, puede obtenerlo. Para el nodo de fibra o el amplificador head end la distancia no es un problema. También vale la pena mencionar que debido a que el cable inició como un medio de distribución de televisión, pocos negocios cuentan con él.

## Bibliografía
Tanenbaum, A. (2003). Redes de computadoras (4ta ed). Pearson.
