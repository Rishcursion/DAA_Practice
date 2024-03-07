#include <stdio.h>
#include "stdlib.h"
#include <time.h>

#define N 100

int ops = 0;
int weights[N];
int values[N];

int max(int a,int b){
  return a<b?b:a;
}

int dfs(int i, int capacity){
  if(i == 0)
    return 0;
  if (capacity - weights[i] < 0){
    ops++;
    return dfs(i-1,capacity);
  }
  
  int valid = values[i] + dfs(i-1,capacity - weights[i]);
  int invalid = dfs(i-1,capacity);
  
  return max(valid,invalid);
}


void test(int n){

  while(n!=0){
    srand(clock());
    int input_size = rand()%(10) + 2;
    int capacity = rand()%25 + 5;
    for( int j = 0; j < input_size;j++){
      weights[j] = rand()%capacity + 2;
      values[j] = rand()%50 + 10;
    }
    ops = 0;
    clock_t start = clock();
    int best_val = dfs(input_size, capacity);
    clock_t end = clock();
    printf("\n_______________\nInput Size : %d",input_size);
    printf("\nOp Count : %d\n",ops);
    printf("Time Taken : %lf\n",(double)(end-start)/CLOCKS_PER_SEC); 
    puts("___________________");
    n--;
  }
}

void main(void){
  int test_cases;
  puts("Enter No Of Test Cases: ");
  scanf("%d",&test_cases);
  test(test_cases);
}
