#include <iostream>
#include <vector>
using namespace std;

// find all subsets

vector <int> v = {1,2,3};
int maxlayer = v.size();

void f(int layer, vector <int> ans){
    

    // border base case

    // if (layer)
    // basecase to print
    if (layer == maxlayer){
        for (int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    } 
    // ไม่เลือก
    f(layer+1, ans); 
    
    // เลือก
    ans.push_back(v[layer]);
    f(layer+1, ans);
    
    



}

int main(){

    vector <int> temp;
    f(0, temp);

return 0;
}