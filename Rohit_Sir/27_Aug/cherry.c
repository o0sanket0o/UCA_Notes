#include <stdio.h>
#include <limits.h>

int findMax(char arr[][], int i, int j, int n, int m, int dp[][]){
	if(i == n - 1 && j == m - 1) return 0;
	if(i >= n || j >= m || arr[i][j] == 'X') return INT_MAX;
	if(dp[i][j] != -1) return dp[i][j];
	int ans = 0;
	if(arr[i][j] == '1') ++ans;
	ans = max(ans, findMax(arr, i + 1, j, n, m));
	ans = max(ans, findMax(arr, i, j + 1, n, m));
	return dp[i][j] = ans;
}

int main(){
	char arr[4][4] = {{'1', '0', 'X', 'X'}, {'1', '0', '1', 'X'}, {'X', 'X', '1', '1'}, {'X', 'X', '1', '1'}};
	int dp[4][4] = {{-1, -1, -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}};
	printf("%d\n", findMax(arr, 0, 0, 4, 4, dp);
	return 0;
}
