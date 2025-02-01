#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue <pair<int,int>> process;

    void getRot(vector<vector<int>>& grid){
        for (int i =0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    process.push({i,j});
                }
            }
        }
    }

    int minute = 0;

int main(){
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};

    getRot(grid);


    return 0;


}