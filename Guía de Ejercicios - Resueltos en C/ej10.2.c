#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096
#define SAMPLING_RATE 44100
#define DELAY_MS 20

void eco(int16_t *vectorIn, int16_t *vectorOut, uint16_t bufferSize, uint16_t samplingRate, uint16_t delay_ms);


int main(void) {

	int16_t myVecIn[BUFFER_SIZE] = {0};
	int16_t myVecOut[BUFFER_SIZE] = {0};
	
	srand(0);
	
	for(uint16_t i = 0; i < BUFFER_SIZE; i++) {
	
		myVecIn[i] = rand() % 65536 - 32768;
	}

	
	eco(myVecIn, myVecOut, BUFFER_SIZE, SAMPLING_RATE, DELAY_MS);
	
	
/* TEST ----------------------------------------------------------------------*/

	for(uint16_t i = 0; i < 10; i++) {
	
		printf("vectorIn[%d] = %d\n", i, myVecIn[i]);
	}
	
	printf("...\n");	
	
	for(uint16_t i = 878; i < 888; i++) {
	
		printf("vectorIn[%d] = %d\n", i, myVecIn[i]);
	}
	
	printf("\n\n");
	
	
	for(uint16_t i = 0; i < 10; i++) {
	
		printf("vectorOut[%d] = %d\n", i, myVecOut[i]);
	}
	
	printf("...\n");
	
	for(uint16_t i = 878; i < 888; i++) {
	
		printf("vectorOut[%d] = %d\n", i, myVecOut[i]);
	}	
	
	printf("\n\n");
	
	
	return 0;
}


void eco(int16_t *vectorIn, int16_t *vectorOut, uint16_t bufferSize, uint16_t samplingRate, uint16_t delay_ms) {

	uint16_t delay_samples = samplingRate * delay_ms / 1000;
	int16_t aux;
	
	for(uint16_t i = 0; i < bufferSize; i++) {
	
		if(i < delay_samples) {
			
			vectorOut[i] = vectorIn[i];
		} else {
			aux = i - delay_samples;
			aux = vectorIn[aux];
			aux /= 2;
			
			vectorOut[i] = vectorIn[i] + aux;
		}
	}
}


