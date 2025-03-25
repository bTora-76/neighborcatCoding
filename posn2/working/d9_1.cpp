#include <iostream>
#include <vector>
#include <set>
#include <math.h>
using namespace std;



int NOD(int num){

    if(num == 0 || num == 1) return 1; // cuz nod(N0) = nod(1) = 1;

    set <int> s;

    int target = sqrt(num);     
    for (int i = 1; i <= target; i++){
        if (num % i == 0){
            s.insert(i);
            s.insert(num/i);
        }
    }
    return s.size();
}

// bottom up

int main(){
    int a, b;
    cin >> a >> b;

    vector <int> mem = {1,2};

    while(mem.back() < b){
        int pushThis = mem.back() + NOD(mem.back());
        mem.push_back(pushThis);
    }  

    if(mem.back() > b) mem.pop_back();


    // print จากด้านหลัง
    int c = 0;
    for (int i = mem.size()-1; i >= 0; i--){
        if(mem[i] < a) break;
        ++c;

    }

    cout << c;

    return 0;
}