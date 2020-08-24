#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 256

int main(void)
{
  FILE *fp_in;
  FILE *fp_out;
  char *filename_input = "input.txt";
  char *filename_output = "output.txt";
  char readline[N] = {'\0'};

  if ((fp_in = fopen(filename_input, "r")) == NULL) {
    fprintf(stderr, "Failed to open file '%s'\n", filename_input);
    exit(EXIT_FAILURE);
  }

  if ((fp_out = fopen(filename_output, "w")) == NULL) {
    fprintf(stderr, "Failed to open file '%s'\n", filename_output);
    exit(EXIT_FAILURE);
  }

  int count = 0;

  while (fgets(readline, N, fp_in) != NULL) {
    if ((count % 3) == 0) {
      fprintf(fp_out, "%s", readline);
    } else {
      fprintf(fp_out, "dummy\n");
    }
    count++;
  }

  fclose(fp_out);
  fclose(fp_in);

  return EXIT_SUCCESS;

}
