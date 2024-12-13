/* THIS IS NOT GOOD YET! Don't Worry about it...*/
#include "headers/basic_ds.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_CAPACITY_ARRAYLIST 4;

//declare functions and put doc over them.

/**
 * Initialize array list for elements of size_t `elementSize`.
 */
arraylist_t * arrayListCreate(size_t elementSize);

/**
 * Get entry at `idx` in arraylist_t `theList`.
 */
void* arrayListGetEntry(arraylist_t * theList, int idx);

/**
 * Write entry at `idx` in arraylist_t `theList` with the `value`.
 */
void arrayListSetEntry(arraylist_t * theList, int idx, void* value);

/**
 * Remove entry at `idx` in arraylist_t `theList` and adjust element positions.
 */
int arrayListDeleteEntry(arraylist_t * theList, int idx);

/**
 * Append entry to `theList` with `value`.
 */
void arrayListAdd(arraylist_t * theList, void* value);

/**
 * Modify maximum capacity of array list to new length of elements.
 */
void arrayListSetCapacity(arraylist_t * theList, int newCapacity);

//this arraylist has "data" which is a pointer to a contiguous memory region of elements of given size
//    those "things" are structs or basic datatypes...
arraylist_t * arrayListCreate(size_t elementSize) {

  arraylist_t * newList = malloc(sizeof(arraylist_t));
  assert(newList != NULL);
  newList->elementSize = elementSize;
  newList->length = 0;
  newList->elementCapacity = DEFAULT_CAPACITY_ARRAYLIST;

  newList->data = calloc(newList->elementSize, newList->elementCapacity);
  assert(newList->data != NULL);

  return newList;
}

void* arrayListGetEntry(arraylist_t * theList, int idx) {
  if (idx >= theList->length) {
    return NULL;
  }

  //this returns void pointer of [idx * elementSize]; I don't like trusting callers to check that
  return theList->data[idx * theList->elementSize];
}

void arrayListSetEntry(arraylist_t * theList, int idx, void* value) {
  if (idx >= theList->length) {
    //idx out of bounds, don't set
    return;
  }

  //write value to idx, shifted by size of elements.
  theList->data[idx] = value; 
}

void arrayListAdd(arraylist_t * theList, void* value) {
  //increasing the length; if length would go above capacity, need to extend it.
  theList->length++;

  if (theList->length > theList->elementCapacity) {
    //expand 
    arrayListSetCapacity(theList, theList->length + 1);
  }

  //now the capacity is good, put the value in the last spot (length-1)
  theList->data[theList->length-1] = value;
}

/** this is generic for setting the capacity of the list; can be used for expanding, shrinking, specific sizing. */
void arrayListSetCapacity(arraylist_t * theList, int newElementCapacity) {

  //don't try to zero it...
  assert(newElementCapacity > 0);

  void* theRealloc = realloc(theList->data, theList->elementSize * newElementCapacity);
  if (theRealloc != NULL) {
    //was able to realloc successfully, now change the element capacity on the struct.
    theList->elementCapacity = newElementCapacity;
  }
}

int arrayListDeleteEntry(arraylist_t * theList, int idx) {
  //if the delete index is outside the size, return -1 (the int returned is the index removed)
  if (idx >= theList->length || idx < 0) {
    return -1;
  }
  
  //loop up to one minus the length, move value ahead into current index (length-2 is last iteration)
  for (int i = idx; i < (theList->length) - 1; i++) {
    theList->data[i] = theList->data[i+1];
  }

  theList->length--;

  return 0;
}

void freeArrayList(arraylist_t *theList) {
  //free the data, then the bigger thing..
  free(theList->data);
  free(theList);
}
