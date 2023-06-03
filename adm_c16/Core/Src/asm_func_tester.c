/*
 * asm_func_tester.c
 *
 *  Created on: Jun 2, 2023
 *      Author: francesco
 */

#include "asm_func_tester.h"


void asm_sum_tester(void) {

	uint32_t a = 5;
	uint32_t b = 3;
	uint32_t resultado;

	resultado = asm_sum(a, b);
}


/* EJERCICIO 1 ---------------------------------------------------------------*/
void asm_zeros_tester(void) {

	uint32_t myVec[] = {1, 3, 5, 7, 9, 11};

	asm_zeros(myVec, sizeof(myVec) / sizeof(myVec[0]));
}


/* EJERCICIO 2 ---------------------------------------------------------------*/
void asm_productoEscalar32_tester(void) {

	uint32_t myVecIn[] = {1, 3, 5, 7, 9, 11};
	uint32_t myVecSize = sizeof(myVecIn) / sizeof(myVecIn[0]);
	uint32_t myVecOut[myVecSize];
	uint32_t scalar = 8;

	asm_productoEscalar32(myVecIn, myVecOut, myVecSize, scalar);
}


/* EJERCICIO 3 ---------------------------------------------------------------*/
void asm_productoEscalar16_tester(void) {

	uint16_t myVecIn[] = {1, 3, 5, 7, 9, 11};
	uint16_t myVecSize = sizeof(myVecIn) / sizeof(myVecIn[0]);
	uint16_t myVecOut[myVecSize];
	uint16_t scalar = 4;

	asm_productoEscalar16(myVecIn, myVecOut, myVecSize, scalar);
}


/* EJERCICIO 4 ---------------------------------------------------------------*/
void asm_productoEscalar16Sat_tester(void) {

	uint16_t myVecIn[] = {1, 3, 5, 7, 9, 11};
	uint16_t myVecSize = sizeof(myVecIn) / sizeof(myVecIn[0]);
	uint16_t myVecOut[myVecSize];
	uint16_t scalar = 600;

	asm_productoEscalar16Sat(myVecIn, myVecOut, myVecSize, scalar);
}
