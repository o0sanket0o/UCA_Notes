#include <stdio.h>
#include <stdbool.h>

bool check(int i, int j, int n, int m){
	return i < n && j < m;
}

int findMaxSum(int *arr, int i, int j, int n, int m){
	if(i == n - 1 && j == m - 1) return *((arr + i * n) + j) ;
	if(i >= n || j >= m) return 0;
	int ans = *((arr + i * n) + j);
	bool first = check(i + 1, j, n, m);
	bool second = check(i, j + 1, n, m);
	if(first && second){
		int one = findMaxSum(arr, i + 1, j, n, m);
        	int two = findMaxSum(arr, i, j + 1, n, m);
		int bestChoice = one < two ? one : two;
		return bestChoice + ans;
	}
	if(first){
		int one = findMaxSum(arr, i + 1, j, n, m);
		return one + ans;
	}
	int two = findMaxSum(arr, i, j + 1, n, m);
	return ans + two;
};


int main(){
	int rows, cols;
	printf("Enter the number of rows and columns:");
	scanf("%d %d", &rows, &cols);
	int arr[rows][cols];
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			int val;
			scanf("%d", &val);
			arr[i][j] = val;
		}
	}
	printf("%d", findMaxSum((int *)arr, 0, 0, rows, cols));
	return 0;
}
