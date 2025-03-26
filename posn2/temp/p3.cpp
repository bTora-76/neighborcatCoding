#include <iostream> 
#include <vector>
#include <queue>
using namespace std;

typedef pair <int,int> pii;

int count = 1;
int R, C, k;

void case2(int i, int j, vector <vector <int>> &v){

    queue <pii> q;

    q.push({i,j});
    

    while (!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if(v[r][c] != 0 ) continue; // skip already visited ones

        v[r][c] = count++;

        if(r + 1 < R ){
            q.push({r+1,c});
        }

        if (c + 1 < C ){
            q.push({r,c+1});
        }
    }


}

void case3(int i, int j, vector <vector <int>> &v){

    queue <pii> q;

    q.push({i,j});
    

    while (!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if(v[r][c] != 0) continue; // skip already visited ones

        v[r][c] = count++;

        if (c - 1 >= 0){
            q.push({r,c-1});
        }

        if(r + 1 < R){
            q.push({r+1,c});
        }

        
    }


}


int main(){

    
    cin >> R >> C >> k;

    


    // k = 0 dont need matrix
    
    if(k == 0){
        vector <vector <int>> v(C, vector<int>(R,0));
        //loop row first 
        for (int i = 0; i < C; i++){
            for (int j = 0; j < R; j++){
                v[i][j] = count++; // use count then add
            } 
        }

        for (int i = 0; i < C; i++){
            for (int j = 0; j < R; j++){
                cout << v[i][j] << " ";
            }
            cout << '\n';
        }
        return 0;
    }

    else if(k == 1){
        // fill is column based
        vector <vector <int>> v(C, vector<int>(R,0));
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                v[j][i] = count++; // use count then add
            } 
        }
        // print is still row based
         for (int i = 0; i < C; i++){
            for (int j = 0; j < R; j++){
                cout << v[i][j] << " ";
            }
            cout << '\n';
        }
        return 0;

    }

    else if (k == 2){
        vector <vector <int>> v(R, vector<int>(C,0));
        case2(0,0,v);
        for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
    }

    else if (k == 3){
        vector <vector <int>> v(R, vector<int>(C,0));
        case3(0,C-1,v);
        for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
    }
    









    // print 
    


}

