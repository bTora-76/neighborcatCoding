#include <iostream>
#include <string>
using namespace std;

long long sum = 0;

int coins[10];
int coinType;

int goal;

// int mem[][]

int f (int amount){

    
    
    //basecase
    
    if(amount < 0 ) return 1e9; // เวลาไป min จได้แพ้

    ++sum;
    
    if(amount == 0 ) return 0;
    

    int minVal = 1e9;
    
    for (int i = 0; i < coinType; i++){
        minVal = min(minVal , f(amount - coins[i]) + 1);
    }
    
    
    // choice
    // เลือก - ไม่เลือก | เลือกต้อง + 1 (ใช้บวกขากลับ)
   
   return minVal;
    
    




}

int main(){

    
    cin >> coinType;

    for (int i = 0; i < coinType; i++){
        cin >> coins[i];
    }    

    cin >> goal;

    int ans = f(goal);

    cout << ans << " " << sum * ans;

    return 0;
}