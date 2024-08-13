#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main(){
struct rusage before, after;
getrusage(RUSAGE_SELF, &before);
int *arr = (int*) malloc (10000*sizeof(int));
getrusage(RUSAGE_SELF, &after);

printf("The difference in the memory is %lukb.", after.ru_maxrss - before.ru_maxrss);

return 0;
}
