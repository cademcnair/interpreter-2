namespace Lexer {
    Lang::Lexer::Token describe(string token, char token_type, int char_pos, int line_pos) {
        if (token_type == 'C') token_type = 'c';
        if (token_type == 'B') __error("Expected variable name after variable command sequence");
        Lang::Lexer::Token to_return;
        to_return.content = token;
        to_return.token_type = token_type;
        to_return.char_pos = char_pos;
        to_return.line_pos = line_pos;
        return to_return;
    }
}