Para crear la imagen para el pod de kubernetes, se debe ubicar en el directorio principal de la tarea. Luego, se construye la imagen con ``"docker build -t tarea2_server ./program"``. 

Para usar y levantar el kubernetes utilizando helm charts, se usa el comando ``helm install app-deployment ./app-deployment``. Para bajarlo, se usa ``helm delete app-deployment``.