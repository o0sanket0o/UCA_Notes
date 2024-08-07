#include <stdio.h>
#include <limits.h>
int findPeak(int arr[], int s, int e){
	int mid = e - (e - s ) / 2;
	if(mid - 1 < 0 || mid + 1 >= n) return mid;
	if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
	else if(arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1]) return findPeak(arr, mid + 1, e);
	else if(arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]) return findPeak(arr, s, mid - 1);
	return -1;
}

int reverse(int n){
	int ans = 0;
	while(n){
		int temp = n % 10;
		if((INT_MAX - temp)/ 10 < ans) return 0;
		ans = ans * 10 + temp; 
		n = n / 10;
	}
	return ans;
}
int main(){
	int arr[4] = {0, 10, 5, 2};
	printf("Peak element:", findPeak(arr, 0, 3);
	return 0;
}
