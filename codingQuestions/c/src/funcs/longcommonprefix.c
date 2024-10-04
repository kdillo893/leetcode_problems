#include "../headers/longcommonprefix.h"

// #include <stdio.h>
#include <stdlib.h> // for malloc/free

char* longestCommonPrefix(char **strs, int strsSize) {
  // guard clauses:
  //   no words, no common.
  if (strsSize <= 0) {
    char *empty = (char *) malloc(sizeof(char));
    empty[0] = '\0';
    return empty;
  }
  //  one word, only common with itself.
  if (strsSize == 1) {
    return strs[0];
  }

  // find the shortest string, that way we can malloc only the length of the
  // shortest string.
  //  a way to do this without a string library is to go by index and loop
  //  over the "strs" outer arrays until one of them is '\0'
  int maxidx = 200;
  for (int idx = 0; idx < 200; idx++) {
    int found = 0;
    for (int word = 0; word < strsSize; word++) {
      if (strs[word][idx] == '\0') {
        found = 1;
        break;
      }
    }

    if (found) {
      maxidx = idx;
      break;
    }
  }

  // there is a word that's empty, return empty.
  if (maxidx == 0) {
    char *empty = (char *)malloc(sizeof(char));
    empty[0] = '\0';
    return empty;
  }

  // evaluate character matches
  char *firstWord = strs[0];
  for (int wnum = 1; wnum < strsSize; wnum++) {
    char *word = strs[wnum];

    for (int letter = 0; letter < maxidx; letter++) {
      if (word[letter] != firstWord[letter]) {
        // set the nulloc and common letter location to NUL val.
        maxidx = letter;
        break;
      }
    }

    if (maxidx == 0) {
      char *empty = (char *)malloc(sizeof(char));
      empty[0] = '\0';
      return empty;
    }
  }

  // copy the letters of the first word up to maxidx
  char *common = (char *)malloc((maxidx + 1) * sizeof(char));
  common[maxidx] = '\0';
  for (int idx = 0; idx < maxidx; idx++) {
    common[idx] = firstWord[idx];
  }

  return common;
}