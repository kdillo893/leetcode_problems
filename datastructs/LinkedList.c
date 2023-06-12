#include "headers/basic_ds.h"
#include <stdlib.h>


void linkedListPrepend(linkedlist_t * theList, int newInt) {
  node_t * newNode = malloc(sizeof(node_t));
  newNode->val = newInt;
  newNode->next = theList->head;
}

void linkedListAppend(linkedlist_t * theList, int newInt) {
  //go to end; with last node put "next" as a new allocated node with the int value.
  node_t * currNode;
  node_t * newNode = malloc(sizeof(node_t));

  while (currNode->next != NULL) {
    currNode = currNode->next;
  }

  currNode->next = newNode;
}

node_t * linkedListSearch(linkedlist_t * theList, int idx) {

  return NULL;
}

int linkedListGetEntry(linkedlist_t * theList, int idx) { 
  node_t * currNode = theList->head;

  int currIdx = 0;
  while(currNode->next != NULL || currIdx != idx) {

  }

  if (currIdx != idx) {
    //didn't reach the index... what do?

    return -1;
  } else {
    return currNode->val;
  }

}

void linkedListSetEntry(linkedlist_t * theList, int idx, void* value) {

  
}

int linkedListDeleteEntry(linkedlist_t * theList, int idx) {
  //if the delete index is outside the size, return -1 (the int returned is the index removed)
}

void linkedListDisplay(linkedlist_t * theList) {

}