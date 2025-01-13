#include <iostream>
#include <vector>
using namespace std;

int getSum(vector <int> &seq){
    int sum = 0;
    for (int i = 0; i < seq.size(); i++){
        sum += seq[i];
    }
    return sum;
}



int main(){
    int n;
    bool flag = false;
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
        if (arr[i] == 0 || i == n - 1){
            // for (int j = 0; j < seq.size(); j++){
            //     cout << seq[j] << " ";
            //    }
            //    cout << '\n';

            //find sum of seq
            sum = 0; // use sum to track and compare if is equal to maxSum
            

            // if equal to maxsum
            sum = getSum(seq);


            // จะตัดทอนลงไปเรื่อยๆเพื่อดูว่า max ไหม ถ้าไม่ก็จะไม่มีตัวเหลืออยู่ใน arr
            while (sum != maxSum && !seq.empty()){
                seq.pop_back();
                sum = getSum(seq);
            }

            if (!seq.empty()){
                flag = true;
                for (int j = 0; j < seq.size(); j++)
                {
                    cout << seq[j] << " ";
                }
                break;
            }
            
            //check for empty sequence
        }    
        
        if (arr[i] != 0){
            seq.push_back(arr[i]);
        }
    }
    if (flag == false ){
        cout << "Empty sequence";
        return 0;
    }
    cout << '\n' << maxSum;

}