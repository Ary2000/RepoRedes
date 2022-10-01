## Prueba Corta #4
### Redes - IC-7602
### Escuela de Ingeniería en Computación, ITCR
### 30-09-2022
Estudiante
* Zhong Jie Liu Guo - 2018319114

1. Explique el concepto de Time Division Multiplexing y Frequency Division Multiplexing. <br> 

&nbsp;&nbsp; 
El multiplexing sirve para permitir que se comparta las líneas de comunicación en un ancho de banda entre muchas señales. La forma de dividirlo determina ambos conceptos de la multiplexión. La Frecuency permite que todos puedan usar el ancho de banda al mismo tiempo, pero cada uno tiene asignado cierto rango de frecuencias para transmitir. Este tiene un detalle y es que se desperdicia parte de la frecuencia entre los límites para evitar las colisiones entre dos frecuencias. La time permite que un usuario pueda utilizar todo el ancho de banda solamente por un tiempo. Luego de eso, se le da oportunidad a otro para que lo utilice y sigue de la misma forma. 

2. Explique el concepto de colisión durante el proceso de asignación del canal, comente las diferencias entre medios guiados y medios no guiados.<br> 

&nbsp;&nbsp; Al asignar un canal, se debe pensar en las posibles condiciones donde puede darse una colisión. Una de ellas puede ser la frecuencia por la cual deba pasar, si está muy ocupada o compite con otros aparatos en el mismo canal. Una colisión puede provocar que la señal del mensaje original se atenúe y pierda datos y hay varias formas de que esto pueda pasar. En un medio guiado como una conexión con un cable coaxial o de fibra óptica, la posibilidad de darse una colisión va a darse dependiendo del material del cable ya sea el largo, material, si es unidireccional o bidireccional. En medios no guiados como las señales inalábricas (WIFI), la colisión va a depender del medio por el cual las ondas viajen y la posible competencia con señales de la misma frecuencia. El ambiente como el aire, los objetos, los seres vivos pueden interrumpir de cierta forma una onda y bajar su potencia. También, otras señales del mismo espectro de ondas van a competir para lograr su transmisión.

3. ¿Como funciona el algoritmo de asignación del canal Aloha y Aloha Ranurado? Explique.<br> 

&nbsp;&nbsp;Ambos algoritmos tratan de transmisión inalámbrica por medio de satélites. El canal ALOHA va a componerse de varias estaciones desde la Tierra y estas apuntan a un satélite. Las estaciones envían sus datos sin algún tipo de sincronización al satélite. Esta manda lo recibido a todas las estaciones y con un token la estación sabe de quién era. Hay una gran probabilidad de colisiones no solo por el medio que es el aire, sino también por las colisiones entre paquetes. Esto deja con un éxito de 18% solamente. El ALOHA Ranurado mejora el algoritmo anterior utilizando una estación que se encarga de la sincronización. La estación va a indicar quién puede transmitir en el momento y les dice a las demás que esperen por un tiempo aleatorio para volver a preguntar. Cuando una estación logró transmitir, este tiene que esperar por un momento al azar para volver a hacerlo. Esto mejoró el éxito a 37%.
 

4. ¿Cuáles son las diferencias entre Hub y Switch? ¿Porqué razón el Switch es mejor?<br> 

&nbsp;&nbsp; Ambos dispositivos tienen puertos y pueden conectarse varias máquinas a una red. La conexión entre los puertos de un HUB es por medio de un bus de datos interno en el aparato. También, la transmisión es por difusión y es half duplex, esto quiere decir que la trasmisión es bidireccional, pero solo puede hacerse una dirección a la vez. Un switch funciona de otra forma al comunicar entre estaciones ya que este crea circuitos virtuales entre el emisor y receptor de forma inteligente. No hay límites en cuántos switches se pueden interconectar mientras que un hub puede tener un máximo de 4. El switch tiene una transmisión full duplex, quiere decir que es bidireccional y ambos lados pueden usar el medio al mismo tiempo. Los switches son mucho más caros que los hubs. El switch es mejor que el hub por varias razones: velocidad, facilidad, tecnología, seguridad, y el más destacable es a la hora de las colisiones ya que como el hub comparte el medio de sus puertos, este tiene que atrasarse para utilizar el bus y no intervenir en una posible comunicación. El switch usa los circuitos virtuales para generar una conexión digital entre los puertos que se van a utilizar y aislando la comunicación. Las posibles colisiones al utilizar un switch solamente serían entre las computadoras y los cables que se conectan al switch.

5. ¿Es posible transportar tramas Ethernet embebidas en imágenes PNG? Justifique su respuesta.<br> 

&nbsp;&nbsp; Es posible utilizar una imagen para transportar las tramas si se colocan los bits que la componen en un png. Si se usa el modelo RGB, cada una puede contener un byte y entonces, por pixel se puede guardar 3 bytes de información. Si tomamos una imagen de 200x200, tendrían capacidad de transportar 120000 bytes o casi 120 KB.