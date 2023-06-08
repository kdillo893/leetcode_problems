#include "headers/basic_ds.h"
#include <stdlib.h>

#define DEFAULT_CAPACITY_ARRAYLIST 4;

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
  //increasing the length, this means 



}

int arrayListDeleteEntry(arraylist_t * theList, int idx) {
  //if the delete index is outside the size, return -1 (the int returned is the index removed)



  return 0;
}

void arrayListDisplay(arraylist_t * theList) {

}