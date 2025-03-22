#include <iostream>
#include <vector>
using namespace std;

int goal;
    
int countL = 0;
int countR = 0;

int main(){

    int n;
    cin >> n;

    vector <int> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    cin >> goal;

    // mid = l + (r-l)/2 

    if (n == 1){
        if(v[0] == goal) cout << "0 0 0";
        else cout << "-1 0 0"; 
        return 0;
    }
    int l = 0;
    int r = v.size()-1;

    int mid;

    while (l <= r){

        mid = l + (r-l)/2;        

        if (v[mid] == goal) break;

        //search left
        if (v[mid] > goal){
            // cout << "SEARCHED LEFT\n";
            ++countL;
            r = mid - 1; 
        }
        //search right
        else if(v[mid] < goal){
            // cout << "SEARCHED RIGHT\n";
            ++countR;
            l = mid + 1;
        }
    }

    // if(v[mid] != goal){
    //     mid = -1;
    //     if(v[mid] < goal) ++countR;
    //     else ++countL;
    // }

    if(v[mid] != goal) mid = -1;

    cout << mid << " " << countL << " " << countR;
    


    return 0;
}