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
* El servicio de kibana va a estar en la dirección `localhost:30601`.
* Luego, va a aparecer un log-in, el usuario es **elastic** y la contraseña puede averiguarse corriendo el siguiente comando: `kubectl get secret quickstart-es-elastic-user -o=jsonpath='{.data.elastic}' | base64 --decode; echo`. Si está en Windows, se recomienda correrlo en una terminal de WSL o de Unix. También, se puede buscar en Lens con el nombre **quickstart-es-elastic-user**.
* Luego en **Dev Tools**, se puede correr el *elastic-script.txt* en la consola proporcionada por kibana para crear y llenar la BD.

Paso 3 . Configurar el DNS API, DNS Interceptor y cliente.
Primero, se ocupan construir las imagenes de los pods (se va a subir a docker hub despues) con el siguiente comando
> docker-compose build

Se instalan el API, el Interceptor y el cliente en el cluster de kubernetes
> helm install app-deployment .\app-deployment\

* Para probar el cliente, se debe acceder a un shell (recomendable usando Lens). Luego, ejecutar nslookup
    * en este caso, debe utilizar el *> server ip* ya que se realizó de forma transparente, solamente ponga la direccion que desea buscar. 
* Se expone un puerto a la máquina host en el puerto **30053** si se desea usar de modo local.
    - en este caso, se debe especificar el puerto anterior y asignar el servidor dns con el *> server ip*