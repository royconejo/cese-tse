#include "display.h"


// buffers para video: frontbuffer y backbuffer
uint8_t g_framebufferA [DRIVER_FRAMEBUFFER_SIZE];
uint8_t g_framebufferB [DRIVER_FRAMEBUFFER_SIZE];


// Si el sistema esta iniciado, se apunta a una estructura provista por la aplicacion
static struct DISPLAY   *g_DISPLAY  = NULL;


bool DISPLAY_Init (struct DISPLAY *d)
{
    if (!d)
    {
        return false;
    }

    // Se asignan a la estructura los punteros a front y backbuffer
    d->frontBuffer  = g_framebufferA;
    d->backBuffer   = g_framebufferB;

    // Sistema iniciado
    g_DISPLAY = d;

    return true;
}


bool DISPLAY_Clear (uint8_t color)
{
    if (!g_DISPLAY)
    {
        return false;
    }

    // Borra el backbuffer con el color especificado
    memset (g_DISPLAY->backBuffer, color, DRIVER_FRAMEBUFFER_SIZE);

    return true;
}

