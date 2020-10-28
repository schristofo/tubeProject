#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

//input functions
void num(char *argv1, double *x);
void array(char *argv1, double *x, size_t xsize);

//transforming functions
void add(double *x, size_t xsize, double b);

#endif
