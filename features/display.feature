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
    Cuando llamo a borrar pantalla con cualquier color como parametro
    Entonces la accion falla

Escenario: Inicio del sistema con parametro incorrecto
    Cuando llamo a iniciar sistema con NULL como parametro
    Entonces la accion falla

Escenario: Inicio correcto del sistema
    Cuando llamo a iniciar sistema pasando un puntero a estructura DISPLAY
    Entonces se asignan a la estructura los punteros a front y backbuffer
    Y la accion no falla

Escenario: Uso con sistema iniciado
    Dado un sistema iniciado correctamente
    Cuando llamo a borrar pantalla con cualquier color como parametro
    Entonces la accion no falla

Escenario: Borrado de pantalla
    Dado un sistema iniciado correctamente
    Cuando llamo a borrar pantalla con color 0x00
    Y borrar pantalla asigna 0x00 a cada byte del backbuffer
    Entonces la accion no falla
    Y el backbuffer contiene 0x00 en cada uno de sus bytes
