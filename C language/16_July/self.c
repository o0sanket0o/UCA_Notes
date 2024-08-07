#include <stdio.h>
#include <time.h>

int main(){
    clock_t start=clock();
    int ans=0;
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            ++ans;
            --ans;
        }
    }
    clock_t end=clock();
    double diff=(double)(start-end)/CLOCKS_PER_SEC;
    printf("%lu\n",diff);
    return 0;
}