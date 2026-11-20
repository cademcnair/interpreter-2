namespace Executer {
    void general(Lang::Executer::Runtime *runtime) {
        Lang::Lexer::Token *tok = runtime->curr_next();
        if (tok->token_type == 'a' || tok->token_type == 'B' || tok->token_type == 'g' || tok->token_type == 'b') {
            if (tok->vtp != 0x0 && tok->vtp->block_level > 0) {
                // block variable op
            }
            else if (tok->vtp != 0x0 && tok->vtp->class_level > 0) {
                // class variable op
            }
            // if (true) {
            else {
                if (runtime->prev == 0x0 && runtime->curr != 0x0) {
                    if (runtime->op == 0x0) {
                        __error("Unexpected token");
                    }
                    runtime->prev = runtime->curr;
                    runtime->curr = tok;
                }
                if (runtime->prev == 0x0 && runtime->curr == 0x0) {
                    runtime->curr = tok;
                    __logs << "Setting curr" << endl;
                }
                if (runtime->prev != 0x0 && runtime->curr != 0x0 && runtime->op != 0x0) {
                    // ready to complete an operation
                    __logs << "Operation" << endl;
                }
            }
        }
        if (tok->token_type == 'c') {
            // operator
            if (runtime->op != 0x0) {
                __error("Unexpected symbol");
            } else runtime->op = tok;
        }
    }
}