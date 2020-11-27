#include "utils.h"

void swap(double *p,double *q) {
   double t;

   t=*p;
   *p=*q;
   *q=t;
}

int num(char *inppath, double *xval) {

  FILE *ifile = fopen(inppath, "r");
  if(ifile == NULL){
    printf("\n\nError: Input file missing or corrupted.\nTry using a different path..\n");
    return 4;
  }

  // *xsize=1;
  // *inputsize=1;
  // xval = (double*) malloc(sizeof(double));
  // inputval = (double*) malloc(sizeof(double));
  // *(inputval) = *(xval);
  // xval = (double*) malloc(sizeof(double));
  fscanf(ifile,"%lf", xval);
  fclose(ifile);

  return 0;
}

void array(char *inppath, double *x, size_t xsize) {

  FILE *ifile = fopen(inppath, "r");
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

int add(double *x, size_t xsize) {

  double d;
  tk=lex(str);

  if(tk == E2){
    printf("(int%s)", str);
  }
  else if(tk == E3) {
    printf("(real%s)", str);
  }
  else {
    printf("\n\nError: Numeral value expected.\n");
    return 4;
  }
  sscanf(str, "%lf", &d);
  for(size_t i=0; i<xsize; i++) {
    *(x+i) = *(x+i) + d;
  }
  return 0;
}

int sub(double *x, size_t xsize) {
  double d;
  tk=lex(str);

  if(tk == E2) {
    printf("(int%s)", str);
  }
  else if(tk == E3) {
    printf("(real%s)", str);
  }
  else {
    printf("\n\nError: Numeral value expected.\n");
    return 4;
  }
  sscanf(str, "%lf", &d);
  for(size_t i=0; i<xsize; i++) {
    *(x+i) = *(x+i) - d;
  }
  return 0;
}

int mult(double *x, size_t xsize) {
  double d;
  tk=lex(str);

  if(tk == E2) {
    printf("(int%s)", str);
  }
  else if(tk == E3) {
    printf("(real%s)", str);
  }
  else {
    printf("\n\nError: Numeral value expected.\n");
    return 4;
  }
  sscanf(str, "%lf", &d);
  for(size_t i=0; i<xsize; i++) {
    *(x+i) = *(x+i) * d;
  }
  return 0;
}

int power(double *x, size_t xsize) {
  double d;
  tk=lex(str);

  if(tk == E2) {
    printf("(int%s)", str);
  }
  else if(tk == E3) {
    printf("(real%s)", str);
  }
  else {
    printf("\n\nError: Numeral value expected.\n");
    return 4;
  }
  sscanf(str, "%lf", &d);
  for(size_t i=0; i<xsize; i++) {
    *(x+i) = pow(*(x+i), d);
  }
  return 0;
}

int mean(double *x, size_t *xsize) {
  double t = 0;

  if(*xsize != 1) {
    for(size_t i=0; i<*xsize; i++){
      t += *(x+i);
    }
    t = t / *xsize;
    *x = t;
    *xsize = 1;
    x = (double*) realloc(x, 1);
  }
  else {
    printf("\n\nError: (mean) expected array as input.\n");
    return 4;
  }
  return 0;
}

int med(double *x, size_t *xsize) {
  size_t n = (*xsize+1)/2-1;

  if(*xsize != 1) {
    sort(x, *xsize);
    *x = *(x+n);
    *xsize = 1;
    x = (double*) realloc(x, 1);
  }
  else {
    printf("\n\nError: (med) expected array as input.\n");
    return 4;
  }
  return 0;
}

int max(double *x, size_t *xsize) {
  double max = *x;

  if(*xsize != 1) {

    for(size_t i=1; i<*xsize; i++) {
      if(*(x+i) > max) {
        max = *(x+i);
      }
    }
    *x = max;
    *xsize = 1;
    x = (double*) realloc(x, 1);
  }
  else {
    printf("\n\nError: (max) expected array as input.\n");
    return 4;
  }
  return 0;
}

int min(double *x, size_t *xsize) {
  double min = *x;

  if(*xsize != 1) {

    for(size_t i=1; i<*xsize; i++) {
      if(*(x+i) < min) {
        min = *(x+i);
      }
    }
    *x = min;
    *xsize = 1;
    x = (double*) realloc(x, 1);
  }
  else {
    printf("\n\nError: (min) expected array as input.\n");
    return 4;
  }
  return 0;
}

int extract(char *outpath, double *x, size_t xsize) {
  FILE *ofile = fopen(outpath, "w");

  if(xsize != 1) {
    fprintf(ofile, "[ %g", *x);
    for (size_t i=1; i<xsize; i++) fprintf(ofile, ", %g", *(x+i));
    fprintf(ofile, " ]\n");
  }
  else {
    fprintf(ofile, "%g\n", *x);
  }

  fclose(ofile);
  return 0;
}

int sort(double *x, size_t xsize) {
   size_t i,j;

   if(xsize != 1) {
     for(i = 0;i < xsize-1;i++) {
        for(j = 0;j < xsize-i-1;j++) {
           if(x[j] > x[j+1])
              swap(&x[j],&x[j+1]);
        }
     }
   }
   else {
     printf("\n\nError: (sort) expected array as input.\n");
     return 4;
   }
   return 0;
}

int idx(double *x, size_t *xsize) {
  size_t id;

  //works only for arrays
  if(*xsize != 1) {
    tk=lex(str);
    //check if idx number is integer
    if(tk == E2) {
      printf("%s", str);
    }
    else {
      printf("\n\nError: Index number expected.\n");
      return 4;
    }
  }
  else {
    printf("\n\nError: (idx) expected array as input.\n");
    return 4;
  }
  id = atoi(str);
  if(id < 0 || id > *xsize-1) {
    printf("\n\nError: Index number out of bounds.\n");
    return 4;
  }
  *x = *(x+id);
  *xsize = 1;
  x = (double*) realloc(x, 1);

  return 0;
}

// SPECIFY YOUR NEW FUNCTIONS HERE
// ...
// SPECIFY YOUR NEW FUNCTIONS HERE
