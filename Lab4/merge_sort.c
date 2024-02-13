#include "stdio.h"
#include "time.h"
#include <stdlib.h>

int ops = 0;

void merge(int array[], int low, int mid, int high){
  int left = mid - low + 1;
  int right = high - mid;
  int lowpart[left];
  int hipart[right];

  int i = 0, j = 0 , k = 0;

  for( i; i < left; i++){
    lowpart[i] = array[low + i];
  }

  for (j ; j < right; j++ ){
    hipart[j] = array[mid + j + 1];
  }
   i = j = 0;
   k = low;
  while(i < left && j < right){
    if (lowpart[i] < hipart[j]){
      ops++;
      array[k] = lowpart[i++];
    }
    else {
      ops++;
      array[k] = hipart[j++];
    }
    k++;
  }

  while (i < left)
    array[k++] = lowpart[i++];
  while (j < right)
    array[k++] = hipart[j++];
}


void mergesort(int array[], int low, int high){

  if (low < high){
    
    int mid = (high + low)/2;
    
    mergesort(array, low, mid);
   
    mergesort(array, mid + 1, high);
    
    merge(array, low, mid, high);
  }
}

void print(int array[],int len){
  int i;
  for(i = 0; i< len ; i++){
    printf("%d ",array[i]);
  }
  printf("\n");
}

int main(void)
  {
    clock_t start, end;
    double time;
    
    start = clock();
    
    int array [] = {876, 1969, 1301, 514, 638, 1956, 1328, 1643, 1283, 375, 1417, 422, 1712, 1374, 1182, 59, 1038, 1158, 1789, 55};
    print(array,10);
    int low = 0,high = 10;

    mergesort(array,low,high-1);

    end = clock();
    print(array,high);
    time = (double) (end - start) / CLOCKS_PER_SEC;

    printf("\nNo Of Operations: %d",ops);
    printf("\nTime Taken: %lf",time);
    
    return 1;

  }


