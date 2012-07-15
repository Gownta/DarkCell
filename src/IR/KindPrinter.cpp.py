import re

import sys, os
from os.path import abspath, dirname
scriptpath = abspath(sys.argv[0])
dirpath = dirname(scriptpath)

kinds = []
kindmatcher = re.compile(' *([a-zA-Z_][a-zA-Z_0-9]*)')

openenum = re.compile("^enum Kind")
endenum = re.compile("^}")

inKind = False
for line in open(dirpath + "/Token.h", "r"):
  line.rstrip()
  if openenum.match(line):
    inKind = True
    continue
  if inKind and endenum.match(line):
    break;
  if inKind:
    m = kindmatcher.match(line)
    if m:
      kinds.append(m.group(1))

function = []
function.append("ostream & operator<<(ostream & os, Kind kind) {")
function.append("  switch (kind) {")
for k in kinds:
  function.append("    case " + k + ": os << \"" + k + "\"; break;")
function.append("  }")
function.append("  return os;");
function.append("}")

f = open(scriptpath[:-3], "w") # drop the .py
f.write('#include "Token.h"\n\n')
f.write('\n'.join(function))
f.close()

