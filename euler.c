#include <stdio.h>

//problem 1
int sumMultiples35(int max) {
  int sum = 0;
  int i;
  for (i = 1; i < max; i++) {
    if ((i % 3 == 0) || (i % 5 == 0))
      sum += i;
  }
  return sum;
}

//problem 112
int increasingNumber(int num) {
  //increasing if every digit to left <= digit to right
  int curDig = num % 10;
  while (num / 10) {
    num /= 10;
    int leftDig = num % 10;
    if (leftDig > curDig)
      return 0;
    curDig = leftDig;
  }
  return 1;
}
int decreasingNumber(int num) {
  //decreasing if every digit to left >= digit to right
  int curDig = num % 10;
  while (num / 10) {
    num /= 10;
    int leftDig = num % 10;
    if (leftDig < curDig)
      return 0;
    curDig = leftDig;
  }
  return 1;
}
int isBouncy(int num) {
  return !increasingNumber(num) && !decreasingNumber(num);
}
int leastNumberBouncyPercent(int percent) {
  //keep track of number of bouncy numbers and max number checked
  //the percentage of bouncy is 100 * # of bouncy / max number
  //can be checked as max number * percent == # of bouncy * 100
  
  int numBouncy = 0;
  int maxNum = 1;
  while (maxNum * percent != numBouncy * 100) {
    maxNum++;
    if (isBouncy(maxNum)) {
      numBouncy++;
    }
  }
  //printf("maxNum: %d\tnumBouncy: %d\n", maxNum, numBouncy);
  return maxNum;
}

int main() {
  //printf("%d\n", sumMultiples35(10));
  printf("%d\n", sumMultiples35(1000));
  
  /*
  printf("%d\n", increasingNumber(12));
  printf("%d\n", increasingNumber(21));
  printf("%d\n", decreasingNumber(12));
  printf("%d\n", decreasingNumber(21));
  printf("%d\n", leastNumberBouncyPercent(50));
  */
  printf("%d\n", leastNumberBouncyPercent(99));
  
  return 0;
}
