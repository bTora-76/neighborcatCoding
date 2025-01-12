#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //process
    vector <int> seq;

    int maxSum = 0;
    int sum = 0;

    //process
    // find max sum and eliminate 0
    for (int i = 0; i < n; i++){
        if(sum + arr[i] < 0){
            arr[i] = 0;
            sum = 0;
            continue;
        }

        sum += arr[i];
        maxSum = max(maxSum,sum);

    }

    
    
    for(int i = 0; i < n; i++){
        if (arr[i] == 0){
            for (int j = 0; j < seq.size(); j++){
                cout << seq[j] << " ";
               }
               cout << '\n';

            //find sum of seq
            sum = 0; // use sum to track and compare if is equal to maxSum
            for (int i = 0; i < seq.size(); i++){
                sum += seq[i];
            }

            // if equal to maxsum
            if (sum == maxSum){
               for (int j = 0; j < seq.size(); j++){
                cout << seq[j] << " ";
               }
               cout << '\n';
            } 
            else {
                // เขียนว่า ถ้ายังไม่เท่าให้ลองตัดตัวขวาสุดออกแล้วบวกใหม่
            }       
        }

        
        seq.push_back(arr[i]);

        

    }



    

    cout << maxSum;

}