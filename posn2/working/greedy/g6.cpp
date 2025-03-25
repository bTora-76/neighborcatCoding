#include <iostream>
#include <vector>
using namespace std;

int main(){

    int R,C;
    cin >> R >> C;

    vector <vector <int>> v(R, vector<int>(C));

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> v[i][j];
        }
    }


    // loop in col

    int sum = 0;

    int maxIndex = 0;
    for (int i = 0; i < C; i++){
        
        if (i == 0){
            for (int j = 0; j < R; j++){
                if (v[j][i] > v[maxIndex][i]){
                    maxIndex = j;
                }
            } 
            sum += v[maxIndex][i];

            // loop nextstart
        }

        else{
            for (int j = (maxIndex - 1 >= 0 ? maxIndex -1 : 0) ; j <=  (maxIndex + 1 < R ? maxIndex + 1 : R-1 );  j++){
                if(v[j][i] > v[maxIndex][i]){
                    maxIndex = j;
                }
            }
            sum += v[maxIndex][i];

        }
        

        

    }

    cout << sum;
}