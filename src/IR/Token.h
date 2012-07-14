#pragma once
#include "core.h"

#include <string>
#include <ostream>

enum Kind {
  WHITESPACE,
  NEWLINE,

  SINGLEQUOTE_STRING,
  DOUBLEQUOTE_STRING,

  PARTIAL
};
ostream & operator<<(ostream & os, Kind kind);

struct Token {
  Kind kind;
  string lexeme;

  Token(Kind kind, string lexeme) : kind(kind), lexeme(lexeme) {}

  operator string();
};
ostream & operator<<(ostream & os, const Token &);

