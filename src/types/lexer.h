namespace Lang {
    namespace Lexer {
        class Token {
        public:
            string content;
                  /*
                    @brief
                    a - number;
                    b - variable name;
                    B - boolean;
                    c - operator;
                    d - special operator;
                    e - seperators;
                    f - break lines;
                    g - string;
                */
            char token_type;
            int char_pos, line_pos;
            Lang::Values::FundamentalValue *fv;
        };
    }
}