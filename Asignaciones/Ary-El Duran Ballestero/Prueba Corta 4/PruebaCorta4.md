Instituto Tecnológico de Costa Rica  
Escuela de Computación  
Redes GR 2  
Prueba Corta 4  
Profesor Gerardo Nereo Campos Araya  
Estudiante Ary-El Durán Ballestero  
Fecha de Entrega: 30/9/2022

1. Explique el concepto de Time Division Multiplexing y Frequency Division
   Multiplexing.
   - Time Division Multiplexing: Se le da accesso al recurso totalmente a un cliente por una cierta cantidad de tiempo, después de esto se le pasa a otro y asi en forma de round robin.
   - Frequency Division Multiplexing: Se divide el recurso en canales, donde todos los clientes reciben uno de estos, esto permite que todos los usuarios puedan usar parte del recurso al mismo tiempo-
2. Explique el concepto de colisión durante el proceso de asignación del canal, comente las diferencias entre medios guiados y medios no guiados.
   - Esto ocurre cuando dos o más estaciones estan buscando una manera de enviar un paquete a un punto como un router o satélite, al momento que encuentran algún método disponible resulta que dos intentan comenzar a enviar información por este medio, causando que los datos de todos colisionen.
   - En los medios guiados esto puede ocurrir cuando un cable se encuentra disponible y dos o más estaciones intentan enviar información a esta usando este mismo.
   - En los medios no guiados puede ser que dos dispositivos comienzen a usar el mismo canal de frecuencia del ancho de banda.
3. ¿Como funciona el algoritmo de asignación del canal Aloha y Aloha Ranurado?

   - El aloha puro consistia que todas las estaciones estaban conectadas a un satelite de manera inalambríca y si querian enviar datos, estos debian ser enviados al mismo tiempo, luego el satelite envia todos los paquetes que tenia que enviar a todas las estaciones, aunque no necesitaran esa información, esto causaba problemas de seguridad.
   - El aloha ranurado usaba ranuras que eran las que se encargaban de recibir la información cuando estaban libres, si se intentaba transmitir y no habían ranuras libres la estación se ponía a dormir un tiempo aleatorio antes de volver a intentar bsucar una ranura.

4. ¿Cuáles son las diferencias entre Hub y Switch? ¿Porqué razón el Switch es mejor?
   - Los switches no envian todas las tramas a todas las estaciones, sino envia las tramas a sus estaciones específicas
   - Los switches no tiene chance de colisión mientras los hubs si.
   - Los switches usan Full-Duples mientras los hubs usan Half-Duplex.
   - Los switches segregan el tráfico mientras los hubs no.
5. ¿Es posible transportar tramas Ethernet embebidas en imágenes PNG? Justifique su respuesta
   - Se pueden usar los bytes que se usan para los colores de los pixeles de la PNG para poder insertar todos los datos de una trama mientras se puede hacer que una columna o fila de estos pixeles sean una trama.
