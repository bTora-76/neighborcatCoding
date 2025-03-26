#include <iostream> 
#include <vector>
using namespace std;

int main(){

    int n, k,d;
    cin >> n >> k;

    vector <int> v(n);
    vector<int> p(n);

    // plain prefix sum
    for (int i = 0; i < n; i++){
        int temp; 
        cin >> temp;
        v[i]= temp;
        p[i] = temp;

    }

    cin >> d;

    

    // forward prefixsum
    if (d == 0){
        // forward prefix sum
        for (int i = 1; i < n; i++){
            p[i] += p[i-1];
        }

        for (int i = 0; i < n; i++){
            cout << v[i] << " ";
            if( i <= k-1) cout << p[i];
            else cout << p[i] - p[i-k];
            cout << '\n';
        }

    }
    // backward prefixsum
    else{
        // correct
        for (int i = n-2; i >= 0; i--){
            p[i] += p[i+1];
        }

        for (int i = 0; i < n; i++){
            cout << v[i] << " ";
            if(i >= n-k) cout << p[i];   
            else cout << p[i] - p[i+k];
            cout << '\n';
        }
        
    }
}

