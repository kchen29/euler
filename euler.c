#include <stdio.h>

//problem 1
int sumMultiples35(int max) {
  int sum = 0;
  int i;
  for (i = 1; i < max; i++) {
    if ((i % 3 == 0) || (i % 5 == 0)) {
      sum += i;
      }
  }
  return sum;
}

int main() {
  /*
  int sum10 = sumMultiples35(10);
  printf("%d\n", sum10);
  */
  int sum1000 = sumMultiples35(1000);
  printf("%d\n", sum1000);
  return 0;
}
