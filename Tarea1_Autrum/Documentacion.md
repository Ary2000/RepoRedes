# Instituto Tecnológico de Costa Rica  
## Escuela de Computación  
## Redes GR 2  
## Tarea Corta 1: ¿Por qué las voces de los integrantes son diferentes?  
## Profesor Gerardo Nereo Campos Araya  
## Estudiantes

- Ary-El Durán Ballestero | 2018102445
- Isaac David Ortega Arguedas | 2018189196
- Zhong Jie Liu Guo | 2018319114

## Fecha de Entrega 8/9/2022
---

## Objetivos
El objetivo de esta tarea es el de implementar un analizador de espectro de audio simple. Esto con el fin de profundizar los conceptos de señales y ondas utilizando software para generar la transformada de Fourier, graficar señales de audio en el dominio del tiempo y dominio de frecuencia.
## Descripción
Con el fin de lograr los objetivos, se debe de implementar una solución de software la cuenta con dos funciones:
### Analizador:
Toma señales de audio streaming (captura de micrófono) o batch (archivos WAV) y deberá almacenar el audio, en caso de ser streaming, graficar la señal en el dominio del tiempo del audio, además de, calcular su transformada de Fourier.

Con estos datos se debe graficar en tiempo real los componentes de frecuencia obtenidos mediante la transformada de Fourier y poder ver tanto el gráfico en el tiempo, así como en frecuencia al mismo tiempo. Una vez finalizada la grabación se debe generar un archivo .atm (Autrum File) que contendrá el audio original, junto con los datos usados 
para generar los gráficos en dominio de frecuencia.
### Reproductor:
Toma archivos con extensión .atm y puede reproducir el audio al mismo tiempo que los gráficos en dominio del tiempo y dominio de frecuencia.
## Diagramas 
### Diagramas de arquitectura
![image](./arquitectura)
### Diagrama de flujo
![image](./flujo)
## ¿Por qué las voces de los integrantes son diferentes?

Las voces de las personas son diferentes porque no todas llegan a las mismas notas, para esto esta el concepto de rango de voz, algunos pueden llegar a notas más graves mientras otros llegan a notas más agudas.
