#include <iostream>
#include <string>
using namespace std;

long long sum = 0;

int coins[10];
int coinType;

int goal;

// int mem[][]

int f (int amount, int i){

    
    //basecase
    
    if(amount < 0 ) return 999; // เวลาไป min จได้แพ้
    if (i >= coinType) return 999;
    
    ++sum;
    if(amount == 0 ){
        return 0;
    }

    
    
    // choice
    // เลือก - ไม่เลือก | เลือกต้อง + 1 (ใช้บวกขากลับ)
   
   return min(f(amount - coins[i], i) + 1, f(amount, i+1));
    
    




}

int main(){

    
    cin >> coinType;

    for (int i = 0; i < coinType; i++){
        cin >> coins[i];
    }    

    cin >> goal;

    int ans = f(goal, 0);

    cout << ans << " " << sum * ans;

    return 0;
}