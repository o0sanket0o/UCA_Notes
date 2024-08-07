#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>

void swap(int arr[], int i, int j){
  int temp=arr[i];
  arr[i]=arr[j];
  arr[j]=temp;
}

void sort(int arr[],int n){
  for(int i = 0; i < n; i++){
    int min=i;
    for(int j = i + 1; j < n; j++){
      if(arr[j]<arr[min]){
	min=j;
      }
    }
    swap(arr,i,min);
  }	
}


long long timeTaken(int n){
  int* arr=(int *) malloc (n* sizeof(int));
  srand(time(NULL));
  for(int i = 0; i < n; i++){
    arr[i]=rand();
  }
  struct timeval before;
  gettimeofday(&before,NULL);
  long long before_time=before.tv_sec*1000ll+before.tv_usec/1000;
  sort(arr,n);
  struct timeval after;
  gettimeofday(&after,NULL);
  long long after_time=after.tv_sec*1000ll+after.tv_usec/1000;
  long long tt=after_time-before_time;
  return tt;
}

int main(){
  long long t1=timeTaken(5000);
  long long t2=timeTaken(10000);
//  printf("Time taken is %llu milliseconds",t1);
  printf("The ratio of times is:%lf",t2*1.0/t1);
  return 0;
}
