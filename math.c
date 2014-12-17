/**
 * @file       usr.c
 * @brief      WISP application-specific code set
 * @details    The WISP application developer's implementation goes here.
 *
 * @author     Aaron Parks, UW Sensor Systems Lab
 *
 */

#include "msp430.h"
#include <math.h>
typedef unsigned long UInt32;
UInt32 add(UInt32 a, UInt32 b)
{
return (a + b);
}
UInt32 mul(UInt32 a, UInt32 b)
{
return (a * b);
}
UInt32 div(UInt32 a, UInt32 b)
{
return (a / b);
}

float fp_add(float a, float b)
{
return (a + b);
}
float fp_mul(float a, float b)
{
return (a * b);
}
float fp_div(float a, float b)
{
return (a / b);
}


/**
 * This implements the user application and should never return
 *
 * Must call WISP_init() in the first line of main()
 * Must call WISP_doRFID() at some point to start interacting with a reader
 */
void main(void) {

  
//  // Register callback functions with WISP comm routines
//  WISP_registerCallback_ACK(&my_ackCallback);
//  WISP_registerCallback_READ(&my_readCallback);
//  WISP_registerCallback_WRITE(&my_writeCallback);
//  WISP_registerCallback_BLOCKWRITE(&my_blockWriteCallback);
//
//  // Get access to EPC, READ, and WRITE data buffers
//  WISP_getDataBuffers(&wispData);
//
//  // Set up operating parameters for WISP comm routines
//  WISP_setMode( MODE_READ | MODE_WRITE | MODE_USES_SEL);
//  WISP_setAbortConditions(CMD_ID_READ | CMD_ID_WRITE /*| CMD_ID_ACK*/);
//
//  // Set up EPC
//  wispData.epcBuf[0] = 0x05; // WISP version
//  wispData.epcBuf[1] = *((uint8_t*)INFO_WISP_TAGID+1); // WISP ID MSB
//  wispData.epcBuf[2] = *((uint8_t*)INFO_WISP_TAGID); // WISP ID LSB
//  wispData.epcBuf[3] = 0xAA;
//  wispData.epcBuf[4] = 0xBB;
//  wispData.epcBuf[5] = 0xCC;
//  wispData.epcBuf[6] = 0xDD;
//  wispData.epcBuf[7] = 0xEE;
//  wispData.epcBuf[8] = 0xFF;
//  wispData.epcBuf[9] = 0x99;
//  wispData.epcBuf[10]= 0xAA;
//  wispData.epcBuf[11]= 0xAA;
  
  // Talk to the RFID reader.
  while (1) {

    volatile UInt32 result[4];
    result[0] = 43125;
    result[1] = 14567;
    result[2] = add(result[0], result[1]);
    result[1] = mul(result[0], result[2]);
    result[3] = div(result[1], result[2]);

    volatile float fp_result[4];
    fp_result[0] = 54.567;
    fp_result[1] = 14346.67;
    fp_result[2] = fp_add(result[0], result[1]);
    fp_result[1] = fp_mul(result[0], result[2]);
    fp_result[3] = fp_div(result[1], result[2]);

  }
}
