namespace Lang {
    namespace Lexer {
        class VariableTokenProfile {
        public:
            bool is_special;
            bool is_end;
            bool is_return;
            bool is_import;
            bool is_export;
            int block_level;
            int class_level;
            VariableTokenProfile() {
                block_level = 0;
                class_level = 0;
                is_special = false;
                is_end = false;
                is_return = false;
                is_import = false;
                is_export = false;
            }
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