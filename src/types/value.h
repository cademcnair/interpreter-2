#include <string>
#include <variant>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long double ld;

namespace Lang {
  namespace Values {
    class Null {};
    // @brief 0 - ld, 1 - string, 2 - bool
    typedef variant<ld, string, bool> FundamentalValue;
    typedef void SimpleValue; /* temp */
    // @brief 0 - FundamentalValue, 1 - Null, 2 - unordered map, 3 - unordered set
    typedef variant<FundamentalValue, Null, unordered_map<string, SimpleValue>, unordered_set<SimpleValue>> SimpleValue;

    class Block {
    };
    class Function {
    };
    class Class {
    };

    // @brief 0 - SimpleValue, 1 - Block, 2 - Function, 3 - Class
    typedef variant<SimpleValue, Block, Function, Class> Value;
  }
}