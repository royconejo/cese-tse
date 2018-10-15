#include "display.h"
#include <string.h> // para NULL


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

    return true;
}


bool DISPLAY_Clear (uint8_t color)
{
    if (!g_DISPLAY)
    {
        return false;
    }

    return true;
}
