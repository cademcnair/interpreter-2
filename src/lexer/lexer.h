
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace Lexer {
  vector<Lang::Lexer::Token> *lex(Lang::Enviromental::Enviroment box, vector<string> lines) {
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
          if (*curr_type == 'g' && *curr == *original_string_entrance_character && *prev != '\\') {
            *building_token += *curr;
            tokens->push_back(Lexer::describe(
              *building_token, *building_token_type, ii, i));
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
        } else {
          if (*prev_type == '-') {
            building_token->push_back(*curr);
            *building_token_type = *curr_type;
          }

          if (*curr_type == *building_token_type) {
            building_token->push_back(*curr);
          // minus symbols
          } else if (
            (*curr_type == 'c' && *building_token_type == 'C') ||
            (*curr_type == 'C' && *building_token_type == 'c')
          ) {
            building_token->push_back(*curr);
            *building_token_type = 'c';
          // negative numbers
          } else if (
            (*curr_type == 'a' && *building_token_type == 'C' && building_token->size() == 1)
          ) {
            building_token->push_back(*curr);
            *building_token_type = 'a';
          // starting with variable commands
          } else if (
            (*curr_type == 'b' && *building_token_type == 'B') ||
            (*curr_type == 'B' && *building_token_type == 'b')
          ) {
            building_token->push_back(*curr);
            *building_token_type = 'b';
          // adding numbers to variables
          } else if (
            (*curr_type == 'a' && *building_token_type == 'b')
          ) {
            building_token->push_back(*curr);
          } else {
            if (*building_token_type == 'C') *building_token_type = 'c';
            if (*building_token_type == 'B') __error("Expected variable name after variable command sequence");
            tokens->push_back(Lexer::describe(
              *building_token, *building_token_type, ii, i));
            building_token->clear();

            building_token->push_back(*curr);
            *building_token_type = *curr_type;
          }

          if (*curr_type == 'g') {
            *in_string = true;
            *original_string_entrance_character = *curr;
          }
        }

        *prev = *curr;
        *prev_type = *curr_type;
        delete curr_type;

      }
    }

    if (*building_token_type != '-') {
      tokens->push_back(Lexer::describe(
        *building_token, *building_token_type, lines.back().size() - 1, lines.size() - 1));
    }

    building_token->clear();
    delete building_token;
    delete building_token_type;
    delete prev;
    delete prev_type;
    delete in_string;
    delete original_string_entrance_character;

    return tokens;
  }
}