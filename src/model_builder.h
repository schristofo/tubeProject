#ifndef MODEL_BUILDER_H
#define MODEL_BUILDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.h"
#include "utils.h"

struct TubeData {
  double *val;
  size_t size;
};

int run(char *modpath, char *inppath, char *outpath);

#endif
