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
    // @brief 0 - FundamentalValue, 1 - Null, 2 - unordered map, 3 - unordered set, 4- vector
    struct SimpleValue;
    using __SimpleValue = variant<FundamentalValue*, nullptr_t, unordered_map<string, SimpleValue*>*, unordered_set<SimpleValue*>*, vector<SimpleValue*>*>;
    struct SimpleValue { __SimpleValue *v; };
    // @brief a - block, b - class, c - function;
    struct ComplexValue { __SimpleValue *v; char type; };

    typedef function<ComplexValue*(vector<ComplexValue*>)> BuiltFunction;
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

    // @brief 0 - SimpleValue, 1 - ComplexValue, 2 - FunctionValue
    typedef variant<SimpleValue, ComplexValue, FunctionValue> Value;
  }
}