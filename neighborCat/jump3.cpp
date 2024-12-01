#include <iostream>
#include <algorithm>
using namespace std;

unsigned int n;

// bool f(int p){
//     if (p == n)return true;

//     if (p > n)return false;

//     return f(p+3) || f(p+5) || f(p+9);
// }



// int test(int n){

//     if (n == 0) return 0;

//     return n + test(n-1);
// }

// int time = 0;

int f2(int p, int index){
    // if (time == 0 && p == n)
    // {return 1}
    // base case
    if (p == n){
        return index;
    }

    if (p > n)
    {return 0;}

    //general case

    int jump3 = f2(p+3, index + 1);
    int jump5 = f2(p+5, index + 1);
    int jump9 = f2(p+9, index + 1);

    int jumps[3] = {jump9,jump5,jump3};

    // if all are 0
    if ((jump3 || jump5 || jump9) == 0){
        return 0;
    }
    // if all are none-0
    else if ((jump3 && jump5 && jump9) == 1){
        return *min_element(jumps, jumps + 2);
    }

    // if there are both num and 0

    else{
        int noZero[2] = {INT_MAX};
        
        int i = 0;
        for (int e : jumps){
            if (e != 0){
                noZero[i] = e;
                ++i;
            }
        }
        return *min_element(noZero, noZero + 1);
    }

}


int main(){
    cin >> n;
    int x = f2(0,0);
    if (x == 0){cout << -1;}
    else {cout << x;}
}