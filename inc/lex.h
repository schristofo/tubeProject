#ifndef LEX_H
#define LEX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *mfile;

#define MAXLEN 10

#define DASHTK 10
#define E1 11 //function
#define E2 12 //integer
#define E3 13 //real
#define NATK 14
#define EOFTK 15

#define NUMTK 20
#define ARRAYTK 21
#define ADDTK 22
#define SUBTK 23
#define MULTTK 24
#define POWTK 25
#define MEDTK 26
#define MEANTK 27
#define MAXTK 28
#define MINTK 29
#define BPTK 30
#define EXTRACTTK 31

int lex(char token[MAXLEN]);

#endif
