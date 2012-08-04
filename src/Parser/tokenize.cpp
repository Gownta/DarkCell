#include "parser.h"

#include <string>
#include <fstream>
#include <iostream>
#include <cctype>

#include "Token.h"

namespace parser {

void tokenize(Kind, const char *, unsigned int) {}

namespace {

inline bool isNewline(char c) {
  switch (c) {
    case '\n':
    case '\r':
    case '\f':
    case '\v':
      return true;
    default:
      return false;
  }
}

inline bool isWhitespace(char c) {
  switch (c) {
    case ' ':
    case '\t':
      return true;
    default:
      return false;
  }
}

}

list<Token> tokenize(const char * filename) {
  // read the file as a char*
  char * file;
  size_t size;
  {
    ifstream File(filename, ios::in|ios::binary|ios::ate);
    if (!File.is_open()) {
      cerr << "file '" << filename << "' cannot be opened for reading; aborting compilation" << endl;
      exit(1);
    }
    size = File.tellg();
    char * memblock = new char[size + 1];
    File.seekg(0, ios::beg);
    File.read(memblock, size);
    File.close();
    memblock[size] = '\0';
    file = memblock;
  }

  // munch until EOF
  list<Token> ret;
  size_t idx = 0;
  while (idx < size) {
    auto start = idx;
    Kind kind;
    #define GRAB(f, k) if (f(file[idx])) { kind = (k); do { ++idx; } while (f(file[idx])); }
    GRAB(isNewline, NEWLINE)
    else GRAB(isWhitespace, WHITESPACE)
    else GRAB(isalpha, PARTIAL)
    else GRAB(isdigit, PARTIAL)
    else { ++idx; kind = PARTIAL; }
    #undef GRAB
    ret.emplace_back(kind, string(file + start, idx - start));
  }

  delete[] file;
  return ret;
}

}

