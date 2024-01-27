#include <stdio.h>
#include <time.h>

/*
  int min(int array[], int len){
  int temp = array[0];
  int min_index;
  for(int i =0;i < len; i++){
      if(array[i]<temp){
        temp = array[i];
        min_index = i;
      }
  }
return i;
}*/

void swap(int array [], int i, int j){
  
  int temp = array[i];
  
  array[i] = array[j];
  array[j] = temp;
}

void Selection_Sort(int array [], int len){
  int min;
  
  for(int i =0; i < len ; i++){
    
    min = i;
    
    for(int j = i+1; j < len ; j++){
        
      if(array[j]< array[min])
          min = j;
    }
    swap(array,i,min);
  }
}

void print(int array[], int length){
  
  for (int i =0; i< length; i++)
    
    printf(" %d ", array[i]);
}

int main(void){
  
  int length;
  
  printf("Enter Size Of Array: \n");
  scanf("%d",&length);
  
  int array [length];
  
  for(int i =0;i< length;i++){
    printf("Enter Element %d", i+1);
    scanf("%d", &array[i]);
  }
  
  puts("Before sort: ");
  print(array, length);
  
  Selection_Sort(array,length);
  
  puts("After Sort: ");
  print(array,length);

return 1;
}

