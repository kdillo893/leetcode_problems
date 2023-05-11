#include "../headers/removeelement.h"


int removeElement(int* nums, int numsSize, int val){
  
  //edge case, just return 0 if there are no elements in nums
  if (numsSize == 0) {
    return 0;
  }


  //loop through the array "nums" until its size. keep track of "count" for non-vals.
  int count = 0;
  for (int i = 0; i < numsSize; i++) {

    if (nums[i] == val) {
      //I guess just continue? replace the value with 0 or soemthing? nvm.
    } else {
      nums[count] = nums[i];
      count++;
    }
  }

  return count;
}