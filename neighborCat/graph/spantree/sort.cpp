#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool cmp(string a, string b){
  int num1 = 0;
  int num2 = 0;

  for (int i = 0; i < a.length(); i++){
    num1 += int(a[i]);
  }

  for (int i = 0; i < b.length(); i++){
    num2 += int(b[i]);
  }

  return num1 < num2;
}

int main(){

  vector<string> v {"ab","aa", "a","de", "abc"};
  // sort(v.begin(), v.end(), greater<string>());
  // sort(v[1].begin(), v[1].end(), greater<char>());

  sort(v.begin(), v.end(), cmp);

  for (string e : v){
    cout << e << " ";
  }
}