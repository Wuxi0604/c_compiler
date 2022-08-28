#include "defs.h"
#define extern_
#include "data.h"
#undef extern_
#include "decl.h"
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int scan(token_t* token);


// Initialise global variables
static
void 
init() 
{
  line      = 1;
  putback   = '\n';
}

// Print out a usage if started incorrectly
static 
void 
usage(
    char *prog
) 
{
  fprintf(stderr, "Usage: %s input_file\n", prog);
  exit(1);
}

// List of printable tokens
char *tokstr[] = { "+", "-", "*", "/", "intlit" };

// Loop scanning in all the tokens in the input file.
// Print out details of each token found.
static 
void 
scanfile() {
  token_t token;

  while (scan(&token)) 
  {
    printf("Token %s", tokstr[token.token]);
    if (token.token == T_INTLIT)
      printf(", value %d", token.int_value);
    printf("\n");
  }
}

// Main program: check arguments and print a usage
// if we don't have an argument. Open up the input
// file and call scanfile() to scan the tokens in it.
void main(
    int     argc, 
    char    *argv[]
) 
{
  if (argc != 2)
    usage(argv[0]);

  init();
  char* file_name = "input01";
  if ((input_file = fopen(file_name, "r")) == NULL) 
  {
    fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
    exit(1);
  }

  scanfile();
  exit(0);
}
