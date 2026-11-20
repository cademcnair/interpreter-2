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
    struct __SimpleValue; class ComplexValue; class SimpleValue;
    typedef function<ComplexValue*(vector<ComplexValue*>)> CatchAllFunction;
    typedef function<SimpleValue*(SimpleValue*, string, SimpleValue*)> OperatorFunction;
    typedef variant<CatchAllFunction, OperatorFunction> BuiltFunction;

    class FunctionValue {
    public:
      bool type_is_built;
      BuiltFunction built;
      FunctionValue(BuiltFunction b) {
        built = b;
        type_is_built = true;
      }
    };

    // @brief 0 - FundamentalValue, 1 - Null, 2 - unordered map, 3 - unordered set, 4- vector, 5 - function
    using ____SimpleValue = variant<FundamentalValue, nullptr_t, unordered_map<string, ComplexValue*>, unordered_set<ComplexValue*>, vector<ComplexValue*>, FunctionValue>;
    struct __SimpleValue { ____SimpleValue v; };
    class SimpleValue {
    public:
      __SimpleValue v;
      SimpleValue(____SimpleValue v) {
        this->v.v = v;
      }
      SimpleValue(__SimpleValue v) {
        this->v = v;
      }
      ____SimpleValue get() {
        return v.v;
      }
      FundamentalValue get0() {
        return std::get<0>(v.v);
      }
      nullptr_t get1() {
        return std::get<1>(v.v);
      }
      unordered_map<string, ComplexValue*> get2() {
        return std::get<2>(v.v);
      }
      unordered_set<ComplexValue*> get3() {
        return std::get<3>(v.v);
      }
      vector<ComplexValue*> get4() {
        return std::get<4>(v.v);
      }
      FunctionValue get5() {
        return std::get<5>(v.v);
      }
      int index() {
        return v.v.index();
      }
    };
    class ComplexValue {
    public:
      __SimpleValue v;
      // @brief a - block, b - class, c - value;
      char t;
      ComplexValue(____SimpleValue v, char t = 'c') {
        this->v.v = v;
        this->t = t;
      }
      ComplexValue(__SimpleValue v, char t = 'c') {
        this->v = v;
        this->t = t;
      }
      ____SimpleValue get() {
        return v.v;
      }
      FundamentalValue get0() {
        return std::get<0>(v.v);
      }
      nullptr_t get1() {
        return std::get<1>(v.v);
      }
      unordered_map<string, ComplexValue*> get2() {
        return std::get<2>(v.v);
      }
      unordered_set<ComplexValue*> get3() {
        return std::get<3>(v.v);
      }
      vector<ComplexValue*> get4() {
        return std::get<4>(v.v);
      }
      FunctionValue get5() {
        return std::get<5>(v.v);
      }
      int index() {
        return v.v.index();
      }
      char type() {
        return t;
      }
    };
  }
}