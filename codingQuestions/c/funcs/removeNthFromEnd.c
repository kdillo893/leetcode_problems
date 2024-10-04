#include "../headers/removeNthFromEnd.h"

#include<stdio.h>
#include<stdlib.h> // for malloc/free

// I forget why everything has "inline", might test without later.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
inline struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  return removeNthFromEndV1(head, n);
  // return removeNthFromEndV2(head, n);
}

inline struct ListNode* removeNthFromEndV1(struct ListNode* head, int n) {
  //edge cases: 
  //  null pointer for the head.
  if (head == NULL) {
    return NULL;
  }
  
  //find the length of the list.
  int length = 0;
  struct ListNode * currNode = head;
  while(currNode != NULL) {
    currNode = currNode->next;
    length++;
  }

  //n is "nth from end", not index.
  //n = 1 means "last node", n = 2 means "2nd to last", etc.
  //n = length means (first node); anything greater is out of bound, just return original.
  if (n > length) {
    return head;
  }

  if (n == length) {
    return head->next;
  }

  //removing the N'th; this is effectively the "ith" node.
  currNode = head;
  struct ListNode * prevNode;

  //use n to trace through, no need for a new variable.
  //process:
  // - removing n'th node, the previous node's "next" would need to go to the one after the removed node.
  for(int i = 0 ; i < length - n; i++) {
    prevNode = currNode;
    currNode = currNode->next;
  }

  //currNode is the one to remove.
  prevNode->next = currNode->next;
  free(currNode);

  return head;
}

inline struct ListNode* removeNthFromEndV2(struct ListNode* head, int n) {
  //edge cases: 
  //  null pointer for the head.
  if (head == NULL) {
    return NULL;
  }
  
  //find the length of the list.
  int length = 0;
  struct ListNode * currNode = head;
  struct ListNode * nthBeforeEnd = NULL;
  struct ListNode * priorToNthBeforeEnd = NULL;
  while(currNode != NULL) {
    currNode = currNode->next;
    length++;

    if (length - n >= 0) {
      if (nthBeforeEnd == NULL) {
        nthBeforeEnd = head;
      } else {
        priorToNthBeforeEnd = nthBeforeEnd;
        nthBeforeEnd = nthBeforeEnd->next;
      }
    }
  }

  //alernate: instead of going through the list twice (one for length, one for node removal),
  //  can instead trace "length - n" spaces before the current node as it traverses.
  //  

  //n before end out of bounds, just return head
  if (nthBeforeEnd == NULL || length < n) {
    return head;
  }

  //if they're the same, just move head->next
  if (nthBeforeEnd == head) {
    return head->next;
  }

  //none of the edge cases, move the node then return head.
  priorToNthBeforeEnd->next = nthBeforeEnd->next;
  free(nthBeforeEnd);
  return head;
}