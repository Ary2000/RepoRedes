# Prueba Corta #2 y #3
## Estudiante: Zhong Jie Liu Guo
## Carne: 2018319114
## Fecha: 10/9/2022

# Compilación
Para compilarlo se usa un compilador de Linux y se corre el siguiente comando:

> `gcc hamming.c -o hamming`

# Corrida
Para ver los comandos específicos, puede verlo al ejecutar el programa con el siguiente comando:

> `./hamming`

Para utilizar el encoder, se utiliza el siguiente formato como ejemplo:

> `./hamming encode --input 0x12AF`

Para utilizar el decoder, se utiliza el siguiente formato como ejemplo:

> `./hamming decode --input 0x12AF --error num_bit`

El argumento de `--error num_bit` puede aparecer una o más veces, entonces el comando sería el siguiente:

> `./hamming decode --input 0x12AF --error num_bit --error num_bit --error num_bit --error num_bit`