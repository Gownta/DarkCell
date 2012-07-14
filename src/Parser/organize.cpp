#include "parser.h"

#include <stack>
#include <ctype.h>

#include "slice.h"
#include "Suite.h"

namespace parser {

// the number and total length of non-newline whitespace
struct LWS { size_t index, indent; };

LWS getLeadingWS(slice<char> & file) {
  size_t index;
  size_t size = 0;
  for (index = 0; ; ++index) switch (file[index]) {
    case ' ':
      size += 1;
      break;
    case '\t':
      size += 8 - size % 8;
      break;
    default:
      return { index, size };
  }
}

Line organizeLine(slice<char> & file, stack<size_t> & indents) {
  return "Hello";
}

Block organizeBlock(slice<char> & file, stack<size_t> & indents) {
  // A block is a list of suites
  Block block;

  for (;;) {
    auto lws = getLeadingWS(file);
    
    // stop if EOF has been reached
    if (file[lws.index] == '\0') {
      return block;
    }

    // ignore empty lines
    if (file[lws.index] == '\n') {
      file.advance(lws.index);
      continue;
    }

    // parse a line on equal indent
    // parse a block on greater indent
    // return on lesser indent
    if (indents.top() == lws.indent) {
      file.advance(lws.index);
      block.push_back(organizeLine(file, indents));
    }
    else if (indents.top() < lws.indent) {
      indents.push(lws.indent);
      block.push_back(organizeBlock(file, indents));
    }
    else /* indents.top() > lws.indent */ {
      indents.pop();

      if (indents.top() < lws.indent) {
        ERROR("Inconsistent indentation");
        // TODO
        // - more descriptive error message
        // - assume that its indent was actually indents.top(); continue parsing
        //   for more errors
      }

      return block;
    }
  }
}

list<Suite> organize(const string & file) {
  // LATER possibly ignore leading #!...

  // Since a program is a block, organize it as so.
  // The program block must be at indent 0.
  slice<char> iterator(file.data(), file.size());
  stack<size_t> indents;
  indents.push(0);

  return organizeBlock(iterator, indents);
}

}

