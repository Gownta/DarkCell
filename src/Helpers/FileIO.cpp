#include "FileIO.h"
#include <string>
#include <fstream>
#include <streambuf>

using namespace std;

string strFromFile(const char * filename) {
  ifstream t(filename);
  string str;

  t.seekg(0, ios::end); 
  str.reserve(t.tellg());
  t.seekg(0, ios::beg);

  str.assign((istreambuf_iterator<char>(t)), istreambuf_iterator<char>());

  return str;
}

