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

	for(uint16_t i = longitudVectorIn; i > 0; i--) {
	
		sum = 0;
	
		for(int16_t j = (i - 1 + (WINDOWSIZE / 2)); j >= (i - 1 - (WINDOWSIZE / 2)); j--) {
		
			if(j >= 0 && j <= (longitudVectorIn - 1)) {
			
				sum += vectorIn[j];
			} 
		} 
		
		vectorOut[i - 1] = sum / WINDOWSIZE;
	}
}
