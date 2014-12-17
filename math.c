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


void main(void) {

  
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
