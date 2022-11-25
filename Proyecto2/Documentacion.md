# Instituto Tecnológico de Costa Rica  
## Escuela de Computación  
## IC 7602 - Redes - GR 2  
## Proyecto 2
## Profesor: Gerardo Nereo Campos Araya  
## Estudiantes:

- Ary-El Durán Ballestero | 2018102445
- Isaac David Ortega Arguedas | 2018189196
- Mario Fernández Robert | 2018163975
- Zhong Jie Liu Guo | 2018319114

## Fecha de Entrega 25/11/2022
---

## Objetivo
El objetivo de este proyecto es el de implementar servicios de capa de aplicación sobre protocolos de transporte UDP y TCP. Para esto se debe desarrollar servidores UDP y TCP en lenguajes de programación C y Python respectivamente, además de, implementar el procesamiento de algunas peticiones DNS especificadas en RFC-2929. Todo esto teniendo que resultar en una solución automatizada mediante el uso de Docker, Docker Compose, Helm Charts y Kubernetes.

## Descripción
Ya que el proyecto II busca profundizar los temas de capa de aplicación y capa de transporte mediante la implementación de aplicaciones que utilicen protocolos TCP y UDP, se deberá implementar los siguientes componentes:
### DNS Interceptor:
Este es un Deployment, cada pod tendrá una pequeña aplicación  C, que escuchará en el puerto UDP/53, esta aplicación recibirá paquetes del protocolo DNS. Deberá examinar el paquete recibido siguiendo la especificación oficial en el RFC2929 y tomar alguna de las siguientes acciones:

1. **Paquete diferente a query estándar:** codifica el paquete a **base64** y via HTTPS se lo envia al NDS API, la respuesta recibida estara en **base64**, esta debe ser decodificada y enviada al cliente solicitante.

2. **Paquete query estándar:** examinarlo detenidamente e identificar el host que se esta tratando de resolver, una 
vez que el host ha sido identificado, deberá buscar en Elasticsearch si un registro para este host existe y tomar alguna de las siguientes acciones:
    
    *  Si existe, deberá extraer la información de esta base de datos y retornar la información, este debe cumplir con la especificación del protocolo en RFC2929.
    * En caso de no existir, la solicitud se trata como el primer caso.
### DNS API:
Este es un Deployment, cada pod contiene container que ejecuta un REST API implementado en Python, que ejecuta un único método en un único verbo HTTP, este único método recibe en el data un paquete DNS (RFC2929) codificado en 
base64, este deberá ser decodificado y enviado a un servidor DNS remoto para su resolución, esto implica lo siguiente:
    
* Esta aplicación deberá implementar un REST API, que a su vez implemente un cliente UDP/DNS para enviar las solicitudes hacia el servidor DNS remoto.
* Esta aplicación deberá recibir como parámetro/archivo de configuración el IP de un servidor DNS remoto.
* Esta aplicación deberá soportar múltiples peticiones al mismo tiempo.
### Elasticsearch/Kibana:
Es un componente que no se tiene que implementar pero que si debe instalarse y configurarse mediante el uso de Docker, Docker compose, Helm Charts y Kubernetes. En este componente deberán existir los siguientes recursos:
* Un índice llamado zones.
* Documentos dentro de este índice que representan hosts, estos tendrán el siguiente formato: `hay que agregar el formato`
* Estos documentos se pueden crear, borrar o modificar en cualquier momento mediante Kibana.
## Diagramas

> Diagrama de arquitectura

![](./assets/arquitectura-proy-2.png)

## Prerequisitos
Para este proyecto, se asume que tiene instalado los siguientes programas:

- Docker Desktop(ver [link](https://www.docker.com/))
- Lens(ver [link](https://k8slens.dev/))

- Helm(ver [link](https://helm.sh/))

## Manual de usuario
> Nota: README.md (ver [link](https://github.com/Ary2000/RepoRedes/tree/main/Proyecto2#readme)).
## Pruebas unitarias


## Recomendaciones

- Utilizar libb64 para el encoding a base64 de los paquetes en C.
- Utilizar la implementacion del MIT para el decoder de base64 en C.
- Preparar un script con querys de elastic search para seedear la base de datos cada vez que se realice una nueva instalacion del proyecto.
- Utilizar los snippets de Postman para referencias de uso de libcurl en C.
- Utilizar el plugin flask-swagger-ui para la documentacion swagger de los endpoints creados.
- Automatizar el proyecto mediante docker y helm.
- Mantener separada cada parte del proyecto para facilitar la ejecución y comprención del código.
- Utilizar una variable de entorno para la contraseña de elastic search y asi facilitar su uso.
- Revisar los elementos que las funciones esperan recibir o deben enviar.

## Conclusiones

- Un DNS funciona escencialmente como una base de datos, la cual almacena informacion relevante para el cliente solicitante de una resolucion de un dominio.
- Implementar un DNS con un round robin agrega flexibilidad al protocolo y nos deja expandir distintos domain names a un conjunto de ips.
- Los estandares RFC detallan especificamente byte por byte y bit por bit el contenido de los paquetes, es muy importante familiarizarse con la nomenclatura para entender los ASCII tables.
- La automatizacion de los proyectos mediante kubernetes y helm charts crean un beneficio considerable a la hora de expandir o compartir proyectos.
- Para implementar un DNS la opcion mas viable es mantener un base de datos no relacional para mantenerse rapida en respuesta y flexible en forma.


## Referencias bibliográficas

- libcurl - API. (s. f.). https://curl.se/libcurl/c/
- Malinen, J. M. (2005). Base64 encoding/decoding. web MIT. https://web.mit.edu/freebsd/head/contrib/wpa/src/utils/base64.c
- RFC 2929 - Domain Name System (DNS) IANA Considerations. (s. f.). https://datatracker.ietf.org/doc/html/rfc2929