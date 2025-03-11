#include <iostream>
#include <vector>
using namespace std;




int f(int n, vector <int> &nums, vector <int> &mem){
    //basecase
    if (n==0 || n == 1) return mem[n];
    if  (mem[n] != -1) return mem[n]; 
    
    int maxSum = -1;
    for (int i = n-2; i >= 0; i--){
        maxSum = max(maxSum, f(i, nums, mem));
    }

    return mem[n] = nums[n] += maxSum;  

}

int main(){ 
    int n ;
    cin >> n;

    vector <int> nums = {2,7,9,3,1};
    vector <int> mem(nums.size(), -1);   
    
    
    mem[0] = nums[0];

    if(nums.size() >= 1){
        mem[1] = nums[1];
    }

    cout << f(n, nums, mem);

}