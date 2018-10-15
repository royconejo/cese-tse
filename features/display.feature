# language: es
# encoding: utf-8

Característica: Interfaz del sistema de video de la expansion RETRO-CIAA 
    Como desarrollador de sistemas embebidos
    Quiero disponer de una interfaz sencilla y confiable
    Para gestionar areas de memoria contigua de frontbuffer y backbuffer para el sistema de video

Escenario: Comprobacion de tamaño de los buffers
    Dado un sistema con frontbuffer y backbuffer reservado en stack
    Cuando mido tamaño del frontbuffer y backbuffer del sistema
    Y el tamaño de ambos no es de (256*144) bytes
    Entonces el test falla

Escenario: Uso con el sistema no iniciado
    Dado un sistema no iniciado
    Cuando llamo a borrar pantalla con cualquier color
    Entonces la accion falla

Escenario: Arranque del sistema
    Dado un sistema iniciado
    Cuando llamo a borrar pantalla con cualquier color
    Entonces la accion no falla

Escenario: Borrado de pantalla
    Dado un sistema iniciado
    Cuando llamo a borrar pantalla con color 0x00
    Y borrar pantalla asigna 0x00 a cada byte del backbuffer
    Entonces la accion no falla
    Y el backbuffer contiene 0x00 en cada uno de sus bytes
