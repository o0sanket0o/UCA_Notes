#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

void swap(int *arr, int i, int j){
	int temp = arr[i]; 
	arr[i] = arr[j];
	arr[j] = temp;
}
void print(int *arr, int n){
	for(int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
}
void quickSort(int *arr, int start, int end, int n){
	if(start >= end) return;
	int pivot = arr[start];
	int i = start + 1, j = start + 1;
	while(j <= end){
		if(arr[j] > pivot) ++j;
		else{
			swap(arr, i, j);
			++i;
			++j;
		}
	}
	swap(arr, start, i - 1);
//	printf("Pivot = %d and array is ", pivot);
//	print(arr, n);
	quickSort(arr, start, i - 2, n);
	quickSort(arr, i, end, n);
}

int main(){
	srand(time(NULL));
	struct timeval before, after;
	gettimeofday(&before, NULL);
	int n = 10000;
	int *arr = (int*) malloc (n * sizeof(int));
	for(int  i = 0; i < n; i++){
		arr[i] = rand() % 20;
	}
//	print(arr, n);
	quickSort(arr, 0, n - 1, n);
	gettimeofday(&after, NULL);
//	print(arr, n);
	long long start = before.tv_sec * 1000 + before.tv_usec / 1000;
	long long end = after.tv_sec * 1000 + after.tv_usec / 1000;
	printf("Time taken to sort the array was:%llums.", end - start);

	return 0;
}
