#include <stdio.h>
#include <stdlib.h>

int state = 0;
int result = 5;

void plus(){
  result = result + 5;
  printf("add5");
}
void p(){
  result = result * result * result * result * result;
  printf("powOf5");
}
void star(){
  result = result * 5;
  printf("times5");
}
void slash(){
  result = result / 5;
  printf("divBy5");
}

int main(int argc, char * argv[]){

  //passing destination path correctly
  if( argc == 2 ) {
   ;
  }
  else if( argc > 2 ) {
    printf("Error: Too many arguments.\nTry again with:\n\t./bin/skata <input-file-path>\n");
    exit(0);
  }
  else {
    printf("Error: Input file path expected.\nTry again with:\n\t./bin/skata <input-file-path>\n");
    exit(0);
  }

  //open input file
  FILE * file = fopen(argv[1], "r");
  if(file == NULL){
    printf("Error: Input file missing or corrupted.\nTry using another destination\n");
    exit(0);
  }

  //read the file
  char* ch = (char*) malloc(sizeof(char));
  printf("model: ");

  while(1) {
    *ch = fgetc(file);

    //state 0: expecting dash(-)
    if(state == 0) {
      if(*ch == '-'){
        printf("-");
        state = 1;
      }
      else if(*ch == ' '){
        ;
      }
      else if(*ch == EOF || *ch == '\n') {
        state = 3;
        printf("\nError: Final dash (-) expected\n");
      }
      else{
        state = 3;
        printf("\nError: Dash (-) expected\n");
      }
    }
    //state 1: expecting a 5by5 function
    else if(state == 1) {
      if(*ch == '+'){
        plus();
        state = 0;
      }
      else if(*ch == '^'){
        p();
        state = 0;
      }
      else if(*ch == '*'){
        star();
        state = 0;
      }
      else if(*ch == '/'){
        slash();
        state = 0;
      }
      else if(*ch == ' '){
        ;
      }
      else if(*ch == EOF || *ch == '\n') {
        state = 2;
      }
      else{
        state = 3;
        printf("\nError: Not recognised token (%c)\n", *ch);
      }
    }
    //state 3: final state (success)
    else if(state == 2) {
      printf("\nModel was built successfully.\noutput: %d\n", result);
      break;
    }
    //state 4: final state (fail)
    else if(state == 3) {
      printf("Failure: Abort reading.\n");
      break;
    }

  }
  fclose(file);

}
