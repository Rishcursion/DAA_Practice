#include <stdio.h>
#include <stdlib.h>

long int ops = 0;

void swap(int *i, int *j){
  int temp = *i;
  *i = *j;
  *j = temp;
}


int partition(int *array, int lo, int hi){
  int pivot_index = hi;
  int pivot = array[pivot_index];
  int i = lo - 1 ;
  for (int j = lo ; j < hi ; j++)
  {
    if(array[j] < pivot){
      i++;
      swap(&array[i],&array[j]);
    }
  }
  swap(&array[i+1],&array[hi]);
  return ++i;
}

void quicksort(int *array,int lo, int hi){
  if (lo < hi){
    int pivot_index = partition(array, lo , hi);
    quicksort(array, lo, pivot_index - 1);
    quicksort(array, pivot_index+ 1, hi);
  }
}


void print(int * array, int len){
  for ( int i = 0;i < len ; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main(){
  int array [] = {10,12,24,2,3,4,14,15};
  int lo = 0;
  int hi = 8;
  print(array, hi);
  quicksort(array, lo , hi - 1);
  print(array, hi);
  
}
