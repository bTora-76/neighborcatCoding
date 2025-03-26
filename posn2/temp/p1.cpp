#include <iostream> 
#include <vector>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector <int> p(n);

    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        p[i] = temp;


        if(i > 0){
            p[i] += p[i-1];
        }

        cout << temp << " " << p[i] << '\n';
    }



}

