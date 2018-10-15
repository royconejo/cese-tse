#pragma once

#include <stdint.h>
#include <stdbool.h>


#define DRIVER_FRAMEBUFFER_SIZE     (256*144)


// Estructura que guarda el estado de la interfaz del sistema de video 
struct DISPLAY
{
    uint8_t *   frontBuffer;
    uint8_t *   backBuffer;
};


// Borra pantalla al color especificado, devuelve "false" si falla
bool DISPLAY_Clear (uint8_t color);


