#include "unity.h"
#include "display.h"


// buffers para video: frontbuffer y backbuffer
extern uint8_t g_framebufferA [DRIVER_FRAMEBUFFER_SIZE];
extern uint8_t g_framebufferB [DRIVER_FRAMEBUFFER_SIZE];


struct DISPLAY display;


void setUp (void)
{
    // Inicia con datos conocidos en los buffers, para comprobacion por 0x00 en ESCENARIO Borrado de pantalla
    memset (g_framebufferA, 0xFF, sizeof(g_framebufferA));
    memset (g_framebufferB, 0xFF, sizeof(g_framebufferB));
}


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


// ESCENARIO Uso con sistema iniciado
void test_uso_sistema_iniciado (void)
{
    TEST_ASSERT_EQUAL (DISPLAY_Clear(0x34), true);
}


// ESCENARIO Borrado de pantalla
void test_borrado_de_pantalla (void)
{
    TEST_ASSERT_EQUAL (DISPLAY_Clear(0x00), true);

    for (uint32_t i = 0; i < (256*144); ++i)
    {
        TEST_ASSERT_EQUAL (display.backBuffer[i], 0x00);
    }
}

