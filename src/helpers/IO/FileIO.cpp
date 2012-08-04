#include "FileIO.h"

#include <string>
#include <fstream>
#include <iostream>

string strFromFile(const char * filename) {
  ifstream file (filename , ios::in|ios::binary|ios::ate);
  if (!file.is_open()) {
    cerr << "file '" << filename << "' cannot be opened for reading; aborting compilation" << endl;
    exit(1);
  }
  size_t size = file.tellg();
  char * memblock = new char [size + 1];
  file.seekg (0, ios::beg);
  file.read (memblock, size);
  file.close();
  memblock[size] = '\0';
  string s(memblock);
  delete[] memblock;
  return s;
}

