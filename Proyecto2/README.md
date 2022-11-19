### Configuración de elastic

Ubicarse en la carpeta principal de Proyecto2

Paso 1. Configurar los operadores de ECK (si ya los tiene, omita este paso)
> helm install eck-deployment ./eck-deployment/

Paso 2. Configurar Elastic y Kibana
* Para facilitar su operación y no tener problemas de ErrPullImage, se recomienda hacer un pull a las imágenes de elastic y kibana usando:
    * `docker pull docker.elastic.co/elasticsearch/elasticsearch:8.4.0`
    * `docker pull docker.elastic.co/kibana/kibana:8.4.0`
* Luego, se usa el siguiente comando (Puede tardar varios minutos):
> helm install elastic-deployment ./elastic-deployment/
* Se debe hacer port-forwarding de kibana para usarlo, usando Lens o usando el siguiente comando:
> `kubectl port-forward service/quickstart-kb-kb-http 5601`

Paso 3 (Pendiente). Configurar el DNS API y DNS Interceptor.
> helm install app-deployment .\app-deployment\