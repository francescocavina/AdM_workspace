#include <stdint.h>
#include <math.h>
#include <stdio.h>

void filtroVentana10(uint16_t *vectorIn, float *vectorOut, uint16_t longitudVectorIn);

int main(void) {

	uint16_t myVecIn[] = {1, 3, 5, 4, 6, 2, 8, 12, 7, 16};
	uint16_t myVecInSize = sizeof(myVecIn) / sizeof(myVecIn[0]);
	
	float myVecOut[myVecInSize];

	filtroVentana10(myVecIn, myVecOut, myVecInSize);

	for(uint8_t i = 0; i < myVecInSize; i++) {
	
		printf("%d ", myVecIn[i]);
	}
	printf("\n");
	for(uint8_t i = 0; i < myVecInSize; i++) {
	
		printf("%.2f ", myVecOut[i]);
	}
	printf("\n");
	
	return 0;
}

void filtroVentana10(uint16_t *vectorIn, float *vectorOut, uint16_t longitudVectorIn) {

	uint8_t sum = 0;
	uint8_t windowSize = 11;

	for(; longitudVectorIn > 0; longitudVectorIn--) {
	
		printf("lonVeIn: %d\n", longitudVectorIn);
	
		for(int8_t j = ((longitudVectorIn - 1) + (windowSize / 2)) ; j > (longitudVectorIn - 1) - (windowSize / 2) - 1; j--) {
			
			printf("j: %d\n", j);
			
			if(j < 0 || j > 10 - 1) {
			
				sum += 0;
			} else {
			
				sum += vectorIn[j];
				printf("yep\n");
			}
		} 
		
		printf("sum: %d\n", sum);
		
		vectorOut[longitudVectorIn - 1] = (float) sum / windowSize;
		sum = 0;
	}
}
