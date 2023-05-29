#include <stdint.h>
#define SIZE 5

void productoEscalar16(uint16_t *vectorIn, uint16_t *vectorOut, uint16_t longitud, uint16_t escalar);

int main(void) {

	uint16_t myVecIn[SIZE] = {10, 8, 9, 7, 11};
	uint16_t myVecOut[SIZE];
	uint16_t scalar = 12;
	uint16_t myVecSize = 0;

	myVecSize = sizeof(myVecIn) / sizeof(myVecIn[0]);
	productoEscalar16(myVecIn, myVecOut, myVecSize, scalar);

	return 0;
}

void productoEscalar16(uint16_t *vectorIn, uint16_t *vectorOut, uint16_t longitud, uint16_t escalar) {

	for(int i = 0; i < longitud; i ++) {
		vectorOut[i] = vectorIn[i] * escalar;
	}
}
