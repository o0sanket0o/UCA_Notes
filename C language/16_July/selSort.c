#include <stdio.h>
#include <assert.h>

void exch(int arr[],int i,int j){
  int temp=arr[i];
  arr[i]=arr[j];
  arr[j]=temp;
}

void sel_sort(int arr[],int n){
  for(int i = 0;i < n;i++){
    int min=i;
    for(int j=i+1;j<n;j++){
      if(arr[j] < arr[min]) min = j;
    }
    exch(arr, i, min);
  }

}
int main()
{
  int arr[]={5, 3, 1, 9, 7};
  printf("Before Sorting:");
  for(int i=0;i<5;i++){
    printf("%d ",arr[i]);
  }
  sel_sort(arr,5);
  printf("\nAfter sorting:");
  for(int i=0; i < 5; i++){
    printf("%d ",arr[i]);
  }
  return 0;
}
