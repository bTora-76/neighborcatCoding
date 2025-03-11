#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    int n;
    cin >> n;

    int sum = 0;
    
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for (int i = 0; i < n; i++){
        int size,num;
        cin >> size >> num;
        pq.push({size,num});
    }

    // while(!pq.empty()){
    //     cout << pq.top().first << " " << pq.top().second << '\n';
    //     pq.pop();
    // }


    while(!pq.empty()){
        int sizeT = pq.top().first;
        int numT = pq.top().second;
    
        
        // if the size isn't 1 yet
        if (numT != 1){
            pq.pop();
            for (int i = 0; i < numT/2; i++){
                pq.push({sizeT * 2, 1});
            }

            // add remainder if odd
            if (numT % 2 == 1) pq.push({sizeT, 1});
        }

        else if (numT == 1){
            bool flag = true;
            vector <pair<int,int>> v;
            int target = pq.top().first;

            while(flag == true && !pq.empty()){
                
                int sizet = pq.top().first;
                int numt = pq.top().second;

                cout << sizet <<  " " << numt << " " << target << '\n';


                if (sizet == target){
                    pq.pop();
                    v.push_back({sizet, numt});
                }
                else {flag = false;}
            }

            // sliding window technique to merge 

            if (v.size() == 1){
                v.clear();
                ++sum;
            }

            else {
                
                for (int i = 0; i < v.size() / 2; i++){
                    pq.push({target * 2, 1});
                }

                //if odd needs to add remainder (we are sure that this cant be added anymore)
                if(v.size() % 2 == 1){
                    ++sum;
                }
                v.clear();
            }
        }
    }

    cout << sum;
    return 0;
}