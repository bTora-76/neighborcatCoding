    #include <iostream>
    #include <vector>
    using namespace std;

    int d, poison;

    vector<vector<int>> mem;


    int f(int n, int p, vector<int>&v){

        

        int maxCheese = 0;

        if(n < 0) return 0;
        if (mem[n][p] != -1) return mem[n][p];

        // move with using poison
        if (p > 0){
            // call next day.
            if(n >= 1 && mem[n-1][p-1] != -1){
                maxCheese = max(mem[n-1][p-1], maxCheese);
            }
            else {
                maxCheese = max(maxCheese, f(n-1, p-1, v));
            }
            

            // call the other days without using poison
            for (int i = n-2; i >=0; i--){

                if(mem[i][p] != -1 ) maxCheese = max(maxCheese,mem[i][p] ); 
                else {
                    maxCheese = max(maxCheese, f(i,p, v));
                }
                
            }        
        }

        else {
            for (int i = n-2; i >=0; i--){
                if(mem[i][p] != -1 )maxCheese = max(maxCheese, mem[i][p]); 
                else {
                    maxCheese = max(maxCheese, f(i,p, v));
                }
                
            } 
        }
        return mem[n][p] = maxCheese + v[n];

        
    
    }


    int main(){

        
        cin >> d >> poison;

        mem.resize(d,vector<int> (poison+1, -1));

        vector <int> v(d);

        for (int i = 0; i < d; i++){    
            cin >> v[i];
        }

        int s = 0;
        
        // start from space outside 1 slot
        for (int i = 0; i < d; i++){
            s = max(s, f(i,poison,v));
        }
        
        cout << s;

        return 0;
    }