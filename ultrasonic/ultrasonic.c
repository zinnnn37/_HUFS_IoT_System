#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

#define TRIG 28 // 20
#define ECHO 29 // 21
#define LED 0 // 17

int	main(void)
{
	int		dist = 0;
	long	startTime, travelTime;

	if (wiringPiSetup() == -1)
		return 1;

	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
	pinMode(LED, OUTPUT);

	printf("ULTRA: \n");
	while (1)
	{
		digitalWrite(TRIG, LOW);
		usleep(2);
		digitalWrite(TRIG, HIGH);
		usleep(20);

		digitalWrite(TRIG, LOW);
		while (digitalRead(ECHO) == LOW)
			printf("LOW\n");
		startTime = micros();
		while (digitalRead(ECHO) == HIGH)
			printf("HIGH\n");
		travelTime = micros() - startTime;
		dist = travelTime * 17 / 1000;
		printf("Distance: %d cm\n", dist);
		if (dist < 10)
			digitalWrite(LED, HIGH);
		else
			digitalWrite(LED, LOW);
		sleep(1);
	}
	return 0;
}
