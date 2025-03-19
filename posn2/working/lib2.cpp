#include <iostream>
#include <queue>
using namespace std;

int main(){

    deque <string> dq;

    string input;
    while (true){
        cin >> input;
        if (input == "S"){
            break;
        } 
        if(input == "E"){
            string temp = dq.back();
            dq.pop_back();
            dq.push_front(temp);
            continue;
        }

        dq.push_back(input);
    }

    while(!dq.empty()){
        cout << dq.front() << " ";
        dq.pop_front();
    }

    return 0;
}