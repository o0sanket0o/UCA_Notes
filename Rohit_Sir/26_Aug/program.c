#include <stdio.h>
#include "first.h"
#include "second.h"

int main(){

	printf("Sum = %d\n", add(20, 10));
	printf("Diff = %d\n", sub(20, 10));
	printf("Mod = %d\n", mod(23, 8));
	printf("Max = %d\n", max(10, 20));
	printf("Min = %d\n", min(10, 20));
	printf("Abs1 = %d\n", absolute(10, 20));
	printf("Abs2 = %d\n", absolute(20, 10));
	printf("Divide = %d\n", div(20, 10));
	printf("Mul = %d\n", mul(10, 20));;
	return 0;

}
