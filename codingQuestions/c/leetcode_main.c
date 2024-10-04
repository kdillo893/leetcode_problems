#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<assert.h>

//user defined header functions (containing solutions)
#include "headers/findball.h"
#include "headers/helpers.h"
#include "headers/isSorted.h"
#include "headers/ishappynum.h"
#include "headers/longcommonprefix.h"
#include "headers/multiplystrings.h"
#include "headers/removeDupes.h"
#include "headers/removeNthFromEnd.h"
#include "headers/removeelement.h"
#include "headers/spiralorder.h"
#include "headers/mergesort.h"
#include "headers/mergestrings.h"

//TODO: move the test functions into separate folder for tests, have a test execution

void happyNumTest() {
  int n = 19;
  int happy = isHappy(n);

  printf("%d is %s\n", n, happy ? "true" : "false");
}

void spiralTest() {

  //define the "pointer to pointers", which would be the array of arrays.
  int **matrix;
  int matrixSize = 3;
  matrix = malloc(sizeof(*matrix) * matrixSize);
  
  int colSize = 3;

  //start value, these will be what we write to arrays.
  int val = 1;

  //we allocated pointers to arrays (this is matrix), now allocate the arrays.
  for (int row = 0; row < matrixSize; row ++) {
    matrix[row] = (int*) malloc(colSize * sizeof(int));
    //as we allocate rows, write them?
    for (int col = 0; col < colSize; col++) {
      matrix[row][col] = val++;
    }
  }

  
  int returnSize = -1;
  int* spiralReturn = spiralOrder(matrix, matrixSize, &colSize, &returnSize);

  //print the array...
  printIntArray(spiralReturn, returnSize);

  free(spiralReturn);

  //free the arrays that we created for the problem
  for (int row = 0; row < matrixSize; row ++) {
    free(matrix[row]);
  }
  free(matrix);
}

void findBallTest() {

  //define the "pointer to pointers", which would be the array of arrays.
  int **grid;
  int gridSize = 3;
  grid = malloc(sizeof(*grid) * gridSize);
  
  int colSize = 5;

  //make a seed for randomization.
  time_t t;
  srand((unsigned) time(&t));

  //we allocated pointers to arrays (this is grid), now allocate the arrays.
  for (int row = 0; row < gridSize; row ++) {
    grid[row] = (int*) malloc(colSize * sizeof(int));
    
    //as we allocate rows, decide +/-1 off random number from seed.
    for (int col = 0; col < colSize; col++) {


      grid[row][col] = 2 * (rand() % 2) - 1;
    }
  }

  //print the sample grid:
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < colSize; j++) {
      printf("%c", grid[i][j] > 0 ? '/' : '\\');
    }
    printf("\n");
  }

  
  int returnSize = -1;
  int* findBallReturn = findBall(grid, gridSize, &colSize, &returnSize);

  //print the array...
  printIntArray(findBallReturn, returnSize);

  free(findBallReturn);

  //free the arrays that we created for the problem
  for (int row = 0; row < gridSize; row ++) {
    free(grid[row]);
  }
  free(grid);
}

void longestCommonPrefixTest() {
  //string array...

  char** words;
  int wordcount = 3;

  words = malloc(wordcount * sizeof(char*));
  
  words[0] = "flow";
  words[1] = "flower";
  words[2] = "flippant";


  char* result = longestCommonPrefix(words, wordcount);

  //print the "words" array to see if it was destructive, then also print the result..
  printf("result=%s, ", result);
  char wordslisting[600];
  sprintf(wordslisting, "[%s, %s, %s]", words[0], words[1], words[2]);
  printf("words=%s", wordslisting);
  

  free(words);
  free(result);
}

void multiplyStringsTest() {

  //strings to multiply
  char* num1="123";
  char* num2="456";

  char* product = multiply(num1, num2);

  printf("%s * %s = %s\n\n", num1, num2, product);
  
}

void removeNthFromEndTest() {
  //put the type into node_t, makes it easier to reference.
  typedef struct ListNode node_t;

  //prep...
  typedef struct {
    node_t * head;
  } int_list;

  int_list* theList = (int_list *) malloc(sizeof(int_list));
  theList->head = NULL;
  
  //initializing list...
  node_t * priorNode = NULL;
  for (int i = 0; i < 5; i++) {
    node_t *currNode = NULL;
    currNode = (node_t *) malloc(sizeof(node_t));
    currNode->next = NULL;
    currNode->val = i;

    //if no head, put this as the head, otherwise update prior node.
    if (priorNode == NULL) {
      theList->head = currNode;
    } else {
      priorNode->next = currNode;
    }
    priorNode = currNode;
  }

  //before:
  node_t* currNode = theList->head;
  printf("before:\n");
  printLinkedList(currNode);

  currNode = removeNthFromEnd(theList->head, 3);
  
  printf("after:\n");
  printLinkedList(currNode);
}

void mergeSortTest() {

  int nums1Size = 10;
  int nums2Size = 5;
  int nums1Len = 5;
  int nums2Len = 5;
  int nums1[10] = { 4, 5, 8, 9, 10, 0,0,0,0,0};
  int nums2[5] = { 1, 2, 3, 6, 7};

  printf("[4,5,8,9,10] with [1,2,3,6,7]:\n");
  merge(nums1, nums1Size, nums1Len, nums2, nums2Size, nums2Len);
  
  printIntArray(nums1, nums1Size);

  int nums3Size = 12;
  int nums4Size = 9;
  int nums3Len = 3;
  int nums4Len = 9;
  int nums3[12] = {1,2,3,0,0,0,0,0,0,0,0,0};
  int nums4[9] = {4,5,6,7,8,9,10,11,12};

  printf("[1,2,3] with [4,5,6,7,8,9,10,11,12]:\n");
  merge(nums3, nums3Size, nums3Len, nums4, nums4Size, nums4Len);
  
  printIntArray(nums3, nums3Size);


  return;
}

void mergeStringsAlternatelyTest() {

  char * str1 = "bigclock";
  char * str2 = "rivers";

  printf("%s with %s:\n", str1, str2);
  char* result1 = mergeAlternately(str1, str2);
  
  printf("result: %s", result1);

  //free the arrays returned
  free(result1);

  return;
}

void removeDuplicatesTest() {
  int numsSize = 20;
  int nums[20] = {5,6,3,2,3,4,7,8,1,2,4,8,12,4,322,134,90,5675,7,345}; // Input array
  int expectedNumsSize = 14;
  int expectedNums[14] = {5,6,3,2,4,7,8,1,12,322,134,90,5675,345}; // The expected answer with correct length

  int k = removeDuplicates(nums, numsSize); // Calls your implementation

  assert(k == expectedNumsSize);
  // printf("returningArraySize=%d; expectedSize=%d\n", k, expectedNumsSize);

  for (int i = 0; i < k; i++) {
      // printf("@%d: op=%d, expect=%d\n", i, nums[i], expectedNums[i]);
      assert(nums[i] == expectedNums[i]);
  }
}


void removeElementTest() {
  
  //removing elements with that value, not the index.

  int arrSize = 12;
  int arr[12] = {45,212,3242,1234,4324,45,6778,56785,234,5454,1212, 9999};
  int expectedResSize = 10;
  int expectedRes[10] = {212,3242,1234,4324,6778,56785,234,5454,1212, 9999};


  //removing idx 5.
  int resSize = removeElement(arr, arrSize, 45);
  printf("returningArraySize=%d; expectedSize=%d\n", resSize, expectedResSize);
  assert(expectedResSize == resSize);

  for (int i = 0; i < resSize; i++) {
      printf("@%d: op=%d, expect=%d\n", i, arr[i], expectedRes[i]);
      assert(arr[i] == expectedRes[i]);
  }

}

void isSortedTest() {
  int arr1Size = 5;
  int arr1[5] = {1,2,3,4,5};
  assert(isSorted(arr1, arr1Size));

  int arr2Size = 5;
  int arr2[5] = {5,4,3,2,1};
  assert(!isSorted(arr2, arr2Size));

  int arr3Size = 0;
  int arr3[0] = {};
  assert(isSorted(arr3, arr3Size));
  int arr4Size = 1;
  int arr4[1] = {12313};
  assert(isSorted(arr4, arr4Size));

  int arr5Size = 9;
  int arr5[9] = {924,1234,4323,5123,12323,23422,43242,242424,262323};
  assert(isSorted(arr5, arr5Size));
}


int main() {

  printf("HappyNum test:\n\n");
  happyNumTest();
  printf("\n");
  
  printf("Spiral test:\n\n");
  spiralTest();
  printf("\n");
  
  printf("FindBall test:\n\n");
  findBallTest();
  printf("\n");

  printf("LongestCommonPrefix test:\n\n");
  longestCommonPrefixTest();
  printf("\n\n");

  printf("MultiplyStrings test:\n\n");
  multiplyStringsTest();
  printf("\n");

  printf("RemoveNthFromEnd test:\n\n");
  removeNthFromEndTest();
  printf("\n");
  
  printf("MergeSort test:\n\n");
  mergeSortTest();
  printf("\n");

  printf("MergeStringsAlternately test:\n\n");
  mergeStringsAlternatelyTest();
  printf("\n");

  printf("RemoveDupes test:\n\n");
  removeDuplicatesTest();
  printf("\n");
  
  printf("RemoveElement test:\n\n");
  removeElementTest();
  printf("\n");

  printf("IsSorted test:\n\n");
  isSortedTest();
  printf("\n");
  

  return 0;
}