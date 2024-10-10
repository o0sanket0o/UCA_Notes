#include <stdio.h>

long long evenFibSum(int n){
        // code here
	long long sum = 0, prev = 1, curr = 1;
        
        while(prev <= n){
                if(!(prev & 1)) sum += prev;
                int temp = prev + curr;
                prev = curr;
                curr = temp;
        }
	return sum;
}

int main(){
	printf("Enter the max limit:");
	int n;
	scanf("%d", &n);
	printf("Answer is %lld.", evenFibSum(n));
	return 0;
}
