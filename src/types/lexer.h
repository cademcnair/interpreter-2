namespace Lang {
    namespace Lexer {
        class Token {
        public:
            string content;
            char token_type;
            int char_pos, line_pos;
        };
    }
}