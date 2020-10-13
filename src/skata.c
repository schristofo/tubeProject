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

int main(){

  FILE * file = fopen("./input/input.txt", "r");

  if(file == NULL){
    printf("file is empty. exit\n");
    exit(0);
  }

  char* ch = (char*) malloc(sizeof(char));
  printf("model: ");

  while(1) {
    *ch = fgetc(file);

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
    else if(state == 2) {
      printf("\nModel was built successfully.\noutput: %d\n", result);
      break;
    }
    else if(state == 3) {
      printf("Failure: Abort reading.\n");
      break;
    }

  }
  fclose(file);

}
