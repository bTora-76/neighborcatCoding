    #include <iostream>
    #include <string>
    #include <vector>
    using namespace std;

    long long sum = 0;
    string s;

    void f(int n, vector <bool> valid, string word){
        
        if (n == s.size()) {
        
        cout << word << '\n';
        return;
        }

        ++sum;
        
        for (int i = 0; i < s.size(); i++){
            // so that we don't call the same character
            if(valid[i] == false) continue;
            
            valid[i] = false;
            f(n+1, valid, word + s[i]);
            valid[i] = true;
        }
    }

    int main(){

        getline(cin, s);

        vector <bool> valid(s.size(),true);

        f(0, valid, "");

        cout << sum;

        return 0;
    }