#include "alarms.h"
#include <stdint.h>

#define HH 90
#define H 80
#define LL 10
#define L 20

static int bit_alm_HH;
static int bit_alm_H;
static int bit_alm_L;
static int bit_alm_LL;

static uint16_t *alm_puerto;

void nivelCreate(uint16_t *nivelt) {
  alm_puerto = nivelt;
  *alm_puerto = 0x0000;
}

void Alarm_HH(uint16_t HHVal) { alm_puerto = 0x0001; }