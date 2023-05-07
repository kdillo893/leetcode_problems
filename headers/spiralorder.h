#include <stdio.h>
#include <stdlib.h>

int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize);


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