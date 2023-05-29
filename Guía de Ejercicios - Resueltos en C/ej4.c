#include <stdint.h>
#include <math.h>
#define SIZE 			5
#define MAX_BITS_SATURATION 	12

void productoEscalar16(uint16_t *vectorIn, uint16_t *vectorOut, uint16_t longitud, uint16_t escalar);

int main(void) {

	uint16_t myVecIn[SIZE] = {10, 8, 9, 7, 11};
	uint16_t myVecOut[SIZE];
	uint16_t scalar = 420;
	uint16_t myVecSize = 0;

	myVecSize = sizeof(myVecIn) / sizeof(myVecIn[0]);
	productoEscalar16(myVecIn, myVecOut, myVecSize, scalar);

	return 0;
}

void productoEscalar16(uint16_t *vectorIn, uint16_t *vectorOut, uint16_t longitud, uint16_t escalar) {

	int result = 0;
	
	for(int i = 0; i < longitud; i ++) {
	
		result = vectorIn[i] * escalar;
		
		if(result >= 0 && result <= ((uint16_t) pow(2, MAX_BITS_SATURATION) - 1)) {
			vectorOut[i] = result;
		} else {
			vectorOut[i] = ((uint16_t) pow(2, MAX_BITS_SATURATION - 1));
		}			
	}
}
