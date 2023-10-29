#include "../headers/removeDupes.h"


int removeDuplicates(int* nums, int numsSize){

  //we receive pointer to array and its length...
  //O(n^2) option
  //traverse array; put non-dupes into the existing array,
  //  increase result size and place non-dupes in the existing memory locations starting at 0...
  //  to evaluate "if a dupe exists", traverse the new length.


  int newSize = 0;

  for (int i = 0; i < numsSize; i++) {
    int isDuplicate = 0;
    
    for (int j = 0; j < newSize; j++) {
      if (nums[i] == nums[j]) {
        isDuplicate = 1;
        break;
      }
    }

    if (!isDuplicate) {
      //not duplicate, add to the list.
      nums[newSize] = nums[i];
      newSize++;
    }
  }


  return newSize;
}

int removeDuplicatesOverTwice(int* nums, int numsSize){

  //we receive pointer to array and its length...
  //O(n^2) option
  //traverse array; put non-dupes into the existing array,
  //  increase result size and place non-dupes in the existing memory locations starting at 0...
  //  to evaluate "if a dupe exists", traverse the new length.

  //sorted arrays could make it O(n), because would only need to check "the other match".


  int newSize = 0;

  for (int i = 0; i < numsSize; i++) {
    int countOfVal = 0;
    
    for (int j = 0; j < newSize; j++) {
      if (nums[i] == nums[j]) {
        countOfVal++;
      }
    }

    //only let 2 duplicates exist.
    if (countOfVal < 2) {
      //not duplicate, add to the list.
      nums[newSize] = nums[i];
      newSize++;
    }
  }


  return newSize;
}