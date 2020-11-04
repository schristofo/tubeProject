#include "tube.h"

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
  "path modification:\n"
  "   model     Define model file path\n"
  "   input     Define input file path\n"
  "   output    Define output file path\n"
  "   clear     Delete all the paths\n\n"
  "model execution:\n"
  "   compile   Compile and print the model\n"
  "   demo      Run a demonstration model\n"
  "   run       Run the model using user-defined paths\n\n");
  return 0;
}
