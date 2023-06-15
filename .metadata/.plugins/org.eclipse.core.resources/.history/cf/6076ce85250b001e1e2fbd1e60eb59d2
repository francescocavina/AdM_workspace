/*
 * asm_func_tester.c
 *
 *  Created on: Jun 2, 2023
 *      Author: Francesco Cavina
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


/* EJERCICIO 5 ---------------------------------------------------------------*/
void asm_filtroVentana10_tester(void) {

	uint16_t myVecIn[] = {1, 3, 5, 4, 6, 2, 8, 12, 7, 16};
	uint16_t myVecInSize = sizeof(myVecIn) / sizeof(myVecIn[0]);
	uint16_t myVecOut[myVecInSize];

	asm_filtroVentana10(myVecIn, myVecOut, myVecInSize);
}


/* EJERCICIO 6 ---------------------------------------------------------------*/
void asm_pack32to16_tester(void) {

	int32_t myVecIn[] = {32500, 439000, 65500, 7010000, 115400, 4000450, 3990705493, 1200, 815440, 340444};
	uint32_t myVecInSize = sizeof(myVecIn) / sizeof(myVecIn[0]);
	int16_t myVecOut[myVecInSize];

	asm_pack32to16(myVecIn, myVecOut, myVecInSize);
}


/* EJERCICIO 7 ---------------------------------------------------------------*/
void asm_max_tester(void) {

	int32_t myVecIn[] = {32500, 439000, -65500, 7010000, -115400, 4000450, 90705493, -1200, 815440, 340444};
	uint32_t myVecInSize = sizeof(myVecIn) / sizeof(myVecIn[0]);

	int32_t max = asm_max(myVecIn, myVecInSize);
}


/* EJERCICIO 8 ---------------------------------------------------------------*/
void asm_downsampleM_tester(void) {


}


/* EJERCICIO 9 ---------------------------------------------------------------*/
void asm_invertir_tester(void) {


}


/* EJERCICIO 10 --------------------------------------------------------------*/



/* EJERCICIO 11 --------------------------------------------------------------*/
void asm_corr_tester(void) {


}
