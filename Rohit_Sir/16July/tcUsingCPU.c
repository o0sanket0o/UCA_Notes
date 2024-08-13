#include <stdio.h>
#include <time.h>

int main(){
	clock_t start, end;
	double diff;
	start = clock();
	int a = 10;
	for(int i = 0; i < 10000; i++){
		for(int j = 0; j < 10000; j++){
			a++;
		}
	}
	end = clock();
	printf("Initial value of clock cycle is %lu.\n", start);
	printf("Final value of clock cycle is %lu.\n", end);
	printf("Value of clock cycles is %lu.\n", CLOCKS_PER_SEC);
	diff = end - start;
	double tt = (diff * 1.0) / CLOCKS_PER_SEC;
	printf("Time taken by the program is %lfs", tt);

	return 0;
}
