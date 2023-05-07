
#include <stdlib.h> // for null, probably not super needed...
#include <stdbool.h> // just to make true/false easier with the "has balls"

int* findBall(int **grid, int gridSize, int *gridColSize, int *returnSize);

// I forget why everything has "inline", might test without later.
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