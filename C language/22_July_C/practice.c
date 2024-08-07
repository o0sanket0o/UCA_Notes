#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>

int main(){
	struct timeval before;
	gettimeofday(&before, NULL);
	long long first = before.tv_sec * 1000 + before.tv_usec / 1000;
	int ans = 0;
	for(int i = 0; i <= 10000; i++){
		for(int j = 0; j <= 10000; j++){		
			ans += 0;
		}
	}

	struct timeval after;
	gettimeofday(&after, NULL);
	long long second = after.tv_sec * 1000 + after.tv_usec / 1000;
	printf("Time taken is %llums.\n", second - first);
	return 0;
}
