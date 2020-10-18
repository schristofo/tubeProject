#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/lex.h"

FILE *ifile;
int tk;
char str[MAXLEN];
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
  while((tk=lex(str)) != 15){

    if(tk == 13){
      printf("-");
    } else if(tk == 11){
      printf("(int%s)", str);
    } else if(tk == 12){
      printf("(real%s)", str);
    } else if(tk == 21){
      printf("add");
    } else if(tk == 22){
      printf("sub");
    } else if(tk == 23){
      printf("mult");
    } else if(tk == 24){
      printf("pow");
    } else if(tk == 20){
      printf("int");
    } else if(tk == 25){
      printf("array");
    } else if(tk == 26){
      printf("med");
    } else if(tk == 27){
      printf("mean");
    } else if(tk == 28){
      printf("max");
    } else if(tk == 29){
      printf("min");
    } else if(tk == 30){
      printf("bp");
    } else if(tk == 31){
      printf("extract");
    } else{
      printf("\nError: Not recognised token (%s)\n", str);
      exit(1);
    }

  }
  printf("\nModel was built successfully.\noutput: ...\n");

  // edo tha kano ta magika
	fclose(mfile);
	return 0;
}
