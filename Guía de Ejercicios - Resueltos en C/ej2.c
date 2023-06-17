#include <stdint.h>

void productoEscalar32(uint32_t *vectorIn, uint32_t *vectorOut, uint32_t longitud, uint32_t escalar);

int main(void) {

	uint32_t myVecIn[] = {1, 3, 5, 7, 9, 11};
	uint32_t myVecSize = sizeof(myVecIn) / sizeof(myVecIn[0]);
	uint32_t myVecOut[myVecSize];
	uint32_t scalar = 8;

	productoEscalar32(myVecIn, myVecOut, myVecSize, scalar);

	return 0;
}

void productoEscalar32(uint32_t *vectorIn, uint32_t *vectorOut, uint32_t longitud, uint32_t escalar) {

	for(; longitud > 0; longitud--) {
		vectorOut[longitud-1] = vectorIn[longitud-1] * escalar;
	}
}
