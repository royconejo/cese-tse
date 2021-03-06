#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <string.h> // para NULL y memset


#define DRIVER_FRAMEBUFFER_SIZE     (256*144)


// Estructura que guarda el estado de la interfaz del sistema de video 
struct DISPLAY
{
    uint8_t *   frontBuffer;
    uint8_t *   backBuffer;
};


// Inicia el sistema
bool DISPLAY_Init (struct DISPLAY *d);

// Borra pantalla al color especificado, devuelve "false" si falla
bool DISPLAY_Clear (uint8_t color);

