#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>

void swap(int arr[], int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void sort(int arr[], int n){
	for(int i = 0; i < n; i++){
		int index = i;
		for(int j = i + 1; j < n; j++){
			if(arr[index] > arr[j]) index = j;
		}
		swap(arr, i, index);
	} 

}
long long find(int n){
	int arr[n];
	struct timeval before;
        gettimeofday(&before, NULL);
        srand(time(NULL));
	for(int i = 0; i < n; i++) arr[i] = rand();
        sort(arr, n);
        struct timeval after;
        gettimeofday(&after, NULL);
        long long first = before.tv_sec * 1000 + before.tv_usec / 1000;
        long long sec = after.tv_sec * 1000 + after.tv_usec / 1000;
        long long diff = sec - first;
	return diff;
}
int main(){
	long long t1 = find(10000);
	long long t2 = find(5000);
	double ratio = (t1 * 1.0) / t2;
	printf("Ratio of time taken is %lf", ratio);	
	return 0;
}
