#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lex.h"

//input functions
void num(char *inppath, double *x);
void array(char *inppath, double *x, size_t xsize);

//transforming functions
int add(double *x, size_t xsize);
int sub(double *x, size_t xsize);
int mult(double *x, size_t xsize);
int power(double *x, size_t xsize);
int med(double *x, size_t *xsize);
int mean(double *x, size_t *xsize);
int max(double *x, size_t *xsize);
int min(double *x, size_t *xsize);
int extract(char *outpath, double *x, size_t xsize);
int sort(double *x, size_t xsize);
int idx(double *x, size_t *xsize);

#endif
