#include "stdio.h"
#include "time.h"

static int  ops = 0;

int Eulers_Algorithm(int a, int b){
  
  ops++;
  
  if (a % b == 0)
    return b;
  
  return Eulers_Algorithm(b,a%b);
}

int main(){
  int a, b, c;
  clock_t start, end ;
  double time_taken;

  puts("Enter The Values Of A and B: ");
  scanf("%d %d",&a, &b);
  
  a = a > b?a:b;
  b = a > b?b:a;

  start = clock();
  
  c = Eulers_Algorithm(a,b);
  
  end = clock();
  
  printf("GCD(%d, %d) = %d\n", a, b, c);
  
  time_taken = (double)(end-start)/CLOCKS_PER_SEC;
  
  printf("No Of Operations : %d\n",ops);
  printf("Time Taken = %lf ms\n",time_taken);

  return 1;
}
