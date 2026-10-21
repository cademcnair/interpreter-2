namespace Lang {
    namespace Executer {
        // todo: consider modes and parents
        class Runtime {
        public:
            Lang::Enviromental::DataSpace *data_space;
            vector<Lang::Lexer::Token*>::iterator position;
            vector<Lang::Lexer::Token*> *tokens;
            Lang::Enviromental::Enviroment *box;
            int *curr_pos;
            Lang::Lexer::Token *curr;
            Lang::Lexer::Token *prev;
            vector<Runtime*> *sub_levels;
            vector<bool> *sub_levels_cleaned;
            Runtime(Lang::Enviromental::DataSpace *ds, vector<Lang::Lexer::Token*> *tok, Lang::Enviromental::Enviroment *bx) {
                data_space = ds;
                tokens = tok;
                box = bx;
                position = tok->begin();
                curr_pos = new int(0);
                sub_levels = new vector<Runtime*>();
                if (__using_logs) {
                    sub_levels_cleaned = new vector<bool>();
                }
            }
            ~Runtime() {
                if (__using_logs) {
                    for (bool b : *sub_levels_cleaned) {
                        if (!b) __error("Did not fully clean up the Runtime");
                    }
                    delete sub_levels_cleaned;
                }
                delete curr_pos;
                delete sub_levels;
            }
            Runtime *using_runtime() {
                if (sub_levels->empty()) return this;
                return sub_levels->back();
            }
            Runtime *clean_recent_child() {
                delete sub_levels->back();
                sub_levels->pop_back();
                if (__using_logs) sub_levels_cleaned->pop_back();
            }
            Runtime *spawn_child() {
                Runtime *new_runtime = new Runtime(data_space, tokens, box);
                sub_levels->push_back(new_runtime);
                if (__using_logs) sub_levels_cleaned->push_back(false);
            }
            vector<Lang::Lexer::Token*>::iterator advance(int amount) {
                (*curr_pos) += amount;
                std::advance(position, amount);
                return position;
            }
            vector<Lang::Lexer::Token*>::iterator next() {
                vector<Lang::Lexer::Token*>::iterator result = advance(1);
                if (result != tokens->end() && (*result)->token_type == 'e') return next();
                return result;
            }
        };
    }
}