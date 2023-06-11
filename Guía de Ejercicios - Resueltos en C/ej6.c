#include <stdint.h>
#include <stdio.h>

#define MAXSIZE 65536
#define MAXSIZEBITS 16

void pack32to16(int32_t * vectorIn, int16_t *vectorOut, uint32_t longitud);

int main(void) {

	uint32_t myVecIn[] = {32500, 439000, 65500, 7010000, 115400, 4000450, 3990705493, 1200, 815440, 340444};
	uint32_t myVecInSize = sizeof(myVecIn) / sizeof(myVecIn[0]);
	
	uint16_t myVecOut[myVecInSize];

	pack32to16(myVecIn, myVecOut, myVecInSize);
	
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

void pack32to16 (int32_t * vectorIn, int16_t *vectorOut, uint32_t longitud) {

	uint32_t aux = 0;

	for(; longitud > 0; longitud--) {

		aux = vectorIn[longitud - 1];	
		aux = (aux >> 16) & 0xFFFF;
		vectorOut[longitud - 1] = aux;	
	}
}


