#include <string>
#include <variant>
#include <unordered_map>
#include <unordered_set>
#include <functional>

using namespace std;
typedef long double ld;

namespace Lang {
  namespace Values {
    // @brief 0 - ld, 1 - string, 2 - bool
    typedef variant<ld, string, bool> FundamentalValue;
    struct SimpleValue; struct ComplexValue;
    typedef function<ComplexValue*(vector<ComplexValue*>)> CatchAllFunction;
    typedef function<SimpleValue*(SimpleValue*, string, SimpleValue*)> OperatorFunction;
    typedef variant<CatchAllFunction, OperatorFunction> BuiltFunction;

    class FunctionValue {
    public:
      bool *type_is_built;
      BuiltFunction *built;
      FunctionValue(BuiltFunction *b) {
        built = b;
        type_is_built = new bool(true);
      }
      ~FunctionValue() {
        if (*type_is_built) {
          delete type_is_built;
          delete built;
        }
      }
    };

    // @brief 0 - FundamentalValue, 1 - Null, 2 - unordered map, 3 - unordered set, 4- vector, 5 - function
    using __SimpleValue = variant<FundamentalValue, nullptr_t, unordered_map<string, ComplexValue*>, unordered_set<ComplexValue*>, vector<ComplexValue*>, FunctionValue>;
    struct SimpleValue { __SimpleValue v; };
    // @brief a - block, b - class, c - value;
    struct ComplexValue { __SimpleValue v; char type; };
  }
}