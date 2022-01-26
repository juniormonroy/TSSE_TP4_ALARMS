#include "alarms.h"
#include <stdint.h>

#define HH 90 // UMBRAL DE DISPARO ALARMA ALTA ALTA 90% DE NIVEL
#define H 80  // UMBRAL DE DISPARO ALARMA ALTA 80% DE NIVEL
#define LL 10 // UMBRAL DE DISPARO ALARMA BAJA BAJA 10% DE NIVEL
#define L 20  // UMBRAL DE DISPARO ALARMA BAJA 20% DE NIVEL

static uint16_t *alm_puerto; // PUERTO VIRTUAL ESTADO DE ALARMA GENERAL

void nivelCreate(uint16_t *nivelt) { // SE INICIALIZA EL PUERTO
  alm_puerto = nivelt;
  *alm_puerto = 0x0000;
}

void Alarm_HH(uint16_t HHVal) { // ALARMA DE ALTA ALTA
  if (HHVal > HH)
    *alm_puerto = 0x0001;
  else
    *alm_puerto = 0x0000;
}

void Alarm_H(uint16_t HVal) { // ALARMA DE ALTA
  if (HVal > H)
    *alm_puerto = 0x0001;
  else
    *alm_puerto = 0x0000;
}

void Alarm_L(uint16_t LVal) { // ALARMA DE BAJA
  if (LVal < L)
    *alm_puerto = 0x0001;
  else
    *alm_puerto = 0x0000;
}
void Alarm_LL(uint16_t LLVal) { // ALARMA DE BAJA BAJA
  if (LLVal < LL)
    *alm_puerto = 0x0001;
  else
    *alm_puerto = 0x0000;
}