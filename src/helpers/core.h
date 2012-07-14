#pragma once

using namespace std;
namespace boost {}
using namespace boost;

#include <iostream>
#include <stdlib.h>

#define ERROR(x)                                      \
do {                                                  \
  cerr << "Error: " << (x) << endl                    \
       << "(from " << __FILE__ << ":"                 \
       << __LINE__ << ")" << endl;                    \
  exit(1);                                            \
} while (false)
