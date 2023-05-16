#include "../headers/mergestrings.h"
#include <stdlib.h>

char * mergeAlternately(char * word1, char * word2){

    //we're not given the length of words, run through to \0 to find length.
    int word1Len = -1;
    int word2Len = -1;

    for (int i = 0; i <= 100 && word1Len < 0 && word2Len < 0; i++) {
        if (word1Len < 0 && word1[i] == '\0') {
            word1Len = i;
        }
        if (word2Len < 0 && word2[i] == '\0') {
            word2Len = i;
        }
    }
    if (word1Len < 0) {
        word1Len = 100;
    }
    if (word2Len < 0) {
        word2Len = 100;
    }

    int newLen = word1Len + word2Len;


    //define the "new string", we malloc b/c we need slots for chars to store.
    char * newWord = calloc(newLen, sizeof(char));

    //loop over both while inserting chars for new word; "i" is the index of the old words, "c" is the new.
    for (int i = 0, c = 0; i < word1Len || i < word2Len; i++) {

        if (i < word1Len) {
            newWord[c] = word1[i];
            c++;
        }
        if (i < word2Len) {
            newWord[c] = word2[i];
            c++;
        }
    }

    return newWord;
}