#include "headers/basic_ds.h"
#include <stdlib.h>
#include <stdio.h>


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
  node_t * currNode = theList->head;

  int currIdx = 0;
  while(currNode->next != NULL || currIdx != idx) {
    //not at the idx, make current equal next, increment idx.
    currNode = currNode->next;
    currIdx++;
  }

  if (currIdx != idx) {
    //didn't reach the index... no real "didn't find" result. just give -1

    return NULL;
  } else {
    return currNode;
  }
}

int linkedListGetEntry(linkedlist_t * theList, int idx) { 
  node_t * currNode = linkedListSearch(theList, idx);

  if (currNode == NULL) {
    //not sure what do if node not found, just give -1
    return -1;
  }
  
  return currNode->val;
}

void linkedListSetEntry(linkedlist_t * theList, int idx, int value) {
  node_t * currNode = linkedListSearch(theList, idx);

  if (currNode == NULL) {
    return;
  }

  currNode->val = value;
}

int linkedListDeleteEntry(linkedlist_t * theList, int idx) {

  if (theList->head == NULL) {
    return -1;
  }

  if (idx == 0) {
    //move the head to next.
    theList->head = theList->head->next;
    return idx;
  }

  //search for the one before so you can connect the nodes.
  node_t * oneBeforeNode = linkedListSearch(theList, idx - 1);
  //if couldn't reach before OR the "node to delete" doesn't exist, just return -1 for no deleted.
  if (oneBeforeNode == NULL || oneBeforeNode->next == NULL) {
    return -1;
  }

  //do have a node, replace then return idx;
  oneBeforeNode->next = oneBeforeNode->next->next;
  return idx;
}

void linkedListDisplay(linkedlist_t * theList) {
  
  printf("[");

  node_t * currNode = theList->head;
  while(currNode != NULL) {
    printf("%d", currNode->val);

    //next node; if this isn't the last one (next not null), then put a comma.
    currNode = currNode->next;
    if (currNode != NULL) {
      printf(", ");
    }
  }

  printf("]\n");

}