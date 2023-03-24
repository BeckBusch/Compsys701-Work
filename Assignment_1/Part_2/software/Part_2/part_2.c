/*
 * my_binary_leds.c
 *
 *  Created on: March 2023
 *      Author: Morteza
 */

#include <stdio.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"

 // Init Matrices
int matrixA[10][10] = {
	{  6, 18,  1, 13, 20, 17, 15, 12, 17,  5 },
	{  2,  3, 13,  8,  2, 11, 11, 16, 15,  8 },
	{  2, 13, 15, 17, 17, 12, 12, 19, 16,  0 },
	{  4,  2, 10,  5,  6,  3, 13, 20, 13, 18 },
	{  8, 14, 18,  3, 10, 15,  9,  9,  2, 11 },
	{ 12,  3,  9,  4,  3, 20, 11, 12,  5,  9 },
	{ 19, 15, 16,  2,  3, 13,  6, 15,  2,  0 },
	{  1,  3, 11, 15,  7, 16,  6, 12, 10,  8 },
	{ 17,  7, 19,  5,  0, 16, 12,  9, 13,  0 },
	{  8, 12, 14,  6,  7,  3, 12,  5, 18,  4 } };

int matrixB[10][10] = {
	{ 10, 10,  3, 15, 16, 13,  7, 10,  0,  0 },
	{ 17,  2,  9,  4,  6, 15,  3, 17,  1,  4 },
	{ 14,  5,  1,  0, 12, 12, 15,  2, 19, 12 },
	{  0, 19,  1, 15, 10, 13,  1, 20, 20, 14 },
	{  8,  8, 13,  5,  4, 13, 14, 17, 18,  0 },
	{  1, 14, 18, 12,  1, 14, 18,  9, 15, 10 },
	{  2,  9, 20, 15, 13, 18,  9,  9, 15, 11 },
	{ 15, 17, 18, 11,  0,  9,  4, 18, 18, 16 },
	{  7, 20, 19,  2,  1, 20, 11,  7, 20,  9 },
	{ 20,  9,  1,  3,  1, 16, 16, 13, 18,  4 } };

int matrixC[10][10] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

int n = 10;

int main() {

	printf("This application performs NxN matrix operationtion\n");

	if (n < 2) {
		printf("Error: Matrix size N below 2\nExiting with code 1");
		return 1;
	}

	int switches = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_0_7_BASE);
	int switch0 = switches & 0b00000001;
	int switch1 = switches & 0b00000010;
	int opcode = switch0 + switch1 * 2;

	switch (opcode) {
	case 0:
		printf("N is %d, the operation is None\n", n);
		break;

	case 1:
		printf("N is %d, the operation is Addition\n", n);
		break;

	case 2:
		printf("N is %d, the operation is Subtraction\n", n);
		break;

	case 3:
		printf("N is %d, the operation is Multiplication\n", n);
		break;

	default:
		printf("??? error");
		break;
	}

	printf("N is 10, the operation is yyy\n");

	Matrix_Operations(&matrixA, &matrixB, &matrixC, opcode);


	int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };

	int i, j;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d\n", matrix[i][j]);
		}
	}


	while (1) {
	}
	return 0;
}

void Matrix_Operations(int* A, int* B, int* C, int OP) {

	switch (OP) {
	case 0:
		break;

	case 1:
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				C[i][j] = A[i][j] + B[i][j];
			}
		}
		break;
	}

}


