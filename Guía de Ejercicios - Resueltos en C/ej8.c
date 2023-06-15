#include <stdio.h>
#include <stdint.h>


void downsampleM(int32_t * vectorIn, int32_t * vectorOut, uint32_t longitud, uint32_t N);


int main(void) {

	int32_t myVecIn[] = {100, 88, 123, 500, 1, 57, 980, 10, 45, 1, 450, 650, 976, 784, 1, 725, 680, 506, 120, 1, 34, 78, 90, 120, 1};
	uint32_t myVecInSize = sizeof(myVecIn) / sizeof(myVecIn[0]);
	int32_t myVecOut[myVecInSize];
	uint32_t N = 5;
	
	downsampleM(myVecIn, myVecOut, myVecInSize, N);
	
/* TEST ----------------------------------------------------------------------*/
	for(uint32_t i = 0; i < myVecInSize; i++) {
	
		printf("%d ", myVecIn[i]);
	}
	printf("\n");
	
	for(uint32_t i = 0; i < myVecInSize; i++) {
	
		printf("%d ", myVecOut[i]);
	}
	printf("\n");
	
	return 0;
}


void downsampleM(int32_t * vectorIn, int32_t * vectorOut, uint32_t longitud, uint32_t N) {

	uint32_t index = 0;
	
	/* Downsampling */
	for(uint32_t i = 1; i <= longitud; i++) {
		
		if(i % N != 0) {
		
			vectorOut[index] = vectorIn[i-1];
			index++;
		}
	}
	
	/* The remaining elements are initialized to 0 */
	for(; index < longitud; index++) {
	
		vectorOut[index] = 0;
	}
}
