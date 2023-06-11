#include <stdint.h>
#include <stdio.h>

#define MAXSIZE 65536
#define MAXSIZEBITS 16

int32_t max(int32_t * vectorIn, uint32_t longitud);

int main(void) {

	int32_t myVecIn[] = {32500, 439000, -65500, 7010000, -115400, 4000450, 90705493, -1200, 815440, 340444};
	uint32_t myVecInSize = sizeof(myVecIn) / sizeof(myVecIn[0]);
	
/* TEST ----------------------------------------------------------------------*/
	for(uint16_t i = 0; i < myVecInSize; i++) {
	
		printf("%d ", myVecIn[i]);
	}
	
	printf("\n\nMax value = %d\n\n", max(myVecIn, myVecInSize));
	
	return 0;
}

int32_t max(int32_t * vectorIn, uint32_t longitud) {

	int32_t max = vectorIn[0];
	
	for(; longitud > 0; longitud--) {
	
		if(vectorIn[longitud - 1] > max) {
		
			max = vectorIn[longitud - 1];		
		}
	}
	
	return max;
}


