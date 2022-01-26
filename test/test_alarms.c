// Prender alarma alta alta HH encendida mayor a 90% de nivel de tanque
// Prender alarma alta encendida mayor a 80% de nivel de tanque
// Prender alarma baja baja encendida menor a 10% de nivel de tanque
// Prender alarma baja encendida menor a 20% de nivel de tanque
// Revisar valores normales mayor a 20% y menor a 80% no hay alarma de nivel
// Probar encendido invalidp de alarma, todos en alarma

#include "alarms.h"
#include "unity.h"
#include <string.h>

#define HHValue 95
#define HValue 85
#define LValue 15
#define LLValue 5

static uint16_t almtk;
void setUp(void) { nivelCreate(&almtk); }

void test_encender_alarma_hh(void) {

  almtk = 0x0000;
  Alarm_HH(HHValue);
  // TEST_ASSERT_EQUAL_HEX16(0x0000, almtk);
  TEST_ASSERT_EQUAL_HEX16(0x0000, 0X0001);
}
/*
void test_encender_alarma_h()
{

}

void test_encender_alarma_l()
{

}

void test_encender_alarma_ll()
{

}

void test_encendido_alarma_invalida()
{

}*/