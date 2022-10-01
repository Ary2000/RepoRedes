# Tecnológico de Costa Rica
## Ingenieria en Computación
### IC-7602 - Redes - II Semestre 2022
### Prueba Corta 4
### Isaac David Ortega Arguedas | 2018189196
---

1. Explique el concepto de Time Division Multiplexing y Frequency Division
Multiplexing
* **Time Division Multiplexing:** los usuarios esperan su turno, y cada cierto tiempo cada uno obtiene toda la banda durante un breve periodo de tiempo.
* **Frequency Division Multiplexing:**  el espectro de frecuencia se divide en bandas de frecuencia, y cada usuario posee exclusivamente alguna banda. Las bandas son grandes para evitar colisiones.
2. Explique el concepto de colisión durante el proceso de asignación del canal, comente las diferencias entre medios guiados y medios no guiados.

Las coliciones durante el proceso de asignación, estas colisiones se dan cuando el canal se prepara para realizar una transmisión de datos de parte una estación y otra estación, ya sea porque acaba de conectarse o porque el mensaje de que el canal se iba a utilizar lo le habia llegado, decide intentar enviar una transmisión.

La diferencia principal entre medios guiados y medios no guiados es la forma en la que se transmiten los datos. De forma muy resumida, los medios guiados utilizan un medio conductor el cual ayuda a transmitir los datos de un punto A un punto B de forma, más o menos, directa. Por otro lado, los medios no guiados son aquellos no se transmiten por medio en especifico, si no que más bien son "ondas" las cuales son transmitidas en todas direcciones hasta que llegan a su destino, esto si no existe una colisión.

3. ¿Como funciona el algoritmo de asignación del canal Aloha y Aloha Ranurado?
Explique 
* **Aloha:** En el mejor de los casos, todas las estaciones se transmiten a las estaciones centrales y esta retransmite a todas. No obstante, existen colisiones, y en el aire no hay forma de determinar si hay o no una colisión. El aire no es un buen medio de transmisión. 
La cantidad de colisiones se debe a la saturación de transmisiones en el aire
Mientras más estaciones de envío y recepción más probabilidades de colisión.
* **Aloha Ranurado:** Las estaciones solo pueden transmitir cuando la estación de sincronización lo indica. Esto disminuye las colisiones en el aire. Lo ideal es que si existe una colisión las estaciones deben de esperar un rato, esto para evitar que se vuelva a dar otra colisión. La estación que acaba de transmitir, debe esperar antes de volver a intentar transmitir.

4. ¿Cuáles son las diferencias entre Hub y Switch? ¿Porqué razón el Switch es mejor?
* **Hub:**
    * No es bueno desde un punto de vista de colisiones, ya que permimte regiones de colisión muy grande.
    * Tiene muchos puertos.
    * Se puede conectar uno con otro extendiendo la red.
    * Solo una estación puede transmitir al mismo tiempo.
* **Switch:**
    * Permite conectar muchisimos segmentos.
    * Permite realizar múltiples configuraciones.
    * Es inteligente para entregar las tramas a las estaciones adecuadas.
    * Es seguro.
    * Segregacion de tráfico. Segmentos logicos.
    * Tiene el concepto de awarness.
    * Entre otros.

Si bien no son todas estas son algunas de las caracteristicas principales de ambos. Se puede observar que el switch puede, de una u otra forma, realiar las mismas acciones de que un hub de una forma más eficiente o de forma más segura, evita colisiones.

5. ¿Es posible transportar tramas Ethernet embebidas en imágenes PNG? Justifique su respuesta. 

Sí es posible, esto debido a que las imagenes estan compuestas por bits. La computadora es la que se encarga de procesar esos bits con el fin de mostrar algo coherente. Por este motivo, toda la información de las tramas de Ethernet podria transformarse para ser manejadas como una imagen y una vez se tenga la imagen decgificarla para conseguir la trama. 