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
  // Read files

  vector<string> files(argc - 1);
  for (int i = 1; i < argc; ++i) files[i - 1] = strFromFile(argv[i]);

  //====================================
  // Parse files

  for (auto & file : files) {
    parser::parse(file);
  }

  //====================================
  // DEV

  return 4;
}

