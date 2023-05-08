#ifndef LL_REMNFOMEND_H
#define LL_REMNFOMEND_H

//define what a linked list node is; 
//  has a value, points to another list node
struct ListNode {
  int val;
  struct ListNode* next;
};

/**
 * Remove the nth node from the end of a linked list.
 *
 * Example, a list is length n, the end of the list index would be n-1..
 * 1 would be the "first node from end", or n-1, 2nd would be n-2, and so on.
 */
struct ListNode* removeNthFromEndV1(struct ListNode* head, int n);
struct ListNode* removeNthFromEndV2(struct ListNode* head, int n);
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);

#endif