#ifndef LEX_H
#define LEX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 10

#define DASHTK 10
#define COLONTK 11
#define E1 12 //function
#define E2 13 //integer
#define E3 14 //real
#define NATK 15
#define EOFTK 16

#define NUMTK 20
#define ARRAYTK 21
#define MATRIXTK 22
#define ADDTK 30
#define SUBTK 31
#define MULTTK 32
#define POWTK 33
#define MEDTK 34
#define MEANTK 35
#define MAXTK 36
#define MINTK 37
#define BPTK 38
#define EXTRACTTK 39
#define SORTTK 40
#define IDXTK 41
// GIVE YOUR FUNCTION A UNIQUE TOKEN (PS. LAST-TOKEN-INDEX + 1)
// #define NFTK

FILE *mfile;
int tk;
char str[MAXLEN];

int lex(char token[MAXLEN]);

#endif
