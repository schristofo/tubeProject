#include "model_builder.h"

int tk;
char str[MAXLEN];

int run(char *modpath, char *inppath, char *outpath) {

  struct TubeData x;
  struct TubeData input;
  int state = 0;  //model state
  int layerNum = 0;  //model layerNum
  double d;

	//open model file
	mfile = fopen(modpath, "r");
	if(mfile == NULL){
		printf("Error: Model file missing or corrupted.\nTry using a different path.\n");
    return 1;
	}

  //start model builder
  printf("\n> model: ");
  tk=lex(str);
  if(tk == DASHTK) {
    printf("-");
    state = 2;
  }
  else {
    printf("\n\nError: Starting dash (-) missing.\n");
    state = 4;
  }
  while(1){
    tk=lex(str);
    //state 0: expecting dash(-)
    if(state == 0) {
      if(tk == DASHTK){
        printf("-");
        state = 1;
      }
      else{
        printf("\n\nError: Dash (-) expected\n");
        state = 4;
      }
    }
    //state 1: expecting a function
    else if(state == 1) {
      if(tk == ADDTK){
        printf("add");

        tk=lex(str);
        if(tk == E2){
          printf("(int%s)", str);
        }
        else if(tk == E3) {
          printf("(real%s)", str);
        }
        else {
          printf("\n\nError: Numeral value expected.\n");
          state = 4;
          continue;
        }
        sscanf(str, "%lf", &d);
        add(x.val, x.size, d);

        state = 0;
        layerNum++;
      }
      else if(tk == SUBTK) {
        printf("sub");

        tk=lex(str);
        if(tk == E2) {
          printf("(int%s)", str);
        }
        else if(tk == E3) {
          printf("(real%s)", str);
        }
        else {
          printf("\n\nError: Numeral value expected.\n");
          state = 4;
          continue;
        }
        sscanf(str, "%lf", &d);
        sub(x.val, x.size, d);

        state = 0;
        layerNum++;
      }
      else if(tk == MULTTK) {
        printf("mult");

        tk=lex(str);
        if(tk == E2) {
          printf("(int%s)", str);
        }
        else if(tk == E3) {
          printf("(real%s)", str);
        }
        else {
          state = 4;
          printf("\n\nError: Numeral value expected.\n");
          continue;
        }
        sscanf(str, "%lf", &d);
        mult(x.val, x.size, d);

        state = 0;
        layerNum++;
      }
      else if(tk == POWTK) {
        printf("pow");

        tk=lex(str);
        if(tk == E2) {
          printf("(int%s)", str);
        }
        else if(tk == E3) {
          printf("(real%s)", str);
        }
        else {
          printf("\n\nError: Numeral value expected.\n");
          state = 4;
          continue;
        }
        sscanf(str, "%lf", &d);
        power(x.val, x.size, d);

        state = 0;
        layerNum++;
      }
      else if(tk == MEDTK) {
        printf("med");

        if(x.size != 1) {
          med(x.val, &(x.size));
          x.val = (double*) realloc(x.val, 1);
        }
        else {
          printf("\n\nError: (med) expected array as input.\n");
          state = 4;
          continue;
        }
        state = 0;
        layerNum++;
      }
      else if(tk == MEANTK) {
        printf("mean");

        if(x.size != 1) {
          mean(x.val, &(x.size));
          x.val = (double*) realloc(x.val, 1);
        }
        else {
          printf("\n\nError: (mean) expected array as input.\n");
          state = 4;
          continue;
        }
        state = 0;
        layerNum++;
      }
      else if(tk == MAXTK) {
        printf("max");

        if(x.size != 1) {
          max(x.val, &(x.size));
          x.val = (double*) realloc(x.val, 1);
        }
        else {
          printf("\n\nError: (max) expected array as input.\n");
          state = 4;
          continue;
        }
        state = 0;
        layerNum++;
      }
      else if(tk == MINTK) {
        printf("min");

        if(x.size != 1) {
          min(x.val, &(x.size));
          x.val = (double*) realloc(x.val, 1);
        }
        else {
          printf("\n\nError: (max) expected array as input.\n");
          state = 4;
          continue;
        }
        state = 0;
        layerNum++;
      }
      else if(tk == BPTK) {
        printf("( o )");
        state = 0;
        layerNum++;
      }
      else if(tk == EXTRACTTK) {
        printf("extract");
        extract(outpath, x.val, x.size);
        state = 0;
        layerNum++;
      }
      else if(tk == SORTTK) {
        printf("sort");

        if(x.size != 1) {
          sort(x.val, x.size);
        }
        else {
          printf("\n\nError: (sort) expected array as input.\n");
          state = 4;
          continue;
        }

        state = 0;
        layerNum++;
      }
      else if(tk == IDXTK) {
        printf("idx");

        //works only for arrays
        if(x.size != 1) {
          tk=lex(str);

          //check if idx number is integer
          if(tk == E2) {
            printf("%s", str);
          }
          else {
            printf("\n\nError: Index number expected.\n");
            state = 4;
            continue;
          }
        }
        else {
          printf("\n\nError: (idx) expected array as input.\n");
          state = 4;
          continue;
        }

        size_t id = atoi(str);
        if(id < 0 || id > x.size-1) {
          printf("\n\nError: Index number out of bounds.\n");
          state = 4;
          continue;
        }
        idx(x.val, &(x.size), id);
        x.val = (double*) realloc(x.val, 1);

        state = 0;
        layerNum++;
      }
      //EOF
      else if(tk == EOFTK) {
        state = 3;
      }
      else {
        printf("\n\nError: Function expected.\n");
        state = 4;
      }
    }
    //state 2: expecting an input function
    else if(state == 2) {
      if(tk == NUMTK) {
        printf("num");
        x.size=1;
        input.size=1;
        x.val = (double*) malloc(sizeof(double));
        input.val = (double*) malloc(sizeof(double));
        num(inppath, x.val);
        *(input.val) = *(x.val);

        state = 0;
        layerNum++;
      }
      else if(tk == ARRAYTK) {

        printf("array");

        //array size
        tk=lex(str);
        if(tk == E2) {
          printf("%s", str);
          x.size=(size_t)atoi(str);
          input.size=x.size;
        }
        else {
          printf("\n\nError: Array size expected.\n");
          state = 4;
          continue;
        }
        // import array
        x.val = (double*) malloc(x.size*sizeof(double));
        input.val = (double*) malloc(x.size*sizeof(double));
        array(inppath, x.val, x.size);
        for(int i=0; i<x.size; i++) {
          *(input.val+i)=*(x.val+i);
        }

        state = 0;
        layerNum++;
      }
      else {
        printf("\n\nError: Input function expected.\n");
        state = 4;
      }
    }
    //state 3: final state (success)
    else if(state == 3) {
      printf("\n\nModel was built successfully.\n");

      //print depth
      if(layerNum != 1) printf(" . depth: %d layers\n", layerNum);
      else printf(" . depth: 1 layer\n");

      //print input
      if(input.size != 1) {
        printf(" . input: [ %g", *(input.val));
        for (size_t i=1; i<input.size; i++) printf(", %g", *(input.val+i));
        printf(" ]\n");
      }
      else {
        printf(" . input: %g\n", *(input.val));
      }

      //print output
      if(x.size != 1) {
        printf(" . output: [ %g", *(x.val));
        for (size_t i=1; i<x.size; i++) printf(", %g", *(x.val+i));
        printf(" ]\n");
      }
      else {
        printf(" . output: %g\n", *(x.val));
      }

      free(x.val);
      free(input.val);
      break;
    }
    //state 4: final state (fail)
    else if(state == 4) {
      printf("Failure: Abort reading.\n");
      break;
    }
  }

	fclose(mfile);
  return 0;
}
