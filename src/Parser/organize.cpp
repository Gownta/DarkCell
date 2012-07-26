#include "parser.h"

#include <stack>
#include <ctype.h>

#include "Suite.h"

namespace parser {

size_t lws(const Token & ws) {
  if (ws.kind != WHITESPACE) ERROR("ICE");

  size_t ret = 0;
  for (size_t i = 0; i < ws.lexeme.size(); ++i) {
    switch (ws.lexeme[i]) {
      case ' ': ret += 1; break;
      case '\t': ret += 8 - ret % 8;
      default: goto EOL;
    }
  } EOL:
  return ret;
}

static bool isOpenParen(const string & str) {
  if (str.length() != 1) return false;
  switch (str[0]) {
    case '[':
    case '{':
    case '(':
      return true;
    default:
      return false;
  }
}
static bool isCloseParen(const string & str) {
  if (str.length() != 1) return false;
  switch (str[0]) {
    case ']':
    case '}':
    case ')':
      return true;
    default:
      return false;
  }
}

static bool balance(const string & p1, const string & p2) {
  if (p1 == "(" && p2 == ")") return true;
  if (p1 == "{" && p2 == "}") return true;
  if (p1 == "[" && p2 == "]") return true;
  return false;
}

static Line organizeLine(list<Token>::const_iterator & it, list<Token>::const_iterator & end, stack<size_t> & indents) {
  Line ret;

  if (it == end) return ret;

  size_t indent = 0;
  if (it->kind == WHITESPACE) {
    indent = lws(*it);
    ++it;
  }

  stack<string> parens;

  for (;; ++it) {
    // return if inputs expended
    if (it == end) return ret;

    switch (it->kind) {
      case WHITESPACE:
        indent = indent + 0;
        // TODO ensure any newlines are followed by at least indent space
        ret.push_back(*it); // WS is important for token joining
        break;
      case COMMENT:
        break;
      case NEWLINE:
        if (parens.empty()) {
          ++it;
          return ret;
        }
        ret.push_back(*it);
        break;
      default:
        ret.push_back(*it);
        if (isOpenParen(*it)) {
          parens.push(*it);
        }
        else if (isCloseParen(*it)) {
          if (parens.empty() || !balance(parens.top(), *it)) {
            ERROR("Unbalanced parenthesis");
          }
          parens.pop();
        }
    }
  }
}

static Block organizeBlock(list<Token>::const_iterator & it, list<Token>::const_iterator & end, stack<size_t> & indents) {
  Block ret;

  for (;;) {
    // return if inputs expended
    if (it == end) return ret;

    // get the indent
    size_t indent = it->kind == WHITESPACE ? lws(*it) : 0;

    // organize line on equal indent
    // organize block on greater indent
    // return on lesser indent
    if (indents.top() == indent) {
      ret.push_back(organizeLine(it, end, indents));
    }
    else if (indents.top() < indent) {
      indents.push(indent);
      ret.push_back(organizeBlock(it, end, indents));
    }
    else /*indents.top() > indent*/ {
      indents.pop();

      if (indents.top() < indent) ERROR("Inconsistent indent");
      // for continuity, assume equal to top; get more errors

      return ret;
    }
  }
}

Block organize(list<Token> & tokens) {
  stack<size_t> indents;
  indents.push(0);

  list<Token>::const_iterator start = tokens.cbegin();
  list<Token>::const_iterator end = tokens.cend();

  return organizeBlock(start, end, indents);
}

}

