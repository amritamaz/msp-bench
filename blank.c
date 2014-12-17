#include "stdio.h"
#include "msp430.h"


int main(void){
	unsigned int i;
	for (i = 100; i > 0; i--){
		printf("this is print statement %d.", i);
	}
	return 0;
}
