#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "src/alarms.h"


static uint16_t almtk;

void setUp(void) { nivelCreate(&almtk); }





void test_encender_alarma_hh(void) {



  almtk = 0x0000;

  Alarm_HH(95);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0001)), (UNITY_INT)(UNITY_INT16)((almtk)), (

 ((void *)0)

 ), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_HEX16)

                                ;

}





void test_encender_alarma_h() {

  almtk = 0x0000;

  Alarm_H(85);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0001)), (UNITY_INT)(UNITY_INT16)((almtk)), (

 ((void *)0)

 ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_HEX16)

                                ;

}





void test_encender_alarma_l() {

  almtk = 0x0000;

  Alarm_L(15);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0001)), (UNITY_INT)(UNITY_INT16)((almtk)), (

 ((void *)0)

 ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_HEX16);



}





void test_encender_alarma_ll() {

  almtk = 0x0000;

  Alarm_LL(5);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0001)), (UNITY_INT)(UNITY_INT16)((almtk)), (

 ((void *)0)

 ), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_HEX16)

                                ;

}





void test_sin_alarma_nivel_normal() {

  almtk = 0x0001;

  Alarm_HH(50);



  Alarm_H(50);



  Alarm_L(50);



  Alarm_LL(50);



  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((almtk)), (

 ((void *)0)

 ), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_HEX16)

                    ;

}





void test_encendido_alarma_invalida() {

  almtk = 0x0001;

  Alarm_HH(5);

  Alarm_H(15);

  Alarm_L(85);

  Alarm_LL(95);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((almtk)), (

 ((void *)0)

 ), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_HEX16);

}
