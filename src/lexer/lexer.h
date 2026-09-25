
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace Lexer {
  void lex(vector<string> lines) {
    __logs << "Lexing " << lines.size() << " line(s)" << endl;
    
    for (string line : lines) {
      cout << line << endl;
    }
  }
}