#include <stdio.h>
#include <stdlib.h>

void* custom(int n){
    char *temp = (char *)malloc(n);
    for(int i = 0; i < n ;i++) temp[i] = 0;
    void *ans = (void *) temp;
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    void *ptr = custom(n);
    char *temp = (char *)ptr;
    for(int i = 0; i < n; i++) printf("%d ", temp[i]);
    return 0;
}
