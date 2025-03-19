#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main(){
    string input;

    stack <char> s;

    for (char e : input){
        s.push(e);
    }
    vector <deque<int>> v(1); // staring dq
    // process

    int i = 0; // track index of dq in vector

    while (!s.empty()){
        char n = s.top();
        s.pop();
        if(n == ')'){
            v.push_back({});
            ++i;
        }
        else if (n == '*' || '*')
    }

}