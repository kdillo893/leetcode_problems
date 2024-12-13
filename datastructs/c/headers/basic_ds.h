#include<stdlib.h>

/** Arraylist would need "what is this an arraylist of" and "length of list", then the contents.
  "how do I specify type on retrieve?" -> maybe just a void pointer and casting from caller.
*/
typedef struct ArrayList {
  size_t elementSize; // how big is each element?
  int length; // what data is actually here and how much? (capacity =/= length)
  int elementCapacity; // how many elements can I hold?

  //data will be "some allocation of size x length", the length can be changed.
  //(array of void pointers).
  void ** data;
} arraylist_t;

/**
 * ArrayListInt, just an arraylist of int sized items.
*/
typedef struct ArrayListInt {
  int length; // what data is actually here and how much? (capacity =/= length)
  int elementCapacity; // how many elements can I hold?

  //data will be "some allocation of intsize x length", the length can be changed.
  int * data;
} arraylistint_t;

/** Node containing a simple int value and the next node
*/
typedef struct Node {
  int val;
  struct Node * next;
} node_t;

/** linkedlist is just "head points to node"...
*/
typedef struct LinkedList {
  node_t * head;
} linkedlist_t;

/** queue is just "keep track of the front and back", new nodes go on the end.
  "front" next refers to "next front"; this trails to back, then next front for back is null.
  "back" added onto by "back's pointer goes to new node" for enqueue.
  in order to "empty", remember to free the nodes before assigning null pointer to top.
*/
typedef struct Queue {
  node_t * front;
  node_t * back;
} queue_t;

/** stack is "keep track of top only", nodes come from and go to top.
  "top" refers to the "next top";
  pop from stack grabs node and new top pointer goes to the old top's next.
  push onto stack is new top points to old top, then stack refers to new node top.
*/
typedef struct Stack {
  node_t * top;
} stack_t;
