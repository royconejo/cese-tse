#include "unity.h"
#include "display.h"


// buffers para video: frontbuffer y backbuffer
extern uint8_t g_framebufferA [DRIVER_FRAMEBUFFER_SIZE];
extern uint8_t g_framebufferB [DRIVER_FRAMEBUFFER_SIZE];


struct DISPLAY display;


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


// ESCENARIO Inicio del sistema con parametro incorrecto
void test_inicio_sistema_param_incorrecto (void)
{
    TEST_ASSERT_EQUAL (DISPLAY_Init(NULL), false);
}


// ESCENARIO Inicio correcto del sistema
void test_inicio_correcto_sistema (void)
{
    TEST_ASSERT_EQUAL (DISPLAY_Init(&display), true);
}


