#include "dusty_rpi.h"
#include <stdio.h>

int main()
{
	if(map_peripheral(&gpio) == -1) 
	{
       	 	printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
        	return -1;
    	}

	// Define gpio 17 as output
	INP_GPIO(18);
	OUT_GPIO(18);

	while(1)
	{
		// Toggle 17 (blink a led!)
		GPIO_SET = 1 << 18;
		sleep(1);

		GPIO_CLR = 1 << 18;
		sleep(1);
	}

	return 0;	

}
