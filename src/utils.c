#include "../inc/utils.h"

void num(char *argv1, double *x) {

  FILE *ifile = fopen(argv1, "r");
  if(ifile == NULL){
    printf("\n\nError: Input file missing or corrupted.\nTry using a different path..\n");
    exit(0);
  }

  fscanf(ifile,"%lf", x);
  fclose(ifile);
}

void array(char *argv1, double *x, size_t xsize) {

  FILE *ifile = fopen(argv1, "r");
  double *num = (double*) malloc(sizeof(double));

  if(ifile == NULL){
    printf("\n\nError: Input file missing or corrupted.\nTry using a different path..\n");
    exit(0);
  }

  for(int i=0; i<xsize; i++) {
    fscanf(ifile,"%lf", num);
    *(x+i)=*num;
  }

  free(num);
  fclose(ifile);
}
