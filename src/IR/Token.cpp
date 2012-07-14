#include "Token.h"

ostream & operator<<(ostream & os, const Token & tok) {
  return os << tok.kind << " ('" << tok.lexeme << "')";
}

Token::operator string() {
  return lexeme;
}

