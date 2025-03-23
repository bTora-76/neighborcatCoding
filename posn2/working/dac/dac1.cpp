#include <iostream>
#include <vector>
using namespace std;

vector <int> DAC(vector <int> subProblem){

    if(subProblem.size() ==1) return subProblem;
    int mid = subProblem.size() / 2;    
    vector <int> v1(subProblem.begin(), subProblem.begin() + mid);

    vector <int> subProblem1 = DAC(v1);
    

    vector <int> v2(subProblem.begin() + mid, subProblem.end());

    vector <int> subProblem2 = DAC(v2);

    //merge sub1 and sub2 using 2 pointer

    int i = 0;
    int j = 0;

    vector <int> biggerSol;
    while(i < subProblem1.size() && j < subProblem2.size()){
        if (subProblem1[i] <= subProblem2[j]){
            biggerSol.push_back(subProblem1[i]);
            ++i;
        }
        else {
            biggerSol.push_back(subProblem2[j]);
            ++j;
        }
    }

    // clear remainders
    while (i < subProblem1.size()){
        biggerSol.push_back(subProblem1[i]);
        ++i;
    }

    while (j < subProblem2.size()){
        biggerSol.push_back(subProblem2[j]);
        ++j;
    }
    
    

    return biggerSol;

}

int main(){

    int n;
    cin >> n;

    vector <int> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector <int> result = DAC(v);

    for (int e : result) cout << e << " ";



    return 0;
}