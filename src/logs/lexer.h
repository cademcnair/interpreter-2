#include <vector>

using namespace std;

namespace Lexer {
  namespace __Logs {
    void log_tokens(vector<Lang::Lexer::Token> *tokens, bool contain_pos = false) {
      __logs << "--- LOGGING TOKENS ---" << endl;
      __logs << "a - number;\nb - variable name;\nB - boolean\nc - operator;\nd - special operator;\ne - seperators;\nf - break lines;\ng - string characters;\n" << endl;
      for (int i = 0; i < tokens->size(); ++i) {
        Lang::Lexer::Token token = tokens->at(i);
        __logs << token.token_type << ": \"" << token.content << "\"";
        if (contain_pos) __logs << " (char pos = " << token.char_pos << ", line pos = " << token.line_pos << ")";
        if (token.token_type == 'a') __logs << " (value = " << get<ld>(*(token.fv)) << ")";
        if (token.token_type == 'B') __logs << " (value = " << (get<bool>(*(token.fv)) ? "true" : "false") << ")";
        if (token.token_type == 'g') __logs << " (value = \"" << get<string>(*(token.fv)) << "\")";
        __logs << endl;
      }
      __logs << "--- END LOGGING TOKENS" << endl;
    }
  }
}