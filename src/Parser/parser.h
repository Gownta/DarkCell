#pragma once
#include "core.h"

#include <string>
#include <list>

#include "Suite.h"

namespace parser {

/**
 * DC programs are organized based on indentation.
 *
 * An indented section of code is called a BLOCK.
 *
 * Blocks are made up of lines and nested blocks. Like Python, these are 
 * called SUITES.
 *
 * LINES are strings. The leading whitespace, which was used to
 * determine how the line was blocked, is removed.
 *
 * Lines are logical, not physical. See
 * docs.python.org/reference/lexical_analysis.html
 *
 * The entire program is a block.
 */

Block organize(const string & file);

void parse(const string & file);

}

