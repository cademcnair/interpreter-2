#include <string>
#include <variant>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long double ld;

namespace Lang {
  namespace Values {
    // @brief 0 - ld, 1 - string, 2 - bool
    typedef variant<ld, string, bool> FundamentalValue;
    // @brief 0 - FundamentalValue, 1 - Null, 2 - unordered map, 3 - unordered set
    struct SimpleValue;
    using __SimpleValue = variant<FundamentalValue*, nullptr_t, unordered_map<string, SimpleValue*>*, unordered_set<SimpleValue*>*>;
    struct SimpleValue { __SimpleValue *v; };
    // @brief a - block, b - class, c - function;
    struct ComplexValue { __SimpleValue *v; char type; };

    // @brief 0 - SimpleValue, 1 - ComplexValue
    typedef variant<SimpleValue, ComplexValue> Value;
  }
}