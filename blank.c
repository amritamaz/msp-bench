#include "stdio.h"
#include "msp430.h"

/**
 * This implements the user application and should never return
 *
 * Must call WISP_init() in the first line of main()
 * Must call WISP_doRFID() at some point to start interacting with a reader
 */
int main(void){
	unsigned int i;
	for (i = 100; i > 0; i--){
		printf("this is print statement %d.", i);
	}
	return 0;
}
