#include <stdio.h>
#include <stdlib.h>

int main() {
  char strbuf[1000];
  FILE *fptr;
  char fname[20] = "testfile.txt";

  printf("\n\nCreating a file testfile.txt and it will be written with text: \n");
  printf("\n____________________________________\n");

  fptr = fopen(fname, "w");
  
  //guard clause, if no pointer, exit with err
  if (fptr == NULL) {
    printf(" ERROR OPENING FILE");
    exit(1);
  }

  printf("Input the sentence to write in the file : ");

  fgets(strbuf, sizeof strbuf, stdin);
  fprintf(fptr, "%s", strbuf);
  fclose(fptr);

  printf("\nFile %s successfully created!\n\n", fname);
  return 0;
}
