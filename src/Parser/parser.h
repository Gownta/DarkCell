#pragma once
#include "core.h"

#include <string>
#include <list>

#include "Suite.h"
#include "Token.h"

namespace parser {

list<Token> tokenize(const char * filename);
Block organize(list<Token> & tokens);


}

