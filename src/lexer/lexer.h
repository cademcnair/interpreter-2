
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace Lexer {
  void lex(Lang::Enviromental::Enviroment box, vector<string> lines) {
    __logs << "Lexing " << lines.size() << " line(s)" << endl;
    
    vector<Lang::Lexer::Token> *tokens = new vector<Lang::Lexer::Token>();
    string *building_token = new string("");
    char *building_token_type = new char('-');
    char *prev = new char('\n');
    char *prev_type = new char('-');
    bool *in_string = new bool(false);
    char *original_string_entrance_character = new char('\'');

    vector<string>::iterator line = lines.begin();
    for (int i = 0; i < lines.size(); ++i, advance(line, 1)) {
      string::iterator curr = line->begin();
      for (int ii = 0; ii < lines.size(); ++ii, advance(curr, 1)) {
        unordered_map<char, char>::iterator key = box.lexer__token_types.find(*curr);
        char *curr_type;
        if (key == box.lexer__token_types.end()) {
          if (*in_string) curr_type = new char('-');
          else __error("illegal character");
        } else curr_type = new char((*key).second);
        
        if (*in_string) {
          if (*curr_type == 'g' && *curr == *original_string_entrance_character) {
            *building_token += *curr;
            tokens->push_back(Lexer::describe());
            building_token->clear();

            *in_string = false;
            *prev = '\n'; *prev_type = '-';
            *building_token_type = '-';
            delete curr_type; continue;
          } else {
            *building_token += *curr;
          }
          // don't worry about *curr_type == 'f' || *curr_type == 'e' BECAUSE
          // it's OK to treat it like normal, as it's not
          // important if the new line token looks like ";;" or "\t\t\t  "
          // as the line will be broken anyways

        } else if (*curr_type == 'e') {
          if (*prev_type == 'e') {
            delete curr_type; continue;
          } else {
            tokens->push_back(Lexer::describe());
            *building_token_type = '-';
          }
        } else if (*curr_type == 'f') {
          delete curr_type;
          if (building_token->size() != 0) {
            tokens->push_back(Lexer::describe());
            *building_token_type = '-';
          }
        }

        *prev = *curr;
        *prev_type = *curr_type;
        delete curr_type;

      }
    }
  }
}