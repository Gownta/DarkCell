#pragma once
#include "core.h"

#include <string>
#include <ostream>

enum Kind {
  WHITESPACE,
  NEWLINE,

  SINGLEQUOTE_STRING,
  DOUBLEQUOTE_STRING,
  SINGLE_QUOTE,
  DOUBLE_QUOTE,

  COMMENT,
  LINE_COMMENT,
  OPEN_COMMENT,
  CLOSE_COMMENT,

  PARTIAL
};
ostream & operator<<(ostream & os, Kind kind);

struct Token {
  Kind kind;
  string lexeme;

  Token(Kind kind, string lexeme) : kind(kind), lexeme(lexeme) {}

  operator string() const;
};
ostream & operator<<(ostream & os, const Token &);

