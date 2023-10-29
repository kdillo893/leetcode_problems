#include "../headers/mergesort.h"
#include "../headers/helpers.h"

#include <stdio.h>
#include <stdlib.h>

void mergev1(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){

  //array output size is size1+size2... wait, what's the difference between *Size and n/m? wanna test...
  // int newLen = m + n;
  printf("n1s=%d, n2s=%d, m=%d, n=%d\n", nums1Size, nums2Size, m, n); 

  //edge cases which would make things O(n) or O(m):
  //  * last index of one array is less than the first index of other (nums1[m-1] < nums2[0] or nums2[n-1] < nums1[0])
  // if 1s < 2s, just append the values from 2s to end of 1s.
  if (nums1[m-1] < nums2[0]) {
    for (int j = 0; j < n; j++) {
      nums1[m+j] = nums2[j];
    }

    return;
  }

  //if 2s < 1s, loop through the "2nd" 
  //[678900000] [12345], [178960000] [12345], [128967000] [12345] ... works. 
  //[6789000] [123], would break the thing, more efficient would be "move the top end up first, then the 2nds in"
  if (nums2[m-1] < nums1[0]) {
    //first array
    for (int i = m-1; i >= 0; i--) {
      nums1[n+i] = nums1[i];
    }

    for (int j = 0; j < n; j++) {
      nums1[j] = nums2[j];
    }
    return;
  }

  //"indeterminate", because nums1 is both "existing data" and "the end data", need to play with that nicely.
  //  -- simplest way: put the 2nd array into the end of the first, then sort.
  //      (this rough way sucks, way too slow)
  //  -- "move things to the end that are the biggest"
  for (int j = 0; j < n; j++) {
    nums1[m + j] = nums2[j];
  }

  for (int c = 0, j = 0; j < n && c < m + n; ) {
    printf("c=%d, j=%d, ", c, j);
    printIntArray(nums1, nums1Size);

    if (nums1[c] < nums1[m+j]) {
      c++;
      continue;
    }

    if (nums1[c] > nums1[m+j]) {
      int temp = nums1[m+j];
      for (int i = m+j; i > c; i--) {
        nums1[i] = nums1[i-1];
      }
      nums1[c] = temp;
      j++;
      c++;
    }
  }
}

void mergev2(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  //array output size is size1+size2... wait, what's the difference between *Size and n/m? wanna test...
  // int newLen = m + n;
  printf("n1s=%d, n2s=%d, m=%d, n=%d\n", nums1Size, nums2Size, m, n); 

  //  -- "move things to the end that are the biggest"
  // does this cover the edge cases better? m+n vs n or m+n... might as well just do this.
  for (int i = m-1, j = n-1, c = nums1Size-1; c >=0;  ) {
    printf("i=%d, j=%d, c=%d\n", i, j, c);
    
    //if all the i's are placed in, we're just putting in j's, so no need to compare.
    //if some i's remain, still need the comparison to move the "i'th" thing up or no.
    // j = -1 is the "edge case" that this still compares, if j < 0, just do the first part.
    
    if (j < 0) {
      nums1[c] = nums1[i];
      i--;
    } else if (i < 0) {
      nums1[c] = nums2[j];
      j--;
    } else if (nums1[i] > nums2[j]) {
      nums1[c] = nums1[i];
      i--;
    } else {
      nums1[c] = nums2[j];
      j--;
    }

    c--;

  }
}

void mergev3(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
  // doing a "memory inefficient" method, which copies the nums1 array into one with 
  //    m length which is temporarily allocated, then do normal "step through the arrays".

  printf("n1s=%d, n2s=%d, m=%d, n=%d\n", nums1Size, nums2Size, m, n);
  printf("%d", nums1[0]);
  printf("%d", nums2[0]);


  // int* tempnums1 = (int*) calloc(m, sizeof(int));
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
  // mergev1(nums1, nums1Size, m, nums2, nums2Size, n);
  mergev2(nums1, nums1Size, m, nums2, nums2Size, n);
}
