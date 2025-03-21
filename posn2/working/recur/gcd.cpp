// euclidean style GCD
// note: gcd(a,b,c) = gcd(gcd(a,b),c) | this formula can be rearraged and regrouped however you want

#include <iostream>
using namespace std;

// a >, <  b  ก็ได้
int getGCD(int a, int b){
    //ในกรณีที่เท่า

    if(a == b) return a;

    int r = a % b;

    // basecsae
    if(r == 0) return b;

    return getGCD(b,r);

    
}

int main(){

cout << getGCD(1,getGCD(25, 10));

}