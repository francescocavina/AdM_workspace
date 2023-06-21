#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096
#define SAMPLING_RATE 44100
#define DELAY_MS 20

void corr(int16_t *vectorX, int16_t *vectorY, int16_t *vectorCorr, uint32_t longitud);


int main(void) {

	// Se define señal sinusoidal 
	int16_t myVecA[] = {1, 5, 8, 10, 9, 6, 1, -4, -8, -10, -10, -7, -3, 2, 7, 9, 10, 8, 4, -8, -5, -9, -10, -9, -5, -1, 4, 8, 10, 9, 7, 2, -3, -7, -10, -10, -8, -3};
	
	// Se define la misma señal defasada 90°
	int16_t myVecB[] = {10, 9, 5, 7, -4, -8, -10, -9, -7, -2, 3, 7, 10, 10, 8, 4, -2, -6, -9, -10, -8, -5, 4, 5, 8, 10, 9, 6, 1, -4, -8, -10, -10, -7, -3, 2, 7, 9};
	
	// Se define señal sinusoidal 
	//int16_t myVecB[] = {1, 5, 8, 10, 9, 6, 1, -4, -8, -10, -10, -7, -3, 2, 7, 9, 10, 8, 4, -8, -5, -9, -10, -9, -5, -1, 4, 8, 10, 9, 7, 2, -3, -7, -10, -10, -8, -3};
	
	
	uint16_t myVecASize = sizeof(myVecA) / sizeof(myVecA[0]);
	int16_t myVecCorr[myVecASize];
	
	corr(myVecA, myVecB, myVecCorr, myVecASize);
	
	
/* TEST ----------------------------------------------------------------------*/

	printf("\n- - - Vector X - - - \n");
	for(uint16_t i = 0; i < myVecASize; i++) {
	
		printf("%d ", myVecA[i]);
	}
	printf("\n");
	
	
	printf("\n- - - Vector Y - - - \n");
	for(uint16_t i = 0; i < myVecASize; i++) {
	
		printf("%d ", myVecB[i]);
	}
	printf("\n");
	
	
	printf("\n- - - Vector Correlación - - - \n");
	for(uint16_t i = 0; i < myVecASize; i++) {
	
		printf("%d ", myVecCorr[i]);
	}
	printf("\n");
	
	
	return 0;
}


void corr(int16_t *vectorX, int16_t *vectorY, int16_t *vectorCorr, uint32_t longitud) {

	int16_t sum;

	for(uint16_t l = 0; l < longitud; l++) {
	
		sum = 0;
		
		for(uint16_t n = 0; n < longitud; n++) {
			if(n - l >= 0) {
				sum += (vectorX[n] * vectorY[n - l]);
			}		
		}
	
		vectorCorr[l] = sum;
	}
}


