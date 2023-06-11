#include <stdint.h>
#include <math.h>
#include <stdio.h>

#define WINDOWSIZE 11

void filtroVentana10(uint16_t *vectorIn, uint16_t *vectorOut, uint16_t longitudVectorIn);

int main(void) {

	uint16_t myVecIn[] = {1, 3, 5, 4, 6, 2, 8, 12, 7, 16};
	uint16_t myVecInSize = sizeof(myVecIn) / sizeof(myVecIn[0]);
	
	uint16_t myVecOut[myVecInSize];

	filtroVentana10(myVecIn, myVecOut, myVecInSize);
	
	
/* TEST ----------------------------------------------------------------------*/
	for(uint16_t i = 0; i < myVecInSize; i++) {
	
		printf("%d ", myVecIn[i]);
	}
	printf("\n");
	
	for(uint16_t i = 0; i < myVecInSize; i++) {
	
		printf("%d ", myVecOut[i]);
	}
	printf("\n");
	
	return 0;
}

void filtroVentana10(uint16_t *vectorIn, uint16_t *vectorOut, uint16_t longitudVectorIn) {

	uint16_t sum;
	
	longitudVectorIn--;

	for(int16_t i = longitudVectorIn; i >= 0; i--) {
	
		sum = 0;
		
		int16_t upperLimit = i + (WINDOWSIZE / 2);
		int16_t lowerLimit = i - (WINDOWSIZE / 2);
		
		for(int16_t j = upperLimit; j >= lowerLimit; j--) {
		
			if(j >= 0 && j <= longitudVectorIn) {
			
				sum += vectorIn[j];
			} 
		} 
		
		vectorOut[i] = sum / WINDOWSIZE;
	}
}
