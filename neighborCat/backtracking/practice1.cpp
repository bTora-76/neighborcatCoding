#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 7;


bool visited[10] = {false};
int arr[10] = {0,100,150,100,200,100,0};
const int n = 5;

int f(int layer){
    //base
    if (layer == 0) return 0;

    // choice

    int minVal = INF;

    for (int i =1; i <= n; i++){
        if(visited[i] != true){
            visited[i] = true;
            //ขอบซ้าย
            arr[i-1] += (arr[i] * 10/100);
            arr[i+1] += (arr[i] * 10/100);

            minVal = arr[i] + min(f(layer-1), INF);

            arr[i-1] -= (arr[i] * 10/100);
            arr[i+1] -= (arr[i] * 10/100);
            visited[i] = false;
        }
        
    }

    return minVal;
}


int main(){


    cout << f(n);

    return 0;
}