[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=19632572&assignment_repo_type=AssignmentRepo)
# Proyecto final

## Integrantes

[Maicol Linares](https://github.com/Maiik14)

[Ana Maria Zambrano](https://github.com/anazambranolozano)

[Sergio Florido](https://github.com/sergioflorido)

## Medición de distancia con sensor ultrasónico HC-SR04 usando PIC18F45K22

## Documentación

`Introducción`

Cuando hicimos la elección de este proyecto, queríamos medir distancias sin tocar los objetos (como un robot que evita choques) a un bajo costo. Investigando, descubrimos el sensor el HC-SR04, es un sensor económico pero funcional, ya que envía El sensor envía una señal ultrasónica (como un silbido que nosotros no oímos) y espera a que rebote en los objetos para medir el tiempo de retorno.

El truco está en el PIC18F45K22: este microcontrolador no solo calcula el tiempo del eco, sino que también lo convierte en centímetros y lo muestra en una LCD.

`Componentes y Funcionalidades`

1. Sensor Ultrasónico HC-SR04:

Lo elegimos porque es fácil de usar y no requiere librerías tan complejas. De sus 4 pines, los pincipales son: 

`TRIG:` Ya que aquí le dijimos: "¡Envía el sonido!" (con un pulso de 10 µs).

`ECHO:` Y ya aquí nos responde: "¡El eco tardó X microsegundos en volver!".

![SENSOR](/IMAGENES/SENSOR.png)

2. Microcontrolador PIC18F45K22:

Este microcontrolador coordinó todo el proceso de medición:

Generó el disparo inicial
Envíó un pulso preciso de 10µs al pin TRIG para activar el sensor

Implementamos esto usando los temporizadores del PIC para garantizar la exactitud del pulso.

![FORMULA](/IMAGENES/FORMULA.png)

3. Pantalla LCD 16x2:

Inicialmente no arrojaba nada en la LCD, sin embargo hicimos algunos ajustes a uan parte del código para que funcionara, utilizando los pines RC0 a RC5 del PIC.

![LCD2](/IMAGENES/LCD2.png)

4. I2C:

Código fundamental para configurar y manejar la comunicación I2C, pensado en posibles expansiones a futuro.

`Descripción del Software`

-Inicialización:
Se configuran los puertos de entrada/salida, se inicializa la pantalla LCD, y se prepara el sensor ultrasónico.

-Funcionamiento:

Se envía un pulso trigger de 10 microsegundos.
El pin ECHO se pone en alto durante el tiempo que tarda el eco en regresar.
Se mide la duración de este pulso.
Se calcula la distancia con la fórmula:

`Distancia (cm)=(Duracion (µs)×0.0343)/2`

​El resultado se muestra en la pantalla LCD.
Se actualiza la medición cada 400 ms.

-Control del LCD:

En modo 4 bits para reducir número de pines.
Funciones para comandos, escritura de caracteres y cadenas, posicionamiento del cursor.

-Manejo del I2C:

Funciones básicas para iniciar, detener y enviar datos.
Código preparado para futuras implementaciones, aunque en este proyecto no es usado activamente.

`Detalles Técnicos del Código`

Uso de retardos (__delay_us, __delay_ms) para temporización precisa.
Lectura directa de pines para detectar el pulso de eco.
Control de bits individuales para la interfaz LCD.
Configuración del PIC18F45K22 para oscilador interno a 16 MHz.
Protección contra timeout en la medición para evitar bloqueos si no hay eco.

## Diagramas

![MONTAJE](/IMAGENES/MONTAJE.jpeg)

![DIAGRAMA MONTAJE1](/IMAGENES/DIAGRAMA%20MONTAJE1.png)


![DIAGRAMA PRO](/IMAGENES/DIAGRAMA%20PRO.jpg)

![VIDEO DEL MONTAJE Y CODIGO](https://github.com/ECCI-microprocesadores/proyecto-entrega-final-g2-e2/blob/main/IMAGENES/proy.mp4)

## Conclusiones

`[1]` Se desarrolló el circuito pero no obtuvimos el funcionamiento esperado ya que presentamos diversas fallas, tales como un sensor el cual no sensaba, se realizó el cambio, aún así siguió sin arrojar información el circuito, realizando un analisis a profundidad pudimos determinar que las fallas pudieron deberse a la falta de una resistencia en pull down o una falla en las conexiones de los pines sensor.


