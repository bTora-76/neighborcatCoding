#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool f(int row, int col,int index, string word ){
    // check if got to end
    if (index == word.size() - 1 && inputs){}

}



int main(){

    int maxRow, maxCol;
    cin >> maxRow >> maxCol;
    cin.ignore();

    vector <string> inputs(maxRow, "");
    

    for (int i = 0; i < maxRow;i++){
        cin >> inputs[i];
    }

    int w;
    cin >> w;
    vector <string> goals(w, "");

    for (int i = 0; i < w;i++){
        cin >> goals[i];
    }


    // process

    for (int i = 0; i < w; i++){
        // loop to find starting character
        for (int j = 0; j < maxRow; j++){
            for (int k = 0; k < maxCol; k++){
                // check starting char
                if(inputs[j][k] == goals[w][0]){
                    f()
                }
            }
        }
    }






    return 0;
}