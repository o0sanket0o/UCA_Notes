#include <stdio.h>

int sign(int a){
	return !(!a) | (a >> 31);
}

int main(){
	int n;
	printf("Enter the number:");
	scanf("%d", &n);
	printf("%d\n", sign(n));

	return 0;
}
