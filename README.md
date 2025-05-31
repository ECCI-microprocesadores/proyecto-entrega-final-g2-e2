[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=19632572&assignment_repo_type=AssignmentRepo)
# Proyecto final

## Integrantes

[Maicol Linares](https://github.com/Maiik14)

[Ana Maria Zambrano](https://github.com/anazambranolozano)

[Sergio Florido](https://github.com/sergioflorido)

## Medición de distancia con sensor ultrasónico HC-SR04 usando PIC18F45K22


## Documentación

`Introducción`

La medición de distancia es una tarea fundamental en diversas aplicaciones de electrónica y robótica, permitiendo al sistema detectar la proximidad de objetos en su entorno. El sensor ultrasónico HC-SR04 utiliza ondas sonoras para medir la distancia de objetos mediante el tiempo que tarda el eco en regresar, lo cual es interpretado por el microcontrolador PIC18F45K22 para mostrar el valor en una pantalla LCD.

`Componentes y Funcionalidades`

-Sensor Ultrasónico HC-SR04:

Envía una señal ultrasónica de 40 kHz.
Recibe el eco cuando la señal rebota en un objeto.
Genera un pulso en el pin ECHO cuya duración es proporcional a la distancia al objeto.
Pines principales: TRIG (entrada para activar el pulso), ECHO (salida que indica duración del eco).

-Microcontrolador PIC18F45K22:

Controla el envío del pulso trigger.
Mide el tiempo del pulso ECHO con retardos en microsegundos.
Calcula la distancia con la fórmula basada en la velocidad del sonido.
Controla la pantalla LCD para mostrar resultados en tiempo real.

-Pantalla LCD 16x2:
Interfaz en modo 4 bits para optimizar el uso de pines.
Visualiza la distancia en centímetros.
Controlada mediante pines RC0 a RC5 del PIC.

-I2C (Interfaz preparada):
Código base para inicializar y controlar comunicación I2C, útil para futuras ampliaciones.

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


## Conclusiones


<!-- Crear una carpeta src e incluir en ella los códigos y/o el proyecto de mplab-->
