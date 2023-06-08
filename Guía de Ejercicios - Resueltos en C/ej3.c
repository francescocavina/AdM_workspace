#include <stdint.h>

void productoEscalar16(uint16_t *vectorIn, uint16_t *vectorOut, uint16_t longitud, uint16_t escalar);

int main(void) {

	uint16_t myVecIn[] = {1, 3, 5, 7, 9, 11};
	uint16_t myVecSize = sizeof(myVecIn) / sizeof(myVecIn[0]);
	uint16_t myVecOut[myVecSize];
	uint16_t scalar = 4;

	productoEscalar16(myVecIn, myVecOut, myVecSize, scalar);

	return 0;
}

void productoEscalar16(uint16_t *vectorIn, uint16_t *vectorOut, uint16_t longitud, uint16_t escalar) {

	for(; longitud > 0; i--) {
		vectorOut[longitud-1] = vectorIn[longitud-1] * escalar;
	}
}
