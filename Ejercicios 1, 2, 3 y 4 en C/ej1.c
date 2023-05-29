#include <stdint.h>
#define SIZE 5

void zeros(uint32_t *vector, uint32_t longitud);

int main(void) {

	uint32_t myVec[SIZE];
	uint32_t myVecSize = 0;

	myVecSize = sizeof(myVec) / sizeof(myVec[0]);
	zeros(myVec, myVecSize);

	return 0;
}

void zeros(uint32_t *vector, uint32_t longitud) {

	for(int i = 0; i < longitud; i ++) {
		vector[i] = 0;
	}
}

