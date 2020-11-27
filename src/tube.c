#include "tube.h"

int tube(int argc, char * argv[]) {

  FILE *fp;
  // names of the files that store the paths of model, input, output files
  char modpath[50], inppath[50], outpath[50];

  // execution without parameters
  if(argc == 1) {
    help();
  }
  // execution with parameters
  else {
    // second parameter "model"
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
    // second parameter "input"
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
    // second parameter "output"
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
    // second parameter "clear"
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
    // second parameter "demo"
    else if(strcmp(argv[1], "demo") == 0) {

      if(argc == 2) {
        printf("# This is a demonstration of a 'tube run' session\n"
        "# using 'model/model-1.txt' file as the model file and \n"
        "# 'input/1to10.txt' as the input file. As you can see, \n"
        "# in the beggining, tube builds our model and prints all\n"
        "# of its block-elements. Next, information is given about\n"
        "# our model's characteristics, as well as, the input and\n"
        "# the output messages. In order to print our result in the\n"
        "# output file we should use the 'extract' function inside\n"
        "# our model.\n\n"
        );
        run("./model/model-1.txt", "./input/1to10.txt", NULL, 1);
      }
      else {
        printf("tube: '%s' has too many arguments.\nUsage: ./tube demo\n\n"
        "Type '%s' or '%s help' to see all of the acceptable commands.\n"
        , argv[1], argv[0], argv[0]);
      }

    }
    // second parameter "run"
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

        run(modpath, inppath, outpath, 1);
      }
      else {
        printf("tube: '%s' has too many arguments.\nUsage: ./tube run\n\n"
        "Type '%s' or '%s help' to see all of the acceptable commands.\n"
        , argv[1], argv[0], argv[0]);
      }

    }
    // second parameter "help"
    else if(strcmp(argv[1], "help") == 0) {

      if(argc == 2) {
        help();
      }
      else {
        printf("tube: '%s' has too many arguments.\nUsage: ./tube help\n\n"
        "Type '%s' or '%s help' to see all of the acceptable commands.\n"
        , argv[1], argv[0], argv[0]);
      }

    }
    // second parameter not recognised
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
  "path modification:\n"
  "   model     Define model file path\n"
  "   input     Define input file path\n"
  "   output    Define output file path\n"
  "   clear     Delete all the paths\n\n"
  "model execution:\n"
  "   demo      Run a demonstration model\n"
  "   run       Run the model using user-defined paths\n\n");
  return 0;
}
