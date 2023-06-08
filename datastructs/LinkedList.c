#include "headers/basic_ds.h"
#include <stdlib.h>


void linkedListPrepend(linkedlist_t * theList, int newInt) {
  node_t * newNode = malloc(sizeof(node_t));
  newNode->val = newInt;
  newNode->next = theList->head;
}

void linkedListAppend(linkedlist_t * theList, int newInt) {
  //go to end.
  node_t * currNode

}

void* linkedListGetEntry(linkedlist_t * theList, int idx) { 
  node_t * currNode = theList->head;
}

void linkedListSetEntry(linkedlist_t * theList, int idx, void* value) {
  
  
}

int linkedListDeleteEntry(linkedlist_t * theList, int idx) {
  //if the delete index is outside the size, return -1 (the int returned is the index removed)
}

void linkedListDisplay(linkedlist_t * theList) {

}