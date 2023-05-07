#include<math.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include "leetcode_functions.h"

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
  printf("[");
  for (int i = 0; i < returnSize; i++) {
    printf("%d", spiralReturn[i]);
    if (i < returnSize - 1) {
      printf(", ");
    }
  }
  printf("]\n");

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
  printf("[");
  for (int i = 0; i < returnSize; i++) {
    printf("%d", findBallReturn[i]);
    if (i < returnSize - 1) {
      printf(", ");
    }
  }
  printf("]\n");

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
  printf("before:\n[");
  while(currNode != NULL) {
    printf("%d, ", currNode->val);
    currNode = currNode->next;
  }
  printf("]\n");

  currNode = removeNthFromEnd(theList->head, 3);
  
  printf("before:\n[");
  while(currNode != NULL) {
    printf("%d, ", currNode->val);
    currNode = currNode->next;
  }
  printf("]\n");


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
  

  return 0;
}