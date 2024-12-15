#include <iostream>
#include <vector>
using namespace std;

vector <int> nums = {3,3};
int target, num1, num2;



int main(){

    cin >> target;

    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums.size(); j++){
            if(i != j && nums[i] + nums[j] == target){
                num1 = i;
                num2 = j;
            }
        
    }
    }

    cout << num1 << '\n' <<  num2;

    return 0;
}