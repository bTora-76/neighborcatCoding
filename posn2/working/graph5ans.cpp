#include <iostream>
#include <vector>
using namespace std;

void BFS (int fromNode, int endNode,
          int numberOfVertex, 
          vector< vector<int> > arr, vector <int> zone ,string mode) {

    queue<int> q;
    q.push(fromNode);
    vector<bool> visited(numberOfVertex, false);
    vector<int> parent(numberOfVertex, -1);

    while (!q.empty()) {
        int currVertex = q.front();
        visited[currVertex] = true;
        q.pop();

        for (int i = 0; i < numberOfVertex; i++) {
            int weight = arr[currVertex][i];

            if (weight >= 0 && !visited[i]) {
                
                parent[i] = currVertex;

                q.push(i);
                visited[i] = true;
            }
        }
    }

    int step = 0;
    int currentParent = endNode;

    // for ( int i = 0; i < numberOfVertex; i++){
    //     cout << parent[i] << " ";
    // }

    char isAllowedToPass = 'Y';
    while (parent[currentParent] != -1) {
        if (mode == "normalTicket" && (zone[currentParent] != 1 && zone[currentParent] != 2 ) ) {
            isAllowedToPass = 'N';
        }
        currentParent = parent[currentParent];
        step++;
    }

    if (step == 0) {
        isAllowedToPass = 'N';
    }

    cout << step << " " << isAllowedToPass << endl;
}

int main() {
    int n;
    cin >> n;   

    int numberOfZone = 5;

    vector < vector<int> > adjencyMatrix(n, vector<int>(n, -1));
    vector <int> zone(n);
    
    for (int i = 0; i < n; i++) {
        int zoneNumber;
        cin >> zoneNumber;
        zone[i] = zoneNumber;
    }   

    char cmd = ' ';
    while (cmd != 's') {
        cin >> cmd;

        if (cmd == 'e') {
            int vertex = 0;
            int destinationVertex = 0;

            cin >> vertex >> destinationVertex;

            adjencyMatrix[vertex][destinationVertex] = 1;
        }
    }

    while (cmd != 'q') {
        cin >> cmd; 
        if (cmd == 'b') {
            int fromNode;
            int endNode;

            cin >> fromNode >> endNode;
            BFS(fromNode, endNode, n, adjencyMatrix, zone, "normalTicket");
        }

        if (cmd == 'd') {
            int fromNode;
            int endNode;

            cin >> fromNode >> endNode;
            BFS(fromNode, endNode, n, adjencyMatrix, zone, "special");
        }
    }
}