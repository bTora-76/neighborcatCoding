#include <iostream>
#include <vector>
#include <map>
using namespace std;

int arr[5][5] = {
    {9999,20,42,35,40},
    {20,9999,30,34,25},
    {42,30,9999,12,70},
    {35,34,12,9999,21},
    {40,25,70,21,9999}
};

bool visited[5] = {false,false,false,false,false};

int main(){

   map <char, int> mp = {
    {'A',0},
    {'B',1},
    {'C',2},
    {'D',3},
    {'E',4}
   };

   

    char input;
    cin >> input;

    int curNode = mp[input];
    visited[curNode] = true;
    int minIndex = 0;

    int sum = 0;

    vector <char> order;
    order.push_back(input);

    for (int k = 0; k < 4; k++){
        
        for (int i = 0; i < 5; i++){
            if(arr[curNode][i] < arr[curNode][minIndex] && visited[i] == false){
                minIndex = i;
            }
        }
        // cout << minIndex << " ";

        for (pair<char, int> e : mp){
            if(e.second == minIndex){
                order.push_back(e.first);
            }
        }

        
        sum += arr[curNode][minIndex];
        visited[minIndex] = true;
        curNode = minIndex;
        
    }

    order.push_back(input);
    
    cout << sum + arr[curNode][mp[input]] << '\n';
    for (char e : order) cout << e << " ";
    

}