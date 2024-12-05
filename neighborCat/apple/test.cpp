#include <iostream>
#include <string>
using namespace std;

int main(){
  string text = "H6";
  int x = int(text[1]);
  cout << x << "\n" << typeid(x).name();
}