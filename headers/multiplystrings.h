
#include <stdio.h>  // for "null" pointer, might be better off using 0
#include <stdlib.h> // for malloc/free

char* multiply(char * num1, char * num2);

/**
 * multiply strings which represent numbers. Don't use any "int parsing" libraries or multiplying by using ints.
 */
inline char * multiply(char * num1, char * num2) {

  //edge cases:
  // either of the strings are null:
  if (num1[0] == '\0' || num2[0] == '\0') {
    return NULL;
  }

  // one of the strings is "0"
  if (num1[0] == '0' || num2[0] == '0') {
    char* zerostring = (char*) malloc(2 * sizeof(char));
    zerostring[0] = '0';
    zerostring[1] = '\0';
    return zerostring;
  }

  // one of the strings is exactly "1", return the opposite.
  if (num1[0] == '1' && num1[1] == '\0') {
    return num2;
  }
  if (num2[0] == '1' && num2[1] == '\0') {
    return num1;
  }
  //end edge cases

  //what is the length of each number? run through them until we see '\0'
  //could do this in one loop, but easier to read this way.
  int len1 = 0;
  for (len1 = 0; num1[len1] != '\0' ; len1++) {
    //nothing inside needed really.
  }
  int len2 = 0;
  for (len2 = 0; num2[len2] != '\0' ; len2++) {
    //nothing inside needed really.
  }

  //len1 is length of num1, len2 is length of num2 (all characters minus NULL which terminates.)
  //what is multiplcation? length of one is extended by the other. (eg 900 * 900 - 810000, 3dig * 3dig => 6 dig.)
  char* product = (char*) malloc((len1+len2+1) * sizeof(char));
  product[len1+len2] = '\0';

  //how do I multiply characters? "add together". when iterating through, go for one string, multiply the "int" equivalent of the chars,
  // then add to the "array" for tracking digits.
  int productAsInts[len1+len2];
  //initialize all as 0
  for (int i = 0; i < len1+len2; i++) {
    productAsInts[i] = 0;
  }

  //char value for "0123456789" starts at 48

  for (int idx1 = 0; idx1 < len1; idx1++) {
    //iterating over the first word, starting at one's place...
    int idx1Val = (int) num1[idx1] - 48;
    // printf("num1 @10^%d: %d\n", len1-1-idx1, idx1Val);

    //0 for the index, don't sum.
    if (idx1Val == 0) continue;

    for (int idx2 = 0; idx2 < len2; idx2++) {
      //evaluate "what to add per index."
      int idx2Val = (int) num2[idx2] - 48;
      // printf("num2 @10^%d: %d\n", len2-1-idx2, idx2Val);

      if (idx2Val == 0) continue;


      productAsInts[idx2+idx1+1] += idx1Val*idx2Val;

      // printf("theArray: \n [");
      // for (int i = 0 ; i < len1+len2; i++) {
      //   printf("%d, ", productAsInts[i]);
      // }
      // printf("]\n");

    }
  }

  //we have the "asInts" array filled, now convert to char array.
  for (int i = len1+len2-1; i >=0; i--) {
    int val = productAsInts[i];
    //as I go through, how does this look?
    int digval = val % 10;
    int carry = val / 10;

    // printf("val=%d, dig=%d, carry=%d\n", val, digval, carry);
    product[i] = (char) digval + 48;
    if (i > 0) {
      productAsInts[i-1]+= carry;
    }

    // printf("%s, %d'th=%d, carry=%d\n", product, len1+len2-i, digval, carry);
  }

  //fix: if the product has leading 0, move everything.
  if (product[0] == '0') {
    for (int i = 0; i < len1+len2; i++) {
      product[i] = product[i+1];
    }
  }

  return product;
}