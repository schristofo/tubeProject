#include "model_builder.h"

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
        state=add(x.val, x.size);
        layerNum++;
      }
      else if(tk == SUBTK) {
        printf("sub");
        state=sub(x.val, x.size);
        layerNum++;
      }
      else if(tk == MULTTK) {
        printf("mult");
        state=mult(x.val, x.size);
        layerNum++;
      }
      else if(tk == POWTK) {
        printf("pow");
        state=power(x.val, x.size);
        layerNum++;
      }
      else if(tk == MEDTK) {
        printf("med");
        state=med(x.val, &(x.size));
        layerNum++;
      }
      else if(tk == MEANTK) {
        printf("mean");
        state=mean(x.val, &(x.size));
        layerNum++;
      }
      else if(tk == MAXTK) {
        printf("max");
        state=max(x.val, &(x.size));
        layerNum++;
      }
      else if(tk == MINTK) {
        printf("min");
        state=min(x.val, &(x.size));
        layerNum++;
      }
      else if(tk == BPTK) {
        printf("( o )");
        state = 0;
        layerNum++;
      }
      else if(tk == EXTRACTTK) {
        printf("extract");
        state=extract(outpath, x.val, x.size);
        layerNum++;
      }
      else if(tk == SORTTK) {
        printf("sort");
        state=sort(x.val, x.size);
        layerNum++;
      }
      else if(tk == IDXTK) {
        printf("idx");
        state=idx(x.val, &(x.size));
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
