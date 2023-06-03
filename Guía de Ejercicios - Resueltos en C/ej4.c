#include <stdint.h>
#include <math.h>
#define SIZE 			5
#define MAX_BITS_SATURATION 	12

void productoEscalar16Sat(uint16_t *vectorIn, uint16_t *vectorOut, uint16_t longitud, uint16_t escalar);

int main(void) {

	uint16_t myVecIn[SIZE] = {1, 3, 5, 7, 9, 11};
	uint16_t myVecSize = sizeof(myVecIn) / sizeof(myVecIn[0]);
	uint16_t myVecOut[myVecSize];
	uint16_t scalar = 4;

	productoEscalar16(myVecIn, myVecOut, myVecSize, scalar);

	return 0;
}

void productoEscalar16(uint16_t *vectorIn, uint16_t *vectorOut, uint16_t longitud, uint16_t escalar) {

	int result = 0;
	
	for(; longitud > 0; i--) {
	
		result = vectorIn[longitud-1] * escalar;
		
		if(result >= 0 && result <= ((uint16_t) pow(2, MAX_BITS_SATURATION) - 1)) {
			vectorOut[longitud-1] = result;
		} else {
			vectorOut[longitud-1] = ((uint16_t) pow(2, MAX_BITS_SATURATION - 1));
		}			
	}
}
