#include <stdio.h>

void print(int* arr, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

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

void swap(int *arr, int i, int j){
	int temp = arr[i]; 
	arr[i] = arr[j];
	arr[j] = temp;
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

void selSort(int arr[], int n){
	for(int i = 0; i < n; i++){
		int index = i;
		for(int j = i + 1; j < n; j++){
			if(arr[index] > arr[j]) index = j;
		}
		swap(arr, i, index);
	} 

}
