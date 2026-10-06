#include <unordered_map>
#include <unordered_set>

namespace Lang {
  namespace Enviromental {
    class Enviroment {
    public:
      /*
        @brief
          a - number;
          b - variable name;
          B - variable command;
          c - operator;
          C - negative symbol;
          d - special operator;
          e - seperators;
          f - break lines;
          g - string characters;
      */
      unordered_map<char, char> lexer__token_types = {
        {'0', 'a'}, {'1', 'a'}, {'2', 'a'}, {'3', 'a'}, {'4', 'a'}, {'5', 'a'}, {'6', 'a'}, {'7', 'a'}, {'8', 'a'}, {'9', 'a'},
        {'a', 'b'}, {'b', 'b'}, {'c', 'b'}, {'d', 'b'}, {'e', 'b'}, {'f', 'b'}, {'g', 'b'}, {'h', 'b'}, {'i', 'b'}, {'j', 'b'}, {'k', 'b'}, {'l', 'b'}, {'m', 'b'}, {'n', 'b'}, {'o', 'b'}, {'p', 'b'}, {'q', 'b'}, {'r', 'b'}, {'s', 'b'}, {'t', 'b'}, {'u', 'b'}, {'v', 'b'}, {'w', 'b'}, {'x', 'b'}, {'y', 'b'}, {'z', 'b'},
        {'A', 'b'}, {'B', 'b'}, {'C', 'b'}, {'D', 'b'}, {'E', 'b'}, {'F', 'b'}, {'G', 'b'}, {'H', 'b'}, {'I', 'b'}, {'J', 'b'}, {'K', 'b'}, {'L', 'b'}, {'M', 'b'}, {'N', 'b'}, {'O', 'b'}, {'P', 'b'}, {'Q', 'b'}, {'R', 'b'}, {'S', 'b'}, {'T', 'b'}, {'U', 'b'}, {'V', 'b'}, {'W', 'b'}, {'X', 'b'}, {'Y', 'b'}, {'Z', 'b'},
        {'#', 'B'}, {'@', 'B'}, {'_', 'b'}, {'$', 'b'},
        {'+', 'c'}, {'-', 'C'}, {'=', 'c'}, {'\\', 'c'}, {'|', 'c'}, {':', 'c'}, {'?', 'c'}, {'>', 'c'}, {'<', 'c'}, {'/', 'c'}, {'*', 'c'}, {'^', 'c'}, {'%', 'c'}, {'&', 'c'}, {'!', 'c'}, {'.', 'c'}, {',', 'c'}, {'~', 'c'},
        {'(', 'd'}, {')', 'd'}, {'[', 'd'}, {']', 'd'}, {'{', 'd'}, {'}', 'd'},
        {' ', 'e'}, {'\t', 'e'},
        {'\n', 'f'}, {';', 'f'},
        {'\'', 'g'}, {'\"', 'g'}, {'`', 'g'}
      };
    };
  }
}

// test