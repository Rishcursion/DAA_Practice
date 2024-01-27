#include <stdio.h>
#include <time.h>

static int operations = 0;

void swap(int array[], int i, int j){
  operations++;
  int temp = array[i];
  
  array[i] = array[j];
  
  array[j] = temp;
}

void bubble_sort(int array[], int len){
  
  for (int i = 0; i < len; i++){
    
    for (int j = i+1;j<len;j++){
      
      if(array[j]<array[i])
        
        swap(array,i,j);
    }
  }
}

void print(int array[], int len){
  for (int i =0;i<len; i++)
    printf("%d ",array[i]);
  printf("\n");
}

int main(){
    int length;

    puts("Enter Length Of Array To Be Sorted: ");
    scanf("%d",&length);
    
    int array[length];
    
    for(int i = 0; i< length;i++){
      printf("Enter Element %d: \n", i+1);
      scanf("%d",&array[i]);
    }
    puts("Array Before Sort: ");
    print(array, length);

    bubble_sort(array, length);
    puts("Array After Sort: ");
    print(array, length);
    printf("\nNo Of Operations = %d ", operations);
    return 1;
}
