#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "src/alarms.h"




























static uint16_t almtk;

void setUp(void) { nivelCreate(&almtk); }



void test_encender_alarma_hh(void) {



  almtk = 0x0000;

  Alarm_HH(95);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((almtk)), (

 ((void *)0)

 ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_HEX16);

}
