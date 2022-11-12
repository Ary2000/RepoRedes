# Tecnológico de Costa Rica
## Ingenieria en Computación
### IC-7602 - Redes - II Semestre 2022
### Examen
### Isaac David Ortega Arguedas | 2018189196
---

## Pregunta 1 (40 pts)
La estación espacial Deep Space 13, será puesta en operación en el verano del año 5698, conocido como el año 2 e.E, la misma estará en una órbita geoestacionaria en el planeta Solaria, el cual es un gemelo idéntico de la Tierra. Al llegar al planeta Solaria, la estación desplegará un enjambre de satélites, cada satélite será colocado en una órbita geoestacionaria sobre el ecuador de Solaria, esto permitirá la formación de un anillo de satélites de comunicación junto con la estación espacial, solo un elemento de la formación tendrá comunicación directa con la Tierra, esto implica que cuando la estación se encuentra fuera del alcance de la Tierra, las comunicaciones provenientes de esta, son recibidas por un satélite y 
estas son enviadas a la estación de forma similar a como funciona un token ring, de igual forma las comunicaciones salientes de la estación serán enviadas a varios satélites hasta encontrar el adecuado que tiene conexión con la Tierra. La distancia entre la Tierra y la esta estación es de alrededor de 400 millones de kilómetros. Deep Space 13 es una estación internacional, esto implica que existen ciudadanos de todos los países viviendo en esta y se tienen que garantizar comunicaciones entre la estación y la tierra.

Lucky Starr Tech ha sido contratada para realizar una propuesta de cómo se implementaría la comunicación en el planeta Solaria en caso de realizar una colonización de este, los reportes iniciales es que en el planeta Solaria no existe vida inteligente, para esta primera etapa se iniciara con la colonización del territorio que será conocido como Namiapí, el cual corresponde a una superficie de 51180 km2 y es idéntico al territorio centroamericano conocido como Costa Rica, como se mencionó anteriormente el planeta Solaria es un gemelo idéntico de la Tierra.

Lucky Starr Tech tiene que realizar una propuesta de la capa física que utilizaría para garantizar las comunicaciones en todo Namiapí, debe justificar ¿por qué seleccionó esta capa física?, puede incluir 
diagramas para apoyar sus deducciones. Es muy importante hacer un uso eficiente de los recursos que se pueden transportar desde la tierra y es aún más importante mencionar que las comunicaciones deberán de estar en operación en menos de dos años en todo el territorio de Namiapí, no importa la velocidad, pero tiene que existir comunicación. En calidad de CTO de la empresa ustedes tienen que elaborar y justificar esta propuesta detalladamente. 

$R/$ Dadas las situaciones del planeta lo mejor seria la utilización de la comunicación satelital. Esto pues, gracias a una estación geoestacionaria, o a un de los multiples satelites que se encuentran sobre el ecuador, se tendria conexión en todo momento, esto gracias al token ring de satelites. Esto permiteria realizar la transmisión del planeta a la estación Deep Space.

Tambien hay que tomar en cuenta que, a comparación con los otros medios, las antenas son relativamente economicas. Y ya que no se cuenta con otros mediós artificiales que puedan causar interferencia el riesgo de colisiones es muy reducido.

## Pregunta 2 (30 pts)
Corría el año de 1993, en Costa Rica se encontraba de moda un programa de televisión llamado Nube Luz, todos los niños y niñasles gustaba verlo y cantar sus canciones, por esta misma época, un niño algo curioso 
recibió uno de los mejores regalos de su vida por parte de su madre y padre, unos Radios Walkie Talkie, este niño se preguntaba como su voz podía ingresar al dispositivo y aparecer en el otro dispositivo. Un día 
este niño viajo a Cristo Rey de Alajuela donde vivía una prima, esta localidad es cercana al Aeropuerto Juan Santamaria y llevó consigo los Radios Walkie Talkie, este niño y su prima se pusieron a transmitir las 
canciones de Nube Luz colocando un Radio Walkie Talkie cerca a la bocina del televisor y escuchando las canciones en el otro Radio Walkie Talkie y se alejaban hasta que la transmisión se cortaba, de un momento a otro se escucho una voz en este radio ajeno al programa de televisión, resultó ser un operador aéreo del aeropuerto Juan Santamaria, esta persona estaba muy molesta porque una frecuencia importante fue invadida por una niña y un niño inocentes, que simplemente estaban jugando.
Explique:
* Desde un punto de vista técnico, ¿Por qué razón se presentó este incidente?

El Walkie Talkie se encontraba en la misma frecuencia que la radio de la torre de control. Esto permitia que el Walkie Talkie pudiera recibir los mensajes de la torre de control y viseversa.

* ¿Por qué es necesaria la regulación de uso de frecuencias?

El problema presentado es un buen motivo del porque deberia ser regulado. Existen medios, que ya sea por privacidad o confiabilidad o seguridad no deberian ser vulnerados. Un dispositivo no regulado podria interferir con otros y esto podria provocar la perdida o filtración de información sencible o ciertos dispositivos podrian verse afectados si se exponen a ciertas frecuencias.

* ¿Por qué se debe certificar los dispositivos y limitar su frecuencia de transmisión?

En la actualidad las frecuancias tienen un uso ya especificado, por ellos no se quiere que un dispositivo pueda acceder a una frecuencia a la que su uso no pertenece. Para esto es que se debe certificar los dispositivos.

* ¿Por qué la privacidad va de la mano con las redes? En especial en medios inalámbricos.

En la actualidad las redes son el medio por el cual la mayoria de la información es transmitida. Alguna de esta información transmitida es información sensible y se espera que los unicos que conoscan su contenido sean el emisor y el receptor. Es por esto que se requere que las redes sean seguras. Si nos centramos en el aspecto de la redes en los medios inalambricos hay que ser muy cuidadosos pues existen formas de recibir información de la cual no se es destinatario, ejemplo de esto es un router en modo promiscuo. Si la información que se encia por estos medios no esta asegurada la información podria ser vulnerada muy facilmente.

* Suponiendo que se encuentran en el año 1993, ¿Qué solución darían para evitar este problema? 

Ya que probablemente el uso de señales no sea lo más optimo, puede que la construcción de un tipo de muro que utilice materiales que disipen señales puede ser una buena idea. Mover la torre de control si bien no es optimo podria prevenir que el problema vuelva a ocurrir. Delimitar un perimetro en el cual no pueden estar personas puede ser otra opción.

## Pregunta 3 (15 pts)
Desde un punto de vista de congestión a nivel de capa de red:
* ¿Por qué razón overprovisioning de hardware no es una herramienta efectiva para lidiar con la congestión? (10 pts)

El motivo por el cual no es un medio efectivo es que no se tiene sertesa de que estos servidores extra llegaran a ser utilizados y por lo tamto estarian siendo desperdiciados. Esto se puede notar especialmente al tomar en cuenta que hay medios para disminuir o prevenir el congestionamiento.
* ¿Como el uso de Inteligencia Artificial (IA) y el análisis de tráfico de capa de red, puede ayudar a tomar decisiones más adecuadas para asegurar un QoS en la red, será posible implementar prioridad de tráfico basado en IA? (5 pts)

La inteligencia artificial podria ser capas de determinar más certeramente si un segmento de red se esta empezando a congestionar, esto seria util ya que se podria hacer que las tramas tomen otras rutas o se le podria indicar a los routers que tomen acciones para manejar la situación que les provoca el congestionamiento.

Dicho esto no creo que actalmente sea posible implementar una IA capas de hacer esto sin comprometer la calidad de servicio, esto pues seria un paso extra en el proceso de transmisión de datos y debido al tamaño de las redes puede que sea uno muy costoso en terminos de tiempo.
## Pregunta 4 (15 pts)
El ancho de banda es el recurso más importante en redes, hacer un uso eficiente y adecuado de este es primordial tanto en clientes como servidores y en todos los dispositivos por los que pasa un paquete
cuando viaja de un punto a otro en Internet (network hops).
* Explique en detalle, ¿Cómo afectan los saltos entre routers el round-trip time de un paquete entre dos puntos de Internet?, ¿Cómo afecta el MTU este tiempo y como nos beneficia conocer el mínimo MTU? Discuta las implicaciones de clientes, servidores y dispositivos de red intermedios 
(routers) que participan en la comunicación. (10 pts)

A mayor cantidad de saltos, mayor round-trip time. Especialmente si la trama enviada es mayor al MTU de un router, esto pues habria que dividir la trama, lo que implica agregarle un nuevo header y un trailer para identificar que venian juntos y luego esperar en el destino para rearmarlo.

Una ventaje de conocer cual es el MTU es que se pueden enviar tramas que lo aprevechen en su totalidad, que no nececiten ser partidas y que sel mensaje sera armado una vez se llegue al destino. Como ventaja adicional se tiene que en medios confiables la utilización de tramas pequeñas es ventajoso pues si una trama se pierde solo se necesita que se reenvie esa pequeña parte en lugar de algo de mayor tamaño o aun peor, la totalidad del mensaje.

* ¿Cómo el uso de caches regionales (cerca del usuario) pueden ayudar a reducir la cantidad de saltos, reducir el round-trip time y hacer un uso eficiente del ancho de banda? Discuta las implicaciones para clientes, servidores y dispositivos de red intermedios. (5 pts)

El uso de los cache es bastante util pues permite almacenar en memeria información que puede vuelva a ser requerida dentro de poco, pero no lo almacena durante mucho tiempo lo que previene que se vuelva demasiado pesado. Esto permite que una solicitud que podria ser pasada en un inicio se vuelva más manejable para el sistema, pues se enuentra en cache y ya no tiene que volver a hacer la solicitud y esperar a recibir los datos. Si estan bien implementados los clientes (usuarios), no se daran cuenta de la presencia del cache, los servidores y dispositivos intermedios, dependiendo de la información cargada, se veran veneficiados al no tener que procesar peticiones que se pueden considerar redundantes.