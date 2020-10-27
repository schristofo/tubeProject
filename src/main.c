#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/lex.h"

int tk;
char str[MAXLEN];

void num(char *argv1, double *x) {

  FILE *ifile = fopen(argv1, "r");
  char *ch = (char*) malloc(sizeof(char));

  if(ifile == NULL){
    printf("Error: Input file missing or corrupted.\nTry using another destination\n");
    exit(0);
  }

  fscanf(ifile,"%lf", x);
  fclose(ifile);
}


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

  double *x;  //passing argument
  double *input;  //input register
  int state = 0;  //model state
  int layerNum = 0;  //model layerNum

	//open model file
	mfile = fopen(argv[2], "r");
	if(mfile == NULL){
		printf("Error: Model file missing or corrupted.\nTry using another destination\n");
		exit(1);
	}

  //start model builder
  printf("\n> model: ");
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
        layerNum++;

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
        layerNum++;

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
        layerNum++;

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
        layerNum++;

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
        layerNum++;
      }
      else if(tk == 27) {
        printf("mean");
        state = 0;
        layerNum++;
      }
      else if(tk == 28) {
        printf("max");
        state = 0;
        layerNum++;
      }
      else if(tk == 29) {
        printf("min");
        state = 0;
        layerNum++;
      }
      else if(tk == 30) {
        printf("( o )");
        state = 0;
        layerNum++;
      }
      else if(tk == 31) {
        printf("extract");
        state = 0;
        layerNum++;
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
        x = (double*) malloc(sizeof(double));
        input = (double*) malloc(sizeof(double));
        num(argv[1], x);
        *input = *x;

        state = 0;
        layerNum++;
      }
      else if(tk == 21) {
        printf("array");
        tk=lex(str);
        if(tk == 12) {
          printf("%s", str);
          state = 0;
        }
        else {
          printf("\nError: Array size expected.\n");
          state = 4;
        }
        // EDW THA MPEI TO ARRAY

        layerNum++;
      }
      else {
        printf("\nError: Input function expected.\n");
        state = 4;
      }
    }
    //state 3: final state (success)
    else if(state == 3) {
      printf("\n\nModel was built successfully.\n");
      if(layerNum != 1) printf("depth: %d layers, ", layerNum);
      else printf("depth: 1 layer, ");
      if(*input == (int)(*input)) printf("input: %.0lf, ", (*input));
      else printf("input: %lf, ", (*input));
      if(*x == (int)(*x)) printf("output: %.0lf\n", (*x));
      else printf("output: %lf\n", (*x));
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
