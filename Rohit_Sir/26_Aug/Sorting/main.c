#include <stdio.h>
#include "custom.h"
#include <time.h>
#include <stdlib.h>
int main(){

	int n = 9;
	int* arr = (int*) malloc (n * sizeof(int));
	srand(time(NULL));
	for(int i = 0; i < 9; i++){
		arr[i] = rand() % 20;
	}
	int *aux = (int*) malloc (n * sizeof(int));
	print(arr, n);
//	mergeSort(arr, aux, 0, n - 1);
//	quickSort(arr, 0, n - 1, n);
	selSort(arr, n);
	print(arr, n);

	return 0;
}
