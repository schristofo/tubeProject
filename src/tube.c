#include "tube.h"

int tk;
char str[MAXLEN];

int tube(int argc, char * argv[]) {

  FILE *fp;
  char modpath[50], inppath[50], outpath[50];

  if(argc == 1) {
    help();
  }
  else {
    if(strcmp(argv[1], "model") == 0) {

      if(argc == 3) {
        fp = fopen("./bin/modpath.bin", "wb+");
        fprintf(fp, "%s\n", argv[2]);
        fclose(fp);
      }
      else {
        printf("Usage: %s model <model-file-path>\n\n"
        "Type '%s' or '%s help' to see all of the acceptable commands.\n"
        , argv[0], argv[0], argv[0]);
      }

    }
    else if(strcmp(argv[1], "input") == 0) {

      if(argc == 3) {
        fp = fopen("./bin/inppath.bin", "wb+");
        fprintf(fp, "%s\n", argv[2]);
        fclose(fp);
      }
      else {
        printf("Usage: %s input <input-file-path>\n\n"
        "Type '%s' or '%s help' to see all of the acceptable commands.\n"
        , argv[0], argv[0], argv[0]);
      }

    }
    else if(strcmp(argv[1], "output") == 0) {

      if(argc == 3) {
        fp = fopen("./bin/outpath.bin", "wb+");
        fprintf(fp, "%s\n", argv[2]);
        fclose(fp);
      }
      else {
        printf("Usage: %s output <output-file-path>\n\n"
        "Type '%s' or '%s help' to see all of the acceptable commands.\n"
        , argv[0], argv[0], argv[0]);
      }

    }
    else if(strcmp(argv[1], "compile") == 0) {

      printf("This feature is not supported yet.\n\n"
      "Type '%s' or '%s help' to see all of the acceptable commands.\n"
      , argv[0], argv[0]);

    }
    else if(strcmp(argv[1], "clear") == 0) {

      if(argc == 2) {
        remove("./bin/modpath.bin");
        remove("./bin/inppath.bin");
        remove("./bin/outpath.bin");
      }
      else {
        printf("tube: '%s' has too many arguments.\nUsage: ./tube clear\n\n"
        "Type '%s' or '%s help' to see all of the acceptable commands.\n"
        , argv[1], argv[0], argv[0]);
      }

    }
    else if(strcmp(argv[1], "demo") == 0) {

      if(argc == 2) {
        run("./model/model-1.txt", "./input/1to10.txt", 0);
      }
      else {
        printf("tube: '%s' has too many arguments.\nUsage: ./tube demo\n\n"
        "Type '%s' or '%s help' to see all of the acceptable commands.\n"
        , argv[1], argv[0], argv[0]);
      }

    }
    else if(strcmp(argv[1], "run") == 0) {

      if(argc == 2) {
        fp = fopen("./bin/modpath.bin", "r+b");
        if(fp == NULL){
      		printf("Model file path not specified.\n\n"
          "Type './tube model <model-file-path>' first.\n");
          return 1;
      	}
        fscanf(fp, "%s", modpath);
        fclose(fp);

        fp = fopen("./bin/inppath.bin", "rb+");
        if(fp == NULL){
          printf("Input file path not specified.\n\n"
          "Type './tube input <input-file-path>' first.\n");
          return 1;
      	}
        fscanf(fp, "%s", inppath);
        fclose(fp);

        fp = fopen("./bin/outpath.bin", "rb+");
        if(fp == NULL){
          printf("Output file path not specified.\n\n"
          "Type './tube output <output-file-path>' first.\n");
          return 1;
      	}
        fscanf(fp, "%s", outpath);
        fclose(fp);

        run(modpath, inppath, outpath);
      }
      else {
        printf("tube: '%s' has too many number of arguments.\nUsage: ./tube run\n\n"
        "Type '%s' or '%s help' to see all of the acceptable commands.\n"
        , argv[1], argv[0], argv[0]);
      }

    }
    else if(strcmp(argv[1], "help") == 0) {

      if(argc == 2) {
        help();
      }
      else {
        printf("tube: '%s' has too many number of arguments.\nUsage: ./tube help\n\n"
        "Type '%s' or '%s help' to see all of the acceptable commands.\n"
        , argv[1], argv[0], argv[0]);
      }

    }
    else {
      printf("tube: '%s' is not a recognisable tube command.\n\n"
      "Type '%s' or '%s help' to see all of the acceptable commands.\n", argv[1], argv[0], argv[0]);
    }
  }

  return 0;
}

int help() {
  //print help
  printf("Usage: tube <command> [<args>]\n\nHere is a list of all the available commands:\n\n"
  "path definition:\n"
  "   model     Define model file path\n"
  "   input     Define input file path\n"
  "   output    Define output file path\n\n"
  "   clear     Delete all the paths\n\n"
  "model execution:\n"
  "   compile   Compile and print the model\n"
  "   demo      Run a demonstration model\n"
  "   run       Run the model using user-defined paths\n\n");
  return 0;
}

int run(char *modpath, char *inppath, char *outpath) {

  double *x;  //passing argument
  size_t xsize;
  double *input;  //input register
  size_t inputsize;
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
        add(x, xsize, d);

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
        sub(x, xsize, d);

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
        mult(x, xsize, d);

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
        power(x, xsize, d);

        state = 0;
        layerNum++;
      }
      else if(tk == MEDTK) {
        printf("med");

        if(xsize != 1) {
          med(x, &xsize);
          x = (double*) realloc(x, 1);
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

        if(xsize != 1) {
          mean(x, &xsize);
          x = (double*) realloc(x, 1);
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

        if(xsize != 1) {
          max(x, &xsize);
          x = (double*) realloc(x, 1);
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

        if(xsize != 1) {
          min(x, &xsize);
          x = (double*) realloc(x, 1);
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
        extract(outpath, x, xsize);
        state = 0;
        layerNum++;
      }
      else if(tk == SORTTK) {
        printf("sort");

        if(xsize != 1) {
          sort(x, xsize);
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
        if(xsize != 1) {
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
        if(id < 0 || id > xsize-1) {
          printf("\n\nError: Index number out of bounds.\n");
          state = 4;
          continue;
        }
        idx(x, &xsize, id);
        x = (double*) realloc(x, 1);

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
        xsize=1;
        inputsize=1;
        x = (double*) malloc(sizeof(double));
        input = (double*) malloc(sizeof(double));
        num(inppath, x);
        *input = *x;

        state = 0;
        layerNum++;
      }
      else if(tk == ARRAYTK) {

        printf("array");

        //array size
        tk=lex(str);
        if(tk == E2) {
          printf("%s", str);
          xsize=(size_t)atoi(str);
          inputsize=xsize;
        }
        else {
          printf("\n\nError: Array size expected.\n");
          state = 4;
          continue;
        }
        // import array
        x = (double*) malloc(xsize*sizeof(double));
        input = (double*) malloc(xsize*sizeof(double));
        array(inppath, x, xsize);
        for(int i=0; i<xsize; i++) {
          *(input+i)=*(x+i);
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
      if(inputsize != 1) {
        printf(" . input: [ %g", *input);
        for (size_t i=1; i<inputsize; i++) printf(", %g", *(input+i));
        printf(" ]\n");
      }
      else {
        printf(" . input: %g\n", *input);
      }

      //print output
      if(xsize != 1) {
        printf(" . output: [ %g", *x);
        for (size_t i=1; i<xsize; i++) printf(", %g", *(x+i));
        printf(" ]\n");
      }
      else {
        printf(" . output: %g\n", *x);
      }

      free(x);
      free(input);
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
