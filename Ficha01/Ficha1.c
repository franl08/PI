#include <stdio.h>
#include <stdlib.h>

/*
 * 1. Estado e Atribuições
 * 
 * 1) 12 16
 * 2) 0 0 (variável y não é inicializada)
 * 3) A 65
 *    B 66 2 50
 *    b 98
 * 4) 100 200
 *
 * 2. Estruturas de Controlo
 *
 * 1)
 *   a) 3 5 (condição Falsa)
 *   b) 11 66 (y = sum(x), x = 1 to 11)
 *   c) _#_#_#_#_#_#_#_#_#_#
 *   d) 1
 *   	01
 *   	11
 *   	001
 *   	101
 *   	011
 *   	111
 *   	0001
 *   	1001
 *   	0101
 *   	1101
 *   	0011
 *   	1011
 *   	0111
 *   	1111
 */

// 3. Programas Iterativos

// 1.
void quadrado(int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			printf("#");
		printf("\n");
	}
}

// 2.
void xadrez(int n){
	for (int i = 0; i < n; i++){
		if (i % 2 == 0)
			for (int j = 0; j < n; j++){
				if (j % 2 == 0) printf("#");
				else printf ("_");
			}
		else
			for (int k = 0; k < n; k++){
				if (k % 2 == 0) printf("_");
				else printf("#");
			}
		printf("\n");
	}
}

