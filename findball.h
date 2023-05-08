//macro to guard that this be only defined once
#ifndef POINT_H
#define POINT_H

/**
 * Find where balls would land if they are funneled through an array of "slopes" in a grid.
 *
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findBall(int **grid, int gridSize, int *gridColSize, int *returnSize);


/**
 * Print out the "array" of the grid
 */
void printBallGrid();

#endif