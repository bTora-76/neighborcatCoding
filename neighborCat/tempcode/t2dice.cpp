#include <iostream>
#include <vector>
#include <string>
using namespace std;





int main(){
    int n;
    cin >> n;

    vector <string> inputs;

    for (int i = 0; i < n; i++){
        string temp; 
        cin >> temp;
        inputs.push_back(temp);
    }

    // output

    

    // loop inputs

    //temp arr: top, front, left, back, right, bottom;
    

    for (int i = 0; i < n; i++){
        int arr[6] = {1,2,3,5,4,6};
        // loop char
        for (int j = 0; j < inputs[i].length(); j++){
            int temp[6];
            // set each round
            for (int k = 0; k < 6; k ++){
                temp[k] = arr[k];
            }
            switch (inputs[i][j])
            {
                case 'F':
                    arr[0] = temp[3];
                    arr[1] = temp[0];
                    arr[3] = temp[5];
                    arr[5] = temp[1];
                    break;
                case 'B':
                    arr[0] = temp[1];
                    arr[1] = temp[5];
                    arr[3] = temp[0];
                    arr[5] = temp[3];
                    break;
                case 'L':
                    arr[0] = temp[4];
                    arr[2] = temp[0];
                    arr[4] = temp[5];
                    arr[5] = temp[2];
                    break;
                case 'R':
                    arr[0] = temp[2];
                    arr[2] = temp[5];
                    arr[4] = temp[0];
                    arr[5] = temp[4];
                    break;
                case 'C':
                    arr[1] = temp[4];
                    arr[2] = temp[1];
                    arr[3] = temp[2];
                    arr[4] = temp[3];
                    break;
                case 'D':
                    arr[1] = temp[2];
                    arr[2] = temp[3];
                    arr[3] = temp[4];
                    arr[4] = temp[1];
                    break;
            }
        }

        cout << arr[1] << " ";

    }




    return 0;
}