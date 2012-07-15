#pragma once
#include "core.h"

#include "Token.h"
#include <list>

namespace parser {

typedef list<Token> Line;
struct Suite;
typedef list<Suite> Block;

class Suite {
public:
  enum Type {
    LINE,
    BLOCK
  };

private:
  Type type;

  Line line;
  Block block;

public:
  Suite(Line line) : type(LINE), line(line) {}
  Suite(Block block) : type(BLOCK), block(block) {}

  Type getType() const { return type; }
  const Line & getLine() const {
    if (type == LINE) return line;
    ERROR("getLine on a Block");
  }
  const Block & getBlock() const {
    if (type == BLOCK) return block;
    ERROR("getBlock on a Line");
  }
};

void print(const Suite & suite);

}

