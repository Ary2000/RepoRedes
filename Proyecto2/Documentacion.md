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

2. **Paquete query estándar:**
### DNS API:
### Elasticsearch/Kibana:
## Diagramas 
## Prerequisitos
Para este proyecto, se asume que tiene instalado los siguientes programas:

- Docker Desktop(ver [link](https://www.docker.com/))

## Manual de usuario
## Pruebas unitarias
## Recomendaciones
## Conclusiones
## Referencias bibliográficas