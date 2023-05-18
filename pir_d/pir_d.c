#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>
#include <stdlib.h>

#define PIR_D 7 // 27

char	pir_flag = 0;

void	pir_interrupt()
{
	pir_flag = 1;
}

int	main(void)
{
	if (wiringPiSetup() == -1)
		return -1;

	pinMode(PIR_D, INPUT);
	wiringPiISR(PIR_D, INT_EDGE_RISING, &pir_interrupt);
	
	while (1)
	{
		if (pir_flag == 1)
		{
			printf("PIR Detected\n");
			pir_flag = 0;
		}
		else
			printf("PIR Not Detected\n");
		usleep(500000);
	}
	return 0;
}
