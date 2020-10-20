#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/lex.h"

FILE *ifile;
int tk;
char str[MAXLEN];
int state = 0;
int depth = 0;
int result = 5;

int main(int argc, char * argv[]){

  //passing destination path correctly
  if( argc > 3 ) {
    printf("Error: Too many arguments.\nTry again with:\n\t%s <input-file-path> <model-file-path>\n", argv[0]);
    exit(1);
  }
  else if( argc < 3 ) {
    printf("Error: Model file path expected.\nTry again with:\n\t%s <input-file-path> <model-file-path>\n", argv[0]);
    exit(1);
  }

  // ifile = fopen(argv[1], "r");
  // if(ifile == NULL){
  //   printf("Error: Input file missing or corrupted.\nTry using another destination\n");
  //   exit(0);
  // }
	//
  // while(1) {
  //   *ch = fgetc(ifile);
  //   if(isdigit(*ch) == 0) {
  //     printf("Error: Digit expected inside the inout file\n");
  //     continue;
  //   }
  //   break;
  // }
  // fclose(ifile);
  // result = atoi(ch);
  // printf("input: int%d\n", result);


	//open model file
	mfile = fopen(argv[2], "r");
	if(mfile == NULL){
		printf("Error: Model file missing or corrupted.\nTry using another destination\n");
		exit(1);
	}

  printf("model: ");
  tk=lex(str);
  if(tk == 10) {
    printf("-");
    state = 2;
  }
  else {
    printf("\nError: Starting dash (-) missing.\n");
    state = 4;
  }

  while(1){
    tk=lex(str);
    //state 0: expecting dash(-)
    if(state == 0) {
      if(tk == 10){
        printf("-");
        state = 1;
      }
      else{
        printf("\nError: Dash (-) expected\n");
        state = 4;
      }
    }
    //state 1: expecting a function
    else if(state == 1) {
      if(tk == 22){
        printf("add");
        state = 0;
        depth++;

        tk=lex(str);
        if(tk == 12) {
          printf("(int%s)", str);
        }
        else if(tk == 13) {
          printf("(real%s)", str);
        }
        else {
          printf("\nError: Numeral value expected.\n");
          state = 4;
        }
      }
      else if(tk == 23) {
        printf("sub");
        state = 0;
        depth++;

        tk=lex(str);
        if(tk == 12) {
          printf("(int%s)", str);
        }
        else if(tk == 13) {
          printf("(real%s)", str);
        }
        else {
          printf("\nError: Numeral value expected.\n");
          state = 4;
        }
      }
      else if(tk == 24) {
        printf("mult");
        state = 0;
        depth++;

        tk=lex(str);
        if(tk == 12) {
          printf("(int%s)", str);
        }
        else if(tk == 13) {
          printf("(real%s)", str);
        }
        else {
          state = 4;
          printf("\nError: Numeral value expected.\n");
        }
      }
      else if(tk == 25) {
        printf("pow");
        state = 0;
        depth++;

        tk=lex(str);
        if(tk == 12) {
          printf("(int%s)", str);
        }
        else if(tk == 13) {
          printf("(real%s)", str);
        }
        else {
          printf("\nError: Numeral value expected.\n");
          state = 4;
        }
      }
      else if(tk == 26) {
        printf("med");
        state = 0;
        depth++;
      }
      else if(tk == 27) {
        printf("mean");
        state = 0;
        depth++;
      }
      else if(tk == 28) {
        printf("max");
        state = 0;
        depth++;
      }
      else if(tk == 29) {
        printf("min");
        state = 0;
        depth++;
      }
      else if(tk == 30) {
        printf("( o )");
        state = 0;
        depth++;
      }
      else if(tk == 31) {
        printf("extract");
        state = 0;
        depth++;
      }
      //EOF
      else if(tk == 15) {
        state = 3;
      }
      else {
        printf("\nError: Function expected.\n");
        state = 4;
      }
    }
    //state 2: expecting an input function
    else if(state == 2) {
      if(tk == 20) {
        printf("num");
        state = 0;
        depth++;
      }
      else if(tk == 21) {
        printf("array");
        state = 0;
        depth++;

        tk=lex(str);
        if(tk == 12) {
          printf("%s", str);
        }
        else {
          printf("\nError: Array size expected.\n");
          state = 4;
        }
      }
      else {
        printf("\nError: Input function expected.\n");
        state = 4;
      }
    }
    //state 3: final state (success)
    else if(state == 3) {
      printf("\nModel was built successfully.\noutput: %d\n", result);
      break;
    }
    //state 4: final state (fail)
    else if(state == 4) {
      printf("Failure: Abort reading.\n");
      break;
    }
  }

  // edo tha kano ta magika
	fclose(mfile);
	return 0;
}
