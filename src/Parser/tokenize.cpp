#if 0
#include "parser.h"

#include <stdio.h>

extern int yylex();
extern void yyrestart(FILE *);

namespace parser {

static list<Token> tokens;
void tokenize(Kind kind, const char * data, size_t length) {
  tokens.emplace_back(kind, string(data, length));
}

list<Token> tokenize(const char * filename) {
  FILE * f = fopen(filename, "r");
  if (f == NULL) ERROR("could not open file");
  yyrestart(f);
  yylex();
  list<Token> ret;
  ret.swap(tokens); // this clears tokens
  return ret;
}

}
#endif

