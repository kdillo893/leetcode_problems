#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};


int* findBall(int **grid, int gridSize, int *gridColSize, int *returnSize);
int isHappy(int n);
char* longestCommonPrefix(char **strs, int strsSize);
char* multiply(char * num1, char * num2);
struct ListNode* removeNthFromEndV1(struct ListNode* head, int n);
struct ListNode* removeNthFromEndV2(struct ListNode* head, int n);
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);

int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize);

/**
 * this is the source of the question:
 * https://leetcode.com/problems/where-will-the-ball-fall/?envType=study-plan&id=level-2
 *
 * Note: The returned array must be malloced, assume caller calls free().
 * MyNote: based on the input samples, this would be more efficient with
 * datatypes like bool or uint8_t.
 */
inline int *findBall(int **grid, int gridSize, int *gridColSize, int *returnSize) {
  // guard clauses,
  //   no grids no balls.
  if (gridSize <= 0) {
    *returnSize = 0;
    return NULL;
  }

  // basic prep the array and loop for checking the grid.
  int rows = gridSize;
  int cols = gridColSize[0];

  // if cols = 0, no balls can drop;
  if (cols == 0) {
    *returnSize = 0;
    return NULL;
  }

  // return is number of balls dropped from top (just the columns width)
  *returnSize = cols;
  int *returnBall = (int *)calloc(*returnSize, sizeof(int));

  // if the column size is 1, always stuck
  if (cols == 1) {
    returnBall[0] = -1;
    return returnBall;
  }

  // set up ball positions:
  for (int col = 0; col < cols; col++) {
    returnBall[col] = col;
  }

  // Evaluating the squares which we pass through by pairs...
  // going through rows would be n, columns would be m. O(n*m)
  //  Tracking balls? array would be the "returnBall" array...
  //   at any point all are -1, return.
  // iterate through, i'th row
  //  3m for evaluating row, tracking balls, and checking adjacent.

  bool hasBalls = 1;
  int *theRow;
  int theSlope;

  for (int row = 0; row < rows && hasBalls; row++) {
    theRow = grid[row];

    // move through the row, evaluate where the ball is angle of the box for the
    // row, then where it goes down next row.
    for (int col = 0; col < cols; col++) {
      // if this ball is -1, move on.
      int theBallLoc = returnBall[col];
      if (theBallLoc == -1)
        continue;

      // we have ball, where it is evaluate +/-
      theSlope = theRow[theBallLoc];
      if (theSlope > 0) {
        // 1 means bump right.
        // if current loc is cols-1 or adjacent location has slope 1, we get
        // stuck
        if (theBallLoc == cols - 1 || theRow[theBallLoc + 1] < 0) {
          returnBall[col] = -1;
        } else {
          returnBall[col]++;
        }
      }
      if (theSlope < 0) {
        //-1 means bump left.
        // if current loc is 0, OR the location behind has slope -1, we get
        // stuck
        if (theBallLoc == 0 || theRow[theBallLoc - 1] > 0) {
          returnBall[col] = -1;
        } else {
          returnBall[col]--;
        }
      }
    }

    // end of for, check if we still have balls.
    hasBalls = 0;
    for (int col = 0; col < cols; col++) {
      if (returnBall[col] > -1) {
        hasBalls = 1;
        break;
      }
    }
  }

  return returnBall;
}

/**
 * Compute wehther the number is happy (sums of digits squared, do they converge
 * to "1")
 */
inline int isHappy(int n) {

  if (n <= 0)
    return 0;

  // number iteration
  while (n != 1) {
    // how do I get the digit? mod 10, divide by 10, repeat.

    int sum = 0;
    while (n > 0) {
      int rem = n % 10;
      sum += rem * rem;

      n = n / 10;
    }

    n = sum; //(new num)

    // sum results that loop?
    //  1 = done
    //  2 -> 4 -> 16 -> 37 -> 58 -> 89 -> (64+81)=145 -> 16+25+1=42 -> 20 ..
    //  see 2. 3 -> 9 -> 81 -> 65 -> 36+25=61 -> 37 .. (see 2's loop) 4, see 2's
    //  loop 5 -> 25 -> 29 -> 85 -> 25+64=89... see 2's loop 6 -> 36 -> 45 -> 41
    //  -> 17 -> 50 7 -> 49 -> 16+81=97 -> 81+49=130 -> 10 -> 1...
    //

    if (n == 1)
      break;
    if (n == 37)
      break;
    if (n == 89)
      break;
    if (n == 17)
      break;
  }

  return n == 1;
}

/**
 * return string (char ptr) of the longest common prefix for the passed array of
 * string pointers.
 */
inline char *longestCommonPrefix(char **strs, int strsSize) {
  // guard clauses:
  //   no words, no common.
  if (strsSize <= 0) {
    char *empty = (char *)malloc(sizeof(char));
    empty[0] = '\0';
    return empty;
  }
  //  one word, only common with itself.
  if (strsSize == 1) {
    return strs[0];
  }

  // find the shortest string, that way we can malloc only the length of the
  // shortest string.
  //  the way to do this without a string library is to go by index and loop
  //  over the "strs" outer arrays until one of them is '\0'
  int maxidx = 200;
  for (int idx = 0; idx < 200; idx++) {
    int found = 0;
    for (int word = 0; word < strsSize; word++) {
      if (strs[word][idx] == '\0') {
        found = 1;
        break;
      }
    }

    if (found) {
      maxidx = idx;
      break;
    }
  }

  // there is a word that's empty, return empty.
  if (maxidx == 0) {
    char *empty = (char *)malloc(sizeof(char));
    empty[0] = '\0';
    return empty;
  }

  // evaluate character matches
  char *firstWord = strs[0];
  for (int wnum = 1; wnum < strsSize; wnum++) {
    char *word = strs[wnum];

    for (int letter = 0; letter < maxidx; letter++) {
      if (word[letter] != firstWord[letter]) {
        // set the nulloc and common letter location to NUL val.
        maxidx = letter;
        break;
      }
    }

    if (maxidx == 0) {
      char *empty = (char *)malloc(sizeof(char));
      empty[0] = '\0';
      return empty;
    }
  }

  // copy the letters of the first word up to maxidx
  char *common = (char *)malloc((maxidx + 1) * sizeof(char));
  common[maxidx] = '\0';
  for (int idx = 0; idx < maxidx; idx++) {
    common[idx] = firstWord[idx];
  }

  return common;
}

/**
 * multiply strings which represent numbers. Don't use any "int parsing" libraries or multiplying by using ints.
 */
inline char * multiply(char * num1, char * num2) {

  //edge cases:
  // either of the strings are null:
  if (num1[0] == '\0' || num2[0] == '\0') {
    return NULL;
  }

  // one of the strings is "0"
  if (num1[0] == '0' || num2[0] == '0') {
    char* zerostring = (char*) malloc(2 * sizeof(char));
    zerostring[0] = '0';
    zerostring[1] = '\0';
    return zerostring;
  }

  // one of the strings is exactly "1", return the opposite.
  if (num1[0] == '1' && num1[1] == '\0') {
    return num2;
  }
  if (num2[0] == '1' && num2[1] == '\0') {
    return num1;
  }
  //end edge cases

  //what is the length of each number? run through them until we see '\0'
  //could do this in one loop, but easier to read this way.
  int len1 = 0;
  for (len1 = 0; num1[len1] != '\0' ; len1++) {
    //nothing inside needed really.
  }
  int len2 = 0;
  for (len2 = 0; num2[len2] != '\0' ; len2++) {
    //nothing inside needed really.
  }

  //len1 is length of num1, len2 is length of num2 (all characters minus NULL which terminates.)
  //what is multiplcation? length of one is extended by the other. (eg 900 * 900 - 810000, 3dig * 3dig => 6 dig.)
  char* product = (char*) malloc((len1+len2+1) * sizeof(char));
  product[len1+len2] = '\0';

  //how do I multiply characters? "add together". when iterating through, go for one string, multiply the "int" equivalent of the chars,
  // then add to the "array" for tracking digits.
  int productAsInts[len1+len2];
  //initialize all as 0
  for (int i = 0; i < len1+len2; i++) {
    productAsInts[i] = 0;
  }

  //char value for "0123456789" starts at 48

  for (int idx1 = 0; idx1 < len1; idx1++) {
    //iterating over the first word, starting at one's place...
    int idx1Val = (int) num1[idx1] - 48;
    // printf("num1 @10^%d: %d\n", len1-1-idx1, idx1Val);

    //0 for the index, don't sum.
    if (idx1Val == 0) continue;

    for (int idx2 = 0; idx2 < len2; idx2++) {
      //evaluate "what to add per index."
      int idx2Val = (int) num2[idx2] - 48;
      // printf("num2 @10^%d: %d\n", len2-1-idx2, idx2Val);

      if (idx2Val == 0) continue;


      productAsInts[idx2+idx1+1] += idx1Val*idx2Val;

      // printf("theArray: \n [");
      // for (int i = 0 ; i < len1+len2; i++) {
      //   printf("%d, ", productAsInts[i]);
      // }
      // printf("]\n");

    }
  }

  //we have the "asInts" array filled, now convert to char array.
  for (int i = len1+len2-1; i >=0; i--) {
    int val = productAsInts[i];
    //as I go through, how does this look?
    int digval = val % 10;
    int carry = val / 10;

    // printf("val=%d, dig=%d, carry=%d\n", val, digval, carry);
    product[i] = (char) digval + 48;
    if (i > 0) {
      productAsInts[i-1]+= carry;
    }

    // printf("%s, %d'th=%d, carry=%d\n", product, len1+len2-i, digval, carry);
  }

  //fix: if the product has leading 0, move everything.
  if (product[0] == '0') {
    for (int i = 0; i < len1+len2; i++) {
      product[i] = product[i+1];
    }
  }

  return product;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
inline struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  return removeNthFromEndV1(head, n);
  // return removeNthFromEndV2(head, n);
}

inline struct ListNode* removeNthFromEndV1(struct ListNode* head, int n) {
  //edge cases: 
  //  null pointer for the head.
  if (head == NULL) {
    return NULL;
  }
  
  //find the length of the list.
  int length = 0;
  struct ListNode * currNode = head;
  while(currNode != NULL) {
    currNode = currNode->next;
    length++;
  }

  //n is "nth from end", not index.
  //n = 1 means "last node", n = 2 means "2nd to last", etc.
  //n = length means (first node); anything greater is out of bound, just return original.
  if (n > length) {
    return head;
  }

  if (n == length) {
    return head->next;
  }

  //removing the N'th; this is effectively the "ith" node.
  currNode = head;
  struct ListNode * prevNode;

  //use n to trace through, no need for a new variable.
  //process:
  // - removing n'th node, the previous node's "next" would need to go to the one after the removed node.
  for(int i = 0 ; i < length - n; i++) {
    prevNode = currNode;
    currNode = currNode->next;
  }

  //currNode is the one to remove.
  prevNode->next = currNode->next;
  free(currNode);

  return head;
}

inline struct ListNode* removeNthFromEndV2(struct ListNode* head, int n) {
  //edge cases: 
  //  null pointer for the head.
  if (head == NULL) {
    return NULL;
  }
  
  //find the length of the list.
  int length = 0;
  struct ListNode * currNode = head;
  struct ListNode * nthBeforeEnd = NULL;
  struct ListNode * priorToNthBeforeEnd = NULL;
  while(currNode != NULL) {
    currNode = currNode->next;
    length++;

    if (length - n >= 0) {
      if (nthBeforeEnd == NULL) {
        nthBeforeEnd = head;
      } else {
        priorToNthBeforeEnd = nthBeforeEnd;
        nthBeforeEnd = nthBeforeEnd->next;
      }
    }
  }

  //alernate: instead of going through the list twice (one for length, one for node removal),
  //  can instead trace "length - n" spaces before the current node as it traverses.
  //  

  //n before end out of bounds, just return head
  if (nthBeforeEnd == NULL || length < n) {
    return head;
  }

  //if they're the same, just move head->next
  if (nthBeforeEnd == head) {
    return head->next;
  }

  //none of the edge cases, move the node then return head.
  priorToNthBeforeEnd->next = nthBeforeEnd->next;
  free(nthBeforeEnd);
  return head;
}

/**
 * Fuck, I forgot to download the other things... :D
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
inline int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize,
                 int *returnSize) {
  // guard clause
  if (matrixSize == 0) {
    *returnSize = 0;
    return NULL;
  }

  // matrix is the pointer to the original array. (pointer to the pointer)

  //"matrix size" is how many matrices in the big one.
  //  this is "how many rows", as each matrix inside is the row.
  //  thus column size (items per row or columns) is "matrixColSize"
  int rows = matrixSize;
  int cols = *matrixColSize;

  // printf("rows=%d, cols=%d\n", rows, cols);

  // size of array to be returned, allocate and set "returnSize"
  *returnSize = rows * cols;
  int *theArray = (int *)calloc(*returnSize, sizeof(int));

  // breaking down the problem:
  //  outer edge is m*n.
  //   go from 0,0 to 0,n-1 to m-1,n-1 to m-1,0 to 1,0.
  //  "spiral" loop is guided by bounds,
  //   upper bounds would be m/n, then m-1/n-1, etc..
  //   lower bounds would be 0, 1, 2, etc.
  //  this "shift" for bounds would be some count.
  //   bounds for this shift are when m-1 <= 1, n-1 <=1 etc...
  // label bounds as top/right/bottom/left, if they overlap exit.
  int top, right, bottom, left;
  top = 0;
  left = 0;
  right = cols - 1;
  bottom = rows - 1;

  // index of the return array
  int currIdx = 0;
  // printf("top=%d, right=%d, bottom=%d, left=%d\n", top, right, bottom, left);

  // slowly spiral inward, moving the index pointer inward until overlap.
  while (top <= bottom && left <= right) {
    for (int i = left; i <= right; i++) {
      // traversing array print...
      printf("%d, ", matrix[top][i]);
      theArray[currIdx++] = matrix[top][i];
    }
    top++;

    for (int j = top; j <= bottom; j++) {
      printf("%d, ", matrix[j][right]);
      theArray[currIdx++] = matrix[j][right];
    }
    right--;

    // top and right are done, bottom and left to do
    //   (if we already got all rows/columns), exit.
    if (top > bottom)
      break;
    for (int i = right; i >= left; i--) {
      printf("%d, ", matrix[bottom][i]);
      theArray[currIdx] = matrix[bottom][i];
      currIdx++;
    }
    bottom--;

    if (left > right)
      break;
    for (int j = bottom; j >= top; j--) {
      printf("%d, ", matrix[j][left]);
      theArray[currIdx] = matrix[j][left];
      currIdx++;
    }
    left++;
  }

  return theArray;
}