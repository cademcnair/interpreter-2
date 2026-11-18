#include <functional>

using namespace Lang::Values;

namespace Lang {
    namespace Built {
        namespace Numbers {
            typedef function<SimpleValue*(ld, ld)> SimpleUtilFunction;
            typedef variant<SimpleUtilFunction> UtilFunction;
            SimpleValue *plus(ld prev, ld curr) {
                return new SimpleValue(prev + curr);
            }

            unordered_map<string, UtilFunction> operations = {
                {"+", plus}
            };

            SimpleValue *op(SimpleValue *prev, string op, SimpleValue *curr) {
                if (__using_logs) {
                    if (prev->index() != 0) __error("Expected number, did not get one");
                    if (curr->index() != 0) __error("Expected number, did not get one");
                    if (prev->get0().index() != 0) __error("Expected number, did not get one");
                    if (curr->get0().index() != 0) __error("Expected number, did not get one");
                }
                
                if (!operations.contains(op)) __error("Operation does not exist");
                
                UtilFunction func = operations[op];
                if (func.index() == 0) {
                    ld prev_value = get<0>(prev->get0());
                    ld curr_value = get<0>(curr->get0());
                    return get<0>(func)(prev_value, curr_value);
                }
            }
        }
    }
}