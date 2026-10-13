namespace Lexer {
    Lang::Lexer::Token describe(string token, char token_type, int char_pos, int line_pos) {
        if (token_type == 'C') token_type = 'c';
        if (token_type == 'B') __error("Expected variable name after variable command sequence");
        Lang::Lexer::Token to_return;
        to_return.content = token;
        if (token_type == 'b') {
            if (token == "true") {
                to_return.fv = new Lang::Values::FundamentalValue(true);
                to_return.token_type = 'B';
            } else if (token == "false") {
                to_return.fv = new Lang::Values::FundamentalValue(false);
                to_return.token_type = 'B';
            } else {
                to_return.token_type = 'b';
            }
        } else to_return.token_type = token_type;
        to_return.char_pos = char_pos;
        to_return.line_pos = line_pos;

        if (token_type == 'a') {
            to_return.fv = new Lang::Values::FundamentalValue(stold(token));
        }

        else if (token_type == 'g') {
            token.pop_back(); token.erase(0, 1);
            to_return.fv = new Lang::Values::FundamentalValue(token);
        }

        return to_return;
    }
}