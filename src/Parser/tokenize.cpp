#include "parser.h"

#include <stdio.h>

extern int yylex();
extern void yyrestart(FILE *);

namespace parser {

void tokenize(Kind kind, const char * data, size_t length) {
  cout << "Token " << kind << ": '" << string(data, length) << "'" << endl;
}

list<Token> tokenize(const char * filename) {
  FILE * f = fopen(filename, "r");
  if (f == NULL) ERROR("could not open file");
  yyrestart(f);
  yylex();
  return list<Token>();
}

}

