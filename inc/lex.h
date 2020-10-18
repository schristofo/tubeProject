#ifndef LEX_H
#define LEX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *mfile;

#define MAXLEN 10

#define E1 10
#define E2 11
#define E3 12
#define DASHTK 13
#define NATK 14
#define EOFTK 15

#define INTTK 20
#define ADDTK 21
#define SUBTK 22
#define MULTTK 23
#define POWTK 24
#define ARRAYTK 25
#define MEDTK 26
#define MEANTK 27
#define MAXTK 28
#define MINTK 29
#define BPTK 30
#define EXTRACTTK 31

int lex(char token[MAXLEN]);

#endif
