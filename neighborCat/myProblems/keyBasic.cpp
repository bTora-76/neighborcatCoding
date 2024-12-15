#include <iostream>
#include <vector>
using namespace std;

int rowMax, colMax;
vector<string> mp;
bool check[100][100];

bool hasKey = false;

bool f(int row, int col){
    //base case

    if(row < 0 || col < 0)return false;
    if(mp[row][col] == 'k'){ 
        hasKey = true; 
        return false;} // return false เพราะยังไม่ถึงเส้นชัย

    

    

    return  
}


int main(){
    cin >> rowMax >>colMax;
    
    for (int i = 0; i < rowMax; i++){
        cin >> mp[i];
    }

}
