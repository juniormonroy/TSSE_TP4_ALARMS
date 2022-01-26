/* TP4 Junior Monroy
EL TEST CONSISTE EN PROBAR EL SISTEMA DE ALARMA DE UN SISTEMA DE CONTROL PID DE
UN NIVEL DE AGUA DE UN TANQUE, EL MISMO CONTARA CON UN SENSOR ULTRASÓNICO EL
CUAL DETECTARA EL NIVEL Y EN BASE A LA MEDICIÓN SE DETERMINARAN ESTADOS DE
ALARMA, DONDE SE CONSIDERAN ALARMAS HH = ALARMA LIMITE ALTA ALTA NIVEL 90% H =
ALARMA LIMITE ALTA NIVEL 80% L = ALARMA LIMITE BAJO NIVEL 20% LL = ALARMA LIMITE
BAJO BAJO 10%

SE REALIZARAN PRUEBAS INYECTANDO DIVERSOS VALORES DE NIVEL PARA CORROBORAR QUE
LOS DISPAROS DE ALARMA SEAN CONGRUENTES Y ADEMÁS NO HAYAN INCONGRUENCIAS COMO
POR EJEMPLO ALARMA HH Y LL AL MISMO TIEMPO.

Se considera alarma activa almtk = 0x0001
Se considera sin alarma    almtk = 0x0000
*/

// Prender alarma alta alta HH encendida mayor a 90% de nivel de tanque
// Prender alarma alta encendida mayor a 80% de nivel de tanque
// Prender alarma baja baja encendida menor a 10% de nivel de tanque
// Prender alarma baja encendida menor a 20% de nivel de tanque
// Revisar valores normales mayor a 20% y menor a 80% no hay alarma de nivel
// Probar encendido invalido de alarma, todos en alarma

#include "alarms.h"
#include "unity.h"
#include <string.h>

#define HHValue 95 // NIVEL DE PRUEBA MAYOR AL UMBRAL DE DISPARO ALARMA 90
#define HValue 85  // NIVEL DE PRUEBA MAYOR AL UMBRAL DE DISPARO ALARMA 80
#define LValue 15  // NIVEL DE PRUEBA MENOR AL UMBRAL DE DISPARO ALARMA 20
#define LLValue 5  // NIVEL DE PRUEBA MENOR AL UMBRAL DE DISPARO ALARMA 10
#define MediumValue                                                            \
  50 // NIVEL MEDIO SIN ALARMA REFERIDA, PARA PROBAR NO ALARMA DE NIVEL

static uint16_t almtk;
void setUp(void) { nivelCreate(&almtk); }

// Prender alarma alta alta HH encendida mayor a 90% de nivel de tanque
void test_encender_alarma_hh(void) {

  almtk = 0x0000;    // ESTADO INICIAL SIN ALARMA
  Alarm_HH(HHValue); // VALOR DE ALARMA 95%
  TEST_ASSERT_EQUAL_HEX16(0x0001,
                          almtk); // SE VERIFICA QUE DEVOLVIO ALARMA DE HH
}

// Prender alarma alta encendida mayor a 80% de nivel de tanque
void test_encender_alarma_h() {
  almtk = 0x0000;  // ESTADO INICIAL SIN ALARMA
  Alarm_H(HValue); // VALOR DE ALARMA 85%
  TEST_ASSERT_EQUAL_HEX16(0x0001,
                          almtk); // SE VERIFICA QUE DEVOLVIO ALARMA DE HH
}

// Prender alarma baja baja encendida menor a 10% de nivel de tanque
void test_encender_alarma_l() {
  almtk = 0x0000;                         // ESTADO INICIAL SIN ALARMA
  Alarm_L(LValue);                        // VALOR DE ALARMA 15%
  TEST_ASSERT_EQUAL_HEX16(0x0001, almtk); // SE VERIFICA QUE DEVOLVIO ALARMA DE
                                          // L
}

// Prender alarma baja encendida menor a 20% de nivel de tanque
void test_encender_alarma_ll() {
  almtk = 0x0000;    // ESTADO INICIAL SIN ALARMA
  Alarm_LL(LLValue); // VALOR DE ALARMA 5%
  TEST_ASSERT_EQUAL_HEX16(0x0001,
                          almtk); // SE VERIFICA QUE DEVOLVIO ALARMA DE LL
}

// Revisar valores normales mayor a 20% y menor a 80% no hay alarma de nivel
void test_sin_alarma_nivel_normal() {
  almtk = 0x0001;        // ESTADO INICIAL EN ALARMA
  Alarm_HH(MediumValue); // SE INYECTA VALOR DE NIVEL DENTRO DEL RANGO ESTABLE
                         // SIN ALARMA 50%
  Alarm_H(MediumValue);  // SE INYECTA VALOR DE NIVEL DENTRO DEL RANGO ESTABLE
                         // SIN ALARMA 50%
  Alarm_L(MediumValue);  // SE INYECTA VALOR DE NIVEL DENTRO DEL RANGO ESTABLE
                         // SIN ALARMA 50%
  Alarm_LL(MediumValue); // SE INYECTA VALOR DE NIVEL DENTRO DEL RANGO ESTABLE
                         // SIN ALARMA 50%
  TEST_ASSERT_EQUAL_HEX16(
      0x0000, almtk); // SE VERIFICA QUE NO DEVOLVIO ALARMA, NIVEL ESTABLE
}

// Probar encendido invalido de alarma, todos en alarma
void test_encendido_alarma_invalida() {
  almtk = 0x0001;    // ESTADO INCIAL EN ALARMA
  Alarm_HH(LLValue); // PRUEBA DE VALOR 5% EN ALARMA HH(90%)
  Alarm_H(LValue);   // PRUEBA DE VALOR 15 EN ALARMA H(80%)
  Alarm_L(HValue);   // PRUEBA DE VALOR 85 EN ALARMA L(20%)
  Alarm_LL(HHValue); // PRUEBA DE VALOR 95 EN ALARMA LL(10%)
  TEST_ASSERT_EQUAL_HEX16(0x0000, almtk);
}