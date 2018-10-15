#include "unity.h"
#include "display.h"


// buffers para video: frontbuffer y backbuffer
extern uint8_t g_framebufferA [DRIVER_FRAMEBUFFER_SIZE];
extern uint8_t g_framebufferB [DRIVER_FRAMEBUFFER_SIZE];



// ESCENARIO Comprobacion de tamaño de los buffers
void test_tamanio_buffers (void)
{
    TEST_ASSERT_EQUAL (sizeof(g_framebufferA), (256*144));
    TEST_ASSERT_EQUAL (sizeof(g_framebufferB), (256*144));
}


// ESCENARIO Uso con el sistema no iniciado
void test_uso_sistema_no_iniciado (void)
{
    TEST_ASSERT_EQUAL (DISPLAY_Clear(0x12), false);
}



