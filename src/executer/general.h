namespace Executer {
    void general(Lang::Enviromental::Enviroment *box, Lang::Executer::Runtime *runtime) {
        Lang::Lexer::Token *tok = runtime->curr_next();
        if (tok->token_type == 'a' || tok->token_type == 'B' || tok->token_type == 'g' || tok->token_type == 'b') {
            // string, boolean, number, or variable
            if (tok->vtp->block_level > 0) {
                // block variable op
            }
            else if (tok->vtp->class_level > 0) {
                // class variable op
            }
            else if (runtime->prev != 0x0 && runtime->op != 0x0) {
                // ready to complete an operation
            }
        }
    }
}