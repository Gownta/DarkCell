#include <iostream>
#include <string>
#include <vector>

#include "FileIO.h"
#include "parser.h"

using namespace std;

int main (int argc, const char ** argv) {

  //====================================
  // Usage

  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " filename [filename ...]" << endl;
    return 1;
  }

  //====================================
  // Parse files

  for (int i = 1; i < argc; ++i) {
    auto toks = parser::tokenize(argv[i]);
    auto block = parser::organize(toks);
    parser::print(block);
  }

  //====================================
  // DEV

  return 4;
}

