#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
  srand(time(NULL));
  printf("The numbers are:\n");
  for(int i = 0; i < 5; i++){
    printf("%d ",rand());
  }
  return 0;
}
