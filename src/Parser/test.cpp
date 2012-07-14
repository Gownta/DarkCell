#include "parser.h"

#include <iomanip>
#include <iostream>

namespace parser {

void parse(const string & file) {
  size_t index = 0;

  while (index < file.size()) {
    size_t oldIndex = index;

    // count the number of leading whitespaces
    int ws = 0;
    while (index < file.size() && file[index] == ' ') {
      index++;
      ws++;
    }

    // print ws
    cout << "--" << setw(3) << ws << " ";

    // find next newline
    index = file.find('\n', index);

    // print the line
    cout << file.substr(oldIndex, index-oldIndex) << endl;

    // increment index over the newline
    if (index == string::npos) break;
    index++;
  }
}

}

