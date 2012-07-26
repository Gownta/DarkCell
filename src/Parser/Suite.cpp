#include "Suite.h"

#include <string>

namespace parser {

static void print(const Block & block, const string & indent);
static void print(const Line & line, const string & indent);
static void print(const Suite & suite, const string & indent);

static void print(const Block & block, const string & indent) {
  for (auto & suite : block) {
    print(suite, indent);
  }
}

static void print(const Line & line, const string & indent) {
  cout << indent;
  for (auto & tok : line) {
    if (tok.kind == WHITESPACE) continue;
    cout << tok.lexeme << ' ';
  }
  cout << endl;
}

static void print(const Suite & suite, const string & indent) {
  switch (suite.getType()) {
    case Suite::BLOCK:
      print(suite.getBlock(), indent + "  ");
      break;
    case Suite::LINE:
      print(suite.getLine(), indent);
      break;
  }
}

void print(const Suite & suite) {
  print(suite, "");
}

}

