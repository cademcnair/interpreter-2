namespace Lang {
    namespace Lexer {
        class VariableTokenProfile {
        public:
            bool is_special = false;
            bool is_end = false;
            bool is_return = false;
            bool is_import = false;
            bool is_export = false;
            int block_level = 0;
            int class_level = 0;
        };
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
                    h - function indsides;
                */
            char token_type;
            int char_pos, line_pos;
            Lang::Values::FundamentalValue *fv;
            VariableTokenProfile *vtp;
            int *next_block_position;
        };
    }
}