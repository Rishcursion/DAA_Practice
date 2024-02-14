#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
      ops++;
      i++;
      swap(&array[i],&array[j]);
    }
  }
  swap(&array[i+1],&array[hi]);
  return i+1;
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

void test_case(int times)
{
  for(int i =0;i<times;i++){
    
    int hrange = 500000, lrange = 0;
    
    if(hrange < lrange){
      int temp = hrange;
      hrange= lrange;
      lrange = temp;
    }

    int size = rand()%(hrange- lrange + 1)+lrange;
    int array[size];

    for(int j = 0;j<size;j++)
      array[j] = rand();
   
    clock_t start,end;
    start = clock();
    quicksort(array,0,size-1);
    end = clock();
    printf("\nNo Of Operations: %ld",ops);
    printf("\nTime taken: %e",(double)(end-start)/CLOCKS_PER_SEC);
    printf("\nInput Size (N) = %d\n",size);
    ops = 0;
  }

}

int main(){
  
   srand(time(NULL));
  int times;
  
  printf("Enter No Of Test Cases: ");
  scanf("%d",&times);
  test_case(times);

  return 1;
}
