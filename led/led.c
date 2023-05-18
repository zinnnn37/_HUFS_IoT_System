#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include <time.h>

#define LED_RED 7
#define LED_BLUE 21
#define LED_GREEN 22

int	main(void)
{
	if (wiringPiSetup() == -1)
		return -1;
	pinMode(LED_RED, OUTPUT);
	pinMode(LED_GREEN, OUTPUT);
	pinMode(LED_BLUE, OUTPUT);
	// set pins as output

	digitalWrite(LED_RED, 0);
	digitalWrite(LED_GREEN, 0);
	digitalWrite(LED_BLUE, 0);
	// make led off
	
	printf("3 Color LED Control Start!!\n");
	for (int i = 0; i < 20; i++)
	{
		printf("Red On\n");
		digitalWrite(LED_RED, 1);
		// make red led on
		usleep(100000);

		printf("Red Off\nGreen On\n");
		digitalWrite(LED_RED, 0);
		digitalWrite(LED_GREEN, 1);
		usleep(100000);

		printf("Green off\nBlue on\n");
		digitalWrite(LED_GREEN, 0);
		digitalWrite(LED_BLUE, 1);
		usleep(100000);
		printf("Blue off\n");
		digitalWrite(LED_BLUE, 0);
	}
	return 0;
}
