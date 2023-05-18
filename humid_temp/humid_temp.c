#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#define MAX_TIME 86	//modify
#define DHT11PIN 29		// 21

int	dht11_val[5] = { 0, 0, 0, 0, 0 };
int	dht11_tmp[5] = { 0, 0, 0, 0, 0 };
float	farenheit_tmp;

void	dht11_read_val()
{
	uint8_t	lststate = HIGH;
	uint8_t	cnt = 0;
	uint8_t	j = 0, i;
	float	farenheit;

	for (i = 0; i < 5; i++)
		dht11_val[i] = 0;
	
	pinMode(DHT11PIN, OUTPUT);
	digitalWrite(DHT11PIN, 0);
	delay(18);
	digitalWrite(DHT11PIN, 1);
	delayMicroseconds(40);
	pinMode(DHT11PIN, INPUT);

	for (i = 0; i < MAX_TIME; i++)
	{
		cnt = 0;

		while (digitalRead(DHT11PIN) == lststate)
		{
			cnt++;
			delayMicroseconds(1);
			if (cnt == 255)
				break ;
		}
		lststate = digitalRead(DHT11PIN);
		if (cnt == 255)
			break ;
		if ((i >= 4) && (i % 2 == 0))
		{
			dht11_val[j/8] <<= 1;
			if (cnt > 26)	// modify
				dht11_val[j/8] |= 1;
			j++;
		}
	}
	printf("j: %d, dht11_val: %d %d %d %d\n", j, dht11_val[0], dht11_val[1], dht11_val[2], dht11_val[3]);
	if ((j >= 40) && (dht11_val[4] == ((dht11_val[0] + dht11_val[1] \
		+ dht11_val[2] + dht11_val[3]) & 0xFF)))
	{
		farenheit = dht11_val[2] * 9./5. + 32;
		printf("Humidity = %d.%d %% Temperature = %d.%d *C (%.1f *F)\n" \
			, dht11_val[0], dht11_val[1], dht11_val[2], dht11_val[3], farenheit);
		for (i = 0; i < 5; i++)
			dht11_tmp[i] = dht11_val[i];
		farenheit_tmp = farenheit;
	}
	else
	{
		printf("Humidity = %d.%d %% Temperature = %d.%d *C (%.1f *F)\n" \
			, dht11_tmp[0], dht11_tmp[1], dht11_tmp[2], dht11_tmp[3], farenheit);
		printf("ERROR\n");
	}
}

int	main(void)
{
	if (wiringPiSetup() == -1)
		return -1;

	while (1)
	{
		dht11_read_val();
		sleep(1);
	}
	return 0;
}
