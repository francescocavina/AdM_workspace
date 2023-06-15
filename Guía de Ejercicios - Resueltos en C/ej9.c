#include <stdio.h>
#include <stdint.h>


void invertir(uint16_t * vector, uint32_t longitud);


int main(void) {

	uint16_t myVec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int32_t myVecSize = sizeof(myVec) / sizeof(myVec[0]);
	
	
/* TEST ----------------------------------------------------------------------*/

	for(uint32_t i = 0; i < myVecSize; i++) {
	
		printf("%d ", myVec[i]);
	}
	printf("\n\n");
	
	
	invertir(myVec, myVecSize);
		
	
	for(uint32_t i = 0; i < myVecSize; i++) {
	
		printf("%d ", myVec[i]);
	}
	printf("\n\n");
	
	return 0;
}


void invertir(uint16_t *vector, uint32_t longitud) {

	uint16_t aux;

	for(uint32_t i = 0; i < longitud / 2; i++) {
	
		aux = vector[i]; 			
		vector[i] = vector[longitud-1-i];	
		vector[longitud-1-i] = aux;
	}
}
