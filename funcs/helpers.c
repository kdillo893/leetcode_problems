#include "../headers/helpers.h"

#include<stdio.h>

void printIntArray(int *arr, int size) {

  printf("[");

  for(int i = 0; i < size; i++) {
    printf("%d", arr[i]);
    if (i < size - 1) {
      printf(", ");
    }
  }

  printf("]\n");

}

void printLinkedList(struct ListNode *currNode) {
  printf("[");

  while(currNode != NULL) {
    printf("%d", currNode->val);

    currNode = currNode->next;
    if (currNode != NULL) {
      printf(", ");
    }
  }

  printf("]\n");
}