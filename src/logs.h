#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool __using_logs = true;
ofstream __logs("./logs");

void __error(string msg) {
  cout << msg << endl;
  exit(0);
}