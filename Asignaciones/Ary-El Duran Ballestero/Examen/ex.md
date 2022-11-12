**Instituto Tecnológico de Costa Rica  
Escuela de Computación  
Redes GR 2  
Examen Final
Profesor Gerardo Nereo Campos Araya  
Estudiante Ary-El Durán Balestero
Fecha de Entrega: 12/11/2022**

# Pregunta 1

La estación espacial Deep Space 13, será puesta en operación en el verano del año 5698, conocido como el año 2 e.E, la misma estará en una órbitageoestacionaria en el planeta Solaria, el cual es un gemelo idéntico de la Tierra. Al llegar al planeta Solaria, la estación desplegará un enjambre de satélites, cada satélite será colocado en una órbita geoestacionaria sobre el ecuador de Solaria, esto permitirá la formación de un anillo de satélites de comunicación junto con la estación espacial, solo un elemento de la formación tendrá comunicación directa con la Tierra, esto implica que cuando la estación se encuentra fuera del alcance de la Tierra, las comunicaciones provenientes de esta, son recibidas por un satélite y estas son enviadas a la estación de forma similar a como funciona un token ring, de igual forma las comunicaciones salientes de la estación serán enviadas a varios satélites hasta encontrar el adecuado que tiene conexión con la Tierra. La distancia entre la Tierra y la esta estación es de alrededor de 400 millones de kilómetros. Deep Space 13 es una estación internacional, esto implica que existen ciudadanos de todos los países viviendo en esta y se tienen que garantizar comunicaciones entre la estación y la tierra.

Lucky Starr Tech ha sido contratada para realizar una propuesta de cómo se implementaría la comunicación en el planeta Solaria en caso de realizar una colonización de este, los reportes iniciales es que en el planeta Solaria no existe vida inteligente, para esta primera etapa se iniciara con la colonización del territorio que será conocido como Namiapí, el cual corresponde a una superficie de 51180 km2 y es idéntico al territorio centroamericano conocido como Costa Rica, como se mencionó anteriormente el planeta Solaria es un gemelo idéntico de la Tierra.  
Lucky Starr Tech tiene que realizar una propuesta de la capa física que utilizaría para garantizar las comunicaciones en todo Namiapí, debe justificar ¿por qué seleccionó esta capa física?, puede incluir diagramas para apoyar sus deducciones. Es muy importante hacer un uso eficiente de los recursos que se pueden transportar desde la tierra y es aún más importante mencionar que las comunicaciones deberán de estar en operación en menos de dos años en todo el territorio de Namiapí, no importa la velocidad, pero tiene que existir comunicación.

En calidad de CTO de la empresa ustedes tienen que elaborar y justificar esta propuesta detalladamente.

## Respuesta

Como se necesita un método donde se pueden salvar los recursos de alguien y que también se quiere realizar de manera rápida en un gran terreno, el que mejor quedaría sería el tipo de comunicación tipo satelital, ya que llenar el terreno de todo Namiapí con cableado para la comunicación sería un trabajo increíblemente largo y costoso.

En este caso la propuesta consistiría en tener estaciones de trasmisión es zonas estratégicas para poder enviar información entre estas, el plan original podría ser que para poder realizar comunicados se debería estar dentro de la estación, pero si hubiera tiempo y recursos se podrían tener conexiones a otros sitios por medio de un cableado, por ejemplo, de cobre, en caso de comodidad o si el lugar donde se debe encontrar la estación podría terminar peligroso.

Diagrama de la estación local  
<img src="diagrama estacion.drawio.png" alt="drawing" width="500"/>

Además, se sabe de la existencia del anillo de satélites que se encuentra geoestacionario en el planeta, significa que ya se tiene un modelo de los satélites que se encuentran ya usando, se podrían usar estos mismos o uno con las modificaciones necesarias para poder completar la comunicación de Namiapí y que además, si se logra hacer de que las maneras de comunicación de los satélites sean compatibles, también sería compatible realizar comunicación entre Namiapí y la Tierra por medio de Deep Space 13.

Diagrama de actividad  
<img src="Conexion anillo.drawio.png" alt="drawing" width="510"/>

# Pregunta 2

Corría el año de 1993, en Costa Rica se encontraba de moda un programa de televisión llamado Nube Luz, todos los niños y niñasles gustaba verlo y cantar sus canciones, por esta misma época, un niño algo curioso recibió uno de los mejores regalos de su vida por parte de su madre y padre, unos Radios Walkie Talkie, este niño se preguntaba como su voz podía ingresar al dispositivo y aparecer en el otro dispositivo. Un día este niño viajo a Cristo Rey de Alajuela donde vivía una prima, esta localidad es cercana al Aeropuerto Juan Santamaria y llevó consigo los Radios Walkie Talkie, este niño y su prima se pusieron a transmitir las canciones de Nube Luz colocando un Radio Walkie Talkie cerca a la bocina del televisor y escuchando las canciones en el otro Radio Walkie Talkie y se alejaban hasta que la transmisión se cortaba, de un momento a otro se escucho una voz en este radio ajeno al programa de televisión, resultó ser un operador aéreo del aeropuerto Juan Santamaria, esta persona estaba muy molesta porque una frecuencia importante fue invadida por una niña y un niño inocentes, que simplemente estaban jugando.  
Explique:

- Desde un punto de vista técnico, ¿Por qué razón se presentó este incidente?
  - En este caso los chiquitos y el operador se encontraron utilizando la misma frecuencia, causando que hubiera ese tipo de intercepción.
- ¿Por qué es necesaria la regulación de uso de frecuencias?
  - • La regulación de las frecuencias es increíblemente importante por los casos presentes en el ejemplo dado, este es un caso no hubieron problemas realmente graves, al menos en lo contado, pero se puede ver como se podría fácilmente irrumpir la privacidad de ciertas comunicaciones, esto se podría utilizar para efectos maliciosos, por ejemplo si alguien quiere realizar problemas, podría tener múltiples radios en la frecuencia que se encuentra utilizando el aeropuerto he intentar llenarla de ruido para hacerle imposible la comunicación, por esto es importante tener la regulación, evitar que dispositivos normales puedan entrar a ciertas frecuencias para salvarlas para casos espaciales como el mismo aeropuerto evitara ataques accidentales o maliciosos.
- ¿Por qué se debe certificar los dispositivos y limitar su frecuencia de transmisión?
  - Esto es para poder darles frecuencias especiales a grupos o organizaciones importantes en el país en donde se encuentre, por ejemplo, en Costa Rica ya se tienen ciertas frecuencias para uso específico de ciertas ramas del gobierno, esto permitirá el uso de estas frecuencias para los miembros de este sin niguna interrupción.
- ¿Por qué la privacidad va de la mano con las redes? En especial en medios inalámbricos.
  - La comunicación en general siempre va de manos con la privacidad, las redes no son una diferencia, la posibilidad de que alguien se meta para poder robar información sensible siempre ha sido presentado en este ámbito, en especial por medios inalámbricos, ya que no se puede saber exactamente donde se encuentra la computadora 100%, la información es trasmitida por frecuencias que otro usuario podría invadir, así que se tienen que desarrollar métodos que prevean esto.
- Suponiendo que se encuentran en el año 1993, ¿Qué solución darían para evitar este problema?

  - La solución obvia sería comenzar a crear regulaciones de los dispositivos que pueden acceder a las frecuencias del aeropuerto, incluso se podría ver ya comenzar a poner frecuencias especificas para varias partes del gobierno y otras cosas.

# Pregunta 3

Desde un punto de vista de congestión a nivel de capa de red:

- ¿Por qué razón overprovisioning de hardware no es una herramienta efectiva para lidiar con la congestión? (10 pts)
  - El overprovisioning no es necesariamente una mala idea, pero el problema es como el costo de poder tener todo este hardware amarrado puede causar problemas de mantenimiento, se tendrán que andar actualizando el hardware constantemente y lo malo es que luego quede incompatible, que alimenta el otro problema de esta solución, cuál es el costo económico, ya que más hardware significa más compra.
- ¿Como el uso de Inteligencia Artificial (IA) y el análisis de tráfico de capa de red, puede ayudar a tomar decisiones más adecuadas para asegurar un QoS en la red, será posible implementar prioridad de tráfico basado en IA? (5 pts)
  - Uniendo estas dos ramas, se podría crear una inteligencia artificial que ya se encuentre encargada de realizar cambios de la prioridad de los paquetes, se podría manipular mejor los aspectos de confiabilidad, retardo, fluctuación y el ancho de banda dependiendo de que intente realizar un usuario y de ahí se podría entrenar la inteligencia artificial para que saque óptimos para el salvado de recursos mientras aun ofrece un buen servicio.

# Pregunta 4

El ancho de banda es el recurso más importante en redes, hacer un uso eficiente y adecuado de este es primordial tanto en clientes como servidores y en todos los dispositivos por los que pasa un paquete cuando viaja de un punto a otro en Internet (network hops).

- Explique en detalle, ¿Cómo afectan los saltos entre routers el round-trip time de un paquete entre dos puntos de Internet?, ¿Cómo afecta el MTU este tiempo y como nos beneficia conocer el mínimo MTU? Discuta las implicaciones de clientes, servidores y dispositivos de red intermedios (routers) que participan en la comunicación. (10 pts)
  - En cada salto puede pasar de que el paquete no llegue, o llegue con error, causando que se necesite reenviar una vez más, perdiendo tiempo. En el caso del MTU, este afectaría porque el tamaño afectaría cuanto tiempo duraría el envió en especial el caso de un paquete grande, donde se tiene que reenviar mucha más información. Conocer el mínimo MTU, nos daría la posibilidad de encontrar un óptimo donde el tamaño es lo suficientemente grande para enviar una buena cantidad de información y decentemente pequeña para no tener que durar mucho durante él envió.
- ¿Cómo el uso de caches regionales (cerca del usuario) pueden ayudar a reducir la cantidad de saltos, reducir el round-trip time y hacer un uso eficiente del ancho de banda? Discuta las implicaciones para clientes, servidores y dispositivos de red intermedios. (5 pts)
  - Este reduce en gran cantidad todos los aspectos mencionados anteriormente, ya que salvaría en el cache websites que son de gran posibilidad que una buena cantidad de usuarios vayan a buscar, esto permitirá que se cargue la página ya carga en el cache, no hay que tener que esperar que se haga todo el viaje. Entonces el cliente no tendrá que esperar mucho tiempo, el servidor no tendrá que esperar la respuesta del dispositivo que necesite responder el request y los dispositivos intermedios se podrán enfocar en otros request que se encuentren fuera del cache.
