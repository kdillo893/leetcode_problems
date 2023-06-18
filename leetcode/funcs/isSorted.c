#include "../headers/isSorted.h"

int isSorted(int * nums, int numsSize) {

  //arrays of size 0 or 1 are always "sorted"
  if (numsSize == 1 || numsSize == 0) {
    return 1;
  }

  int isSorted = 1;
  for (int i = 0; i < numsSize-1; i++) {
    if (nums[i] > nums[i+1]) {
      isSorted = 0;
      break;
    }
  }

  return isSorted;
}