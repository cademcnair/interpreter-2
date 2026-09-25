#include <iostream>
#include <vector>
#include <string>
#include "logs.h"
#include "types/box.h"
#include "lexer/lexer.h"

using namespace std;

int main(int argc, char *argv[]) {
  __logs << "--- baileyi ---" << endl;

  if (argc != 2) __error("Please input one argument, being the file name");

  __logs << "Reading file " << argv[1] << endl;
  freopen(argv[1], "r", stdin);
  string line;
  vector<string> lines;
  while (getline(cin, line)) {
    while (!line.empty()) {
      if (line[0] == ' ' || line[0] == '\t') {
        line.erase(line.begin());
      } else break;
    }
    lines.push_back(line);
    line = "";
  }
  __logs << "Read file" << endl;

  Lexer::lex(lines);

}