#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
void merge(int arr[], int* aux, int s, int mid, int e){
	for(int i = s; i <= e; i++) aux[i] = arr[i];
	int i = s, j = mid + 1;
	for(int a = s; a <= e; a++){
		if(i > mid) arr[a] = aux[j++];
		else if(j > e) arr[a] = aux[i++];
		else if(aux[j] < aux[i]) arr[a] = aux[j++]; 
		else arr[a] = aux[i++];
	}

}

void mergeSort(int arr[], int* aux, int s, int e){
	if(s >= e) return;
	int mid = s + (e - s) / 2;
	mergeSort(arr, aux, s, mid);
	mergeSort(arr, aux, mid + 1, e);
	merge(arr, aux, s, mid, e);
}
int main(){
	srand(time(NULL));
	int n = rand() % 10 + 1;
	int arr[n];
	for(int i = 0; i < n; i++){
		arr[i] = rand() % 100;
	}
	printf("Before sorting:");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	int *aux = (int*) malloc (n * sizeof(int));
	mergeSort(arr, aux, 0, n - 1);
	printf("\nAfter sorting:");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	free(aux);
	return 0;
}
