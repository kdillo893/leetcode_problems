#include "headers/basic_ds.h"
#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_CAPACITY_ARRAYLIST 4;

//declare functions and put doc over them.


arraylist_t * arrayListCreate(size_t elementSize);
void* arrayListGetEntry(arraylist_t * theList, int idx);
void arrayListSetEntry(arraylist_t * theList, int idx, void* value);
int arrayListDeleteEntry(arraylist_t * theList, int idx);

void arrayListAdd(arraylist_t * theList, void* value);
void arrayListSetCapacity(arraylist_t * theList, int newCapacity);

//so this arraylist has "data" which is a pointer to an array of "things",
//    those "things" are structs or basic datatypes...

arraylist_t * arrayListCreate(size_t elementSize) {

  arraylist_t * newList = malloc(sizeof(arraylist_t));
  newList->elementSize = elementSize;
  newList->length = 0;
  newList->elementCapacity = DEFAULT_CAPACITY_ARRAYLIST;

  newList->data = calloc(newList->elementSize, newList->elementCapacity);

  return newList;
}

void* arrayListGetEntry(arraylist_t * theList, int idx) {
  if (idx >= theList->length) {
    return NULL;
  }
  return theList->data[idx];
}

void arrayListSetEntry(arraylist_t * theList, int idx, void* value) {
  if (idx >= theList->length) {
    //idx out of bounds, don't set
    return;
  }

  // can I actually do this? will it copy value or use a pointer which would let us alter data later?
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