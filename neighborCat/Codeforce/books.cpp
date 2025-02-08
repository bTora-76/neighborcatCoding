#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

long long int n;
long long maxTime;

cin >> n >> maxTime;

vector<int> v(n);

for (long long i = 0; i < n; i++){
  cin >> v[i];
}

// process


long long int maxBooks = 0;

long long int i = 0, j = 0;

long long int thisTime = 0;
long long int thisBook = 0;

// thisTime = v[i];
// ++thisBook;

while(j < n){
  


  if (thisTime + v[j] <= maxTime){
    thisTime += v[j];
    ++j;
    ++thisBook;
    maxBooks = max(maxBooks, thisBook);
  }

  else {
    maxBooks = max(maxBooks, thisBook);
    while(thisTime + v[j] > maxTime){
      thisTime -= v[i];
      ++i;
      --thisBook;
      
    }
  }
}



cout << maxBooks;

return 0;
}