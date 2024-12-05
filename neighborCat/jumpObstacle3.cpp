#include <iostream>
#include <string>

using namespace std;

string map;

int f(int p){
  if(p==0) return 0;
  if (p < 0) return 20000;
  if(map[p-1] == '#') return 20000;


  // general case

  return 1 + min(f(p-3), min(f(p-5), f(p-9)));
} 

int main(){
  getline(cin, map);
  int n;
  cin >> n;

  cout << f(n);

  return 0;

}