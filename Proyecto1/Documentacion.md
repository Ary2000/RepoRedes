# Instituto Tecnológico de Costa Rica  
## Escuela de Computación  
## IC 7602 - Redes - GR 2  
## Proyecto 1
## Profesor Gerardo Nereo Campos Araya  
## Estudiantes

- Ary-El Durán Ballestero | 2018102445
- Isaac David Ortega Arguedas | 2018189196
- Mario Fernández Robert | 2018163975
- Zhong Jie Liu Guo | 2018319114

## Fecha de Entrega 21/10/2022
---

## Objetivos
El objetotivo de este proyecto es el de implementar redes locales virtuales (VLAN) mediante la configuracipon de servicios de red.Esta red local debe contar con routers, servidores DHCP, servidor de DNS y servidor VPN. Además, implementa reglas de enrutamiento, reglas de firewall, implementa y configura un proxy reverso e instala Web Servers con sitios básicos.
El proyecto debe automatizar toda la configuración e instalación mediante Docker compese y Shell scripts. Así como utilizar herramientas de diagnóstico de redes.
## Descripción
Con el fin de lograr el objetivo, se debe implementar dos pequeñas redes virtuales que exponen diferentes servicios, toda la configuración debe ser implementada mediante Docker y Docker Compose.
### Redes 
Se cuenta con dos redes, cauna tiene se respectivo nombre, número de red y máscara.
### Routers
Se encargan de darle internet a su respectiva LAN Virtual, se encargan del tráfico de salida permitido. Permite el acceso externo mediante puertos especificados en la asignación.
### DNS
Implementa tres zonas. Cada componente en las redes tendrá una entrada en su respectiva zona. Como forwarder, se utilizarán los 8.8.8.8 y 8.8.4.4. Esto cambio se realizó pues se presentaron ciertos problemas que se arreglaron al cambiar el 8.8.8.9 por el 8.8.4.4
## Diagramas 
### Diagramas de arquitectura
![image](./arquitectura)
## Manual de usuario
## Pruebas unitarias