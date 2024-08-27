#include <stdio.h>

void printPaths(int i, int j, int n, int m){
	if(i == n - 1 && j == m - 1){
		printf("%d %d\n", i, j);
		return;
	}
	if(i >= n || j >= m) return;
	printf("%d %d-->",i, j);
	printPaths(i + 1, j, n, m);
	printPaths(i, j + 1, n, m);
}

int main(){
	printPaths(0, 0, 3, 3);
	return 0;
}

