#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>

#define TOUCH 2	//27
#define LED 0	//17

int	main(void)
{
	if (wiringPiSetup() == -1)
		return -1;

	pinMode(TOUCH, INPUT);
	pinMode(LED, OUTPUT);

	while (1)
	{
		if (digitalRead(TOUCH) == HIGH)
		{
			printf("Touch Detected\n");
			digitalWrite(LED, HIGH);
		}
		else
		{
			printf("Touch Not Detected\n");
			digitalWrite(LED, LOW);
		}
		usleep(20000);

	}
	return 0;
}
