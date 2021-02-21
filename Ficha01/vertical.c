#include <stdio.h>
#include <stdlib.h>
#include "vertical.h"

void vertical(int n){
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < i; j++)
			printf("#");
		printf("\n");
	}
	for (int k = n - 1; k > 0; k--){
		for (int x = 0; x < k; x++)
			printf("#");
		printf("\n");
	}
}

