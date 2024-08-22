#include <stdio.h>

int invert(int num, int pos, int n){
	int y = -1;
	int rem = 32 - n;
	y = y << (n + pos - 1);
	y = ~y;
	printf("%d\n", y);
	y = y >> (pos - 1);
        y = y << (pos - 1);	
	printf("%d\n", y);
	return y ^ num;
}


int main(){
	int num;
	printf("Enter the number:");
	scanf("%d", &num);
	int n, pos;
	printf("Enter position and number of bits:");
	scanf("%d %d", &pos, &n);
	printf("%d\n",invert(num, pos, n));


			return 0;
			}
