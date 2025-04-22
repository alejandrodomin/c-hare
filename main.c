#include <stdio.h>
#include <time.h>

void* gen_data(long int);

int main() {
  // 10 000 000 000
  time_t start, end;

  time(&start);
  gen_data(10000000000); 
  time(&end);

  double elapsed = difftime(end, start);

  printf("Generated 10 billion items in %f seconds at a rate of %e/s\n", 
         elapsed, 10000000000/elapsed);

  return 0;
}

void* gen_data(long int upper_bound) {
  time_t start, end;
  time(&start);

  long int i = 0;
  for(i; i < upper_bound; i++) {
    
    if (i % 10000 == 0) {
      time(&end);

      double seconds = difftime(end, start);
      double items_hz = i / seconds;

      printf("Generating item %ld of %ld [%es]\r", 
             i, upper_bound, items_hz);
    }
  }
}
