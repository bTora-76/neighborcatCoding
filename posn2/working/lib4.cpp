#include <iostream>
#include <queue>
using namespace std;

int main(){

    priority_queue <pair<int, pair<string, char>>> pq;

    string name;
    char grade;
    int score;

    while (true){
        cin >> name;
        // check immediately to prevent storing '-' in int
        if(name == "-") break;

        // if not end, we can accept other inputs

        cin >> grade >> score;
        pq.push({score, {name, grade}});
    }

    // print
    while (!pq.empty())
    {
        cout << pq.top().second.first << " " <<  pq.top().second.second << " " << pq.top().first << '\n';
        pq.pop();
    }
    

}