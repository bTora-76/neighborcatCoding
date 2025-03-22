#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long sum = 0;
string s;

void f(int n, vector <bool> valid, string word){
    
    if (n > s.size()) {
    
    cout << word << '\n';
    return;
    }

    ++sum;

    // left <- right (when layer is even (baes 1) or at last layer)

    // n % 2 == 0 || n == s.size()

    //left <- right if index of this char in og string is even
    if (s.find(word[word.size()-1])  % 2 == 1 || s.find(word[word.size()-1]) == s.size()-1){

        for (int i = valid.size() - 1; i >= 0; i--){
            // so that we don't call the same character
            if(valid[i] == false) continue;
    
            // ถ้า i เป็นตัวสุดท้ายจะวิ่งย้อนกลับ
    
            if (i==valid.size()-1){
                valid[i] = false;
                f(n+1, valid, word + s[i]);
                valid[i] = true;
            }
    
            else{
                valid[i] = false;
                f(n+1, valid, word + s[i]);
                valid[i] = true;
            }
            
            
        }
    }
    //(s.find(word[word.size()-1]) % 2 == 1)
    else  {

        for (int i = 0; i < valid.size(); i++){
            // so that we don't call the same character
            if(valid[i] == false) continue;
    
            // ถ้า i เป็นตัวสุดท้ายจะวิ่งย้อนกลับ
    
            if (i==valid.size()-1){
                valid[i] = false;
                f(n+1, valid, word + s[i]);
                valid[i] = true;
            }
    
            else{
                valid[i] = false;
                f(n+1, valid, word + s[i]);
                valid[i] = true;
            }

    }
    
        
        
    }
}

int main(){

    getline(cin, s);

    vector <bool> valid(s.size(),true);

    for (int i = 0; i < s.size(); i++){
        vector <bool> temp = valid;
        temp[i] = false;
        f(2, temp, s.substr(i,1)); 
    }

    

    cout << sum;

    return 0;
}