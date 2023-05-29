#include <stdint.h>
#define SIZE 5

void productoEscalar32(uint32_t *vectorIn, uint32_t *vectorOut, uint32_t longitud, uint32_t escalar);

int main(void) {

	uint32_t myVecIn[SIZE] = {10, 8, 9, 7, 11};
	uint32_t myVecOut[SIZE];
	uint32_t scalar = 12;
	uint32_t myVecSize = 0;

	myVecSize = sizeof(myVecIn) / sizeof(myVecIn[0]);
	productoEscalar32(myVecIn, myVecOut, myVecSize, scalar);

	return 0;
}

void productoEscalar32(uint32_t *vectorIn, uint32_t *vectorOut, uint32_t longitud, uint32_t escalar) {

	for(int i = 0; i < longitud; i ++) {
		vectorOut[i] = vectorIn[i] * escalar;
	}
}
