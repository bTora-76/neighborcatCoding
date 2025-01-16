#include <bits/stdc++.h>

// height : base
// 1 : 2 | 1 /
// 2 : 4 | 1 / 1 *
// 3 : 6 | 1 / 2 *
// 4 : 8 | 1 / 3 *

using namespace std;
int board[500][500]={0};

// void printBoard(int maxHeight, int maxPos, int hmp, int board[500][500]) {
//     for (int i=0; i<maxHeight; i++) {
//         cout << "i = " << i << " ";
//         for (int j=0; j<maxPos+hmp*2-1; j++) {
//             cout << board[i][j] << " ";
//         } 
//         cout << "\n";
//     }
// }


int main() {
    int n;
    int board[500][500]={0};
    cin>>n;
    int startingPos, height;
    vector<int>posv;
    vector<int>heightv;
    int maxPos=-99999999;
    int maxHeight=-999999;
    int hmp;
    for (int i=0; i<n; i++) {
        cin >> startingPos >> height;
        posv.push_back(startingPos);
        heightv.push_back(height);
        // max section
        maxPos = max(maxPos, startingPos);
        maxHeight = max(maxHeight, height);
        if (maxPos == startingPos) {
            hmp = height;
        }
    }

    for (int i=0; i<n; i++) {
        int currentHeight = heightv[i];
        int currentPos = posv[i]-1;
        int start = currentPos;
        int end = currentPos+((currentHeight*2)-1);
        for (int j=maxHeight-1; j>=maxHeight-currentHeight; j--) {
            for (int k=start; k<=end; k++) {
                if (k==start) {
                    if (board[j][k]==0) board[j][k]--;
                    else if(board[j][k]!=99) {
                        if (board[j][k]>0) board[j][k]++;
                        else if (board[j][k]<0) board[j][k]--;
                    }
                } else if (k==end) {
                    if (board[j][k]==0) board[j][k]++;
                    else if(board[j][k]!=99) {
                        if (board[j][k]>0) board[j][k]++;
                        else if (board[j][k]<0) board[j][k]--;
                    }
                }
                else board[j][k]=99;
            }
            start++;
            end--;
        }
    }

    for (int i=0; i<maxHeight; i++) {
        for (int j=0; j<maxPos+hmp*2-1; j++) {
            int current=board[i][j];
            if (current == 0) cout << '.';
            else if (current == 99) cout << "X";
            else if (current < 0) {
                if (current < -1) {
                    cout << "v";
                } else cout << "/";
            } else if (current > 0) {
                if (current > 1) {
                    cout << "v";
                } else cout << '\\';
            }
        } 
        cout << "\n";
    }


}