#ifndef TUBE_H
#define TUBE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.h"
#include "utils.h"

int tube(int argc, char * argv[]);
int help();
int clear();
int run(char *modpath, char *inppath, char *outpath);

#endif
