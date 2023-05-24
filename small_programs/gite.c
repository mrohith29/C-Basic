/*
 * GITE, the git helper
 *
 * I mostly just use 3 commands: add, commit, and push. This is a simple
 * wrapper around those commands to make it easier to use.
 *
 * It just takes the commit message as an argument and does the rest.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 2048

int main(int argc, char *argv[]) {
  char command[MAXLEN] = "git add . && git commit -m \"";
  char *message = argv[1];
  char *end = "\" && git push";

  if (argc < 2) {
    printf("Usage: gite \"commit message\"\n");
    return 1;
  }

  strcat(command, message);
  strcat(command, end);

  system(command);

  return 0;
}
