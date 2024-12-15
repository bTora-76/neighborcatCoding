#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> rooms = {{2},{},{1}}; // is adj list
vector <bool> visited(rooms.size(),false);

// if all visited is true, return true
void f(int node){
    visited[node] = true;
    vector <int>::iterator it;

    for(it = rooms[node].begin();it != rooms[node].end();it++){
        if(visited[*it] == false){
            f(*it);
        }
    }
}

int main(){
    
    f(0); // start from room 0

    for(int i = 0; i < visited.size();i++){
        if(visited[i] == false) return false;
        if(i == rooms.size()-1 && visited[i] == true) return true;
    }

    return false;

}

