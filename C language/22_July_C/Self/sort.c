#include <stdio.h>
#include <assert.h>

void swap(int arr[], int i, int j){
  int temp=arr[i];
  arr[i]=arr[j];
  arr[j]=temp;
}

void sort(int arr[],int n){
  for(int i = 0; i < n; i++){
    int min= i;
    for(int j = i + 1; j < n; j++){
      if(arr[j]<arr[min]){
	min=j;
      }
    }
    swap(arr,i,min);
  }	
}


int main(){
  int arr[]={9,1,7,3,5};
//  printf("Array before sorting:");
//  for(int i = 0; i < 5; i++){
//    printf("%d ",arr[i]);
//  }
  sort(arr,5);
//  printf("\nArray after sorting:");
//  for(int i = 0; i < 5; i++){
//    printf("%d ",arr[i]);
//  }
  int exp[]={1,3,5,7,9};
  for(int i = 0; i < 5; i++){
    assert(arr[i]==exp[i]);
  }
  return 0;
}
