#include <stdint.h>
#define SIZE 5

void zeros(uint32_t *vector, uint32_t longitud);

int main(void) {

	uint32_t myVec[] = {1, 3, 5, 7, 9, 11};

	zeros(myVec, sizeof(myVec) / sizeof(myVec[0]);

	return 0;
}

void zeros(uint32_t *vector, uint32_t longitud) {

	for(; longitud > 0; i--) {
		vector[longitud-1] = 0;
	}
}

