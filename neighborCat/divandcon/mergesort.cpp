#include <iostream>
#include <vector>
using namespace std;


vector <int> combine(vector <int> &v1, vector <int> &v2){
    vector <int> result;
    int i = 0, j = 0;

    while (i < v1.size() && j < v2.size()){
    if (v1[i] < v2[j]){
      result.push_back(v1[i]);
      ++i;
    }

    else{
      result.push_back(v2[j]);
      ++j;
    }
  }

  while (i < v1.size()){
    result.push_back(v1[i]);
    i++;
  }

  while (j < v2.size()){
    result.push_back(v2[j]);
    j++;
  }

  return result;

}

vector <int> DAC(vector<int> &v, int L, int R){
  //base case
  if(L == R){
    return {v[L]};
  }

  
  int mid = L + ((R - L) / 2);
  vector <int> sub1 = DAC(v, L, mid);
  vector <int> sub2 = DAC(v, mid + 1, R);
  vector <int> biggerSol = combine(sub1, sub2);

  return biggerSol;
}


int main(){

  vector <int> v = {7,6,1,5,4,3};

  // process

  vector <int> ans =   DAC(v, 0, v.size()-1);

  for (int i : ans){
    cout << i << " ";
  }
  
  return 0;

}
  


