#include "utils.h"

void swap(double *p,double *q) {
   double t;

   t=*p;
   *p=*q;
   *q=t;
}

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

  for(size_t i=0; i<xsize; i++) {
    fscanf(ifile,"%lf", num);
    *(x+i)=*num;
  }

  free(num);
  fclose(ifile);
}

void add(double *x, size_t xsize, double b) {
  for(size_t i=0; i<xsize; i++) {
    *(x+i) = *(x+i) + b;
  }
}

void sub(double *x, size_t xsize, double b) {
  for(size_t i=0; i<xsize; i++) {
    *(x+i) = *(x+i) - b;
  }
}

void mult(double *x, size_t xsize, double b) {
  for(size_t i=0; i<xsize; i++) {
    *(x+i) = *(x+i) * b;
  }
}

void power(double *x, size_t xsize, double b) {
  for(size_t i=0; i<xsize; i++) {
    *(x+i) = pow(*(x+i), b);
  }
}

void mean(double *x, size_t *xsize) {
  double t = 0;
  for(size_t i=0; i<*xsize; i++){
    t += *(x+i);
  }
  t = t / *xsize;
  *x = t;
  *xsize = 1;
}

void med(double *x, size_t *xsize) {
  size_t n = (*xsize+1)/2-1;
  sort(x, *xsize);

  *x = *(x+n);
  *xsize = 1;
}

void max(double *x, size_t *xsize) {
  double max = *x;

  for(size_t i=1; i<*xsize; i++) {
    if(*(x+i) > max) {
      max = *(x+i);
    }
  }
  *x = max;
  *xsize = 1;
}

void min(double *x, size_t *xsize) {
  double min = *x;

  for(size_t i=1; i<*xsize; i++) {
    if(*(x+i) < min) {
      min = *(x+i);
    }
  }
  *x = min;
  *xsize = 1;
}

void extract(double *x, size_t xsize) {
  FILE *ofile = fopen("./output.txt", "w");

  if(xsize != 1) {
    fprintf(ofile, "[ %g", *x);
    for (size_t i=1; i<xsize; i++) fprintf(ofile, ", %g", *(x+i));
    fprintf(ofile, " ]\n");
  }
  else {
    fprintf(ofile, "%g\n", *x);
  }

  fclose(ofile);
}

void sort(double *x, size_t xsize) {
   size_t i,j;

   for(i = 0;i < xsize-1;i++) {
      for(j = 0;j < xsize-i-1;j++) {
         if(x[j] > x[j+1])
            swap(&x[j],&x[j+1]);
      }
   }
}

void idx(double *x, size_t *xsize, size_t d) {
  *x = *(x+d);
  *xsize = 1;
}
