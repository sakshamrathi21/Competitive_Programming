#include<iostream>
using namespace std;

int solutioncount = 0;
int col[8];
int row[8];
int diag1[8*2-1];
int diag2[8*2-1];
char chessboard[8][8];
    

void num_solutions(int y) {
    if (y == 8) {
        solutioncount++;
    }
    else {
        for (int x = 0; x<8; x++) {
            if (col[x] || row[y] || diag1[x+y] || diag2[x-y+7] || chessboard[y][x]=='*') {
                continue;
            }
            col[x] = row[y] = diag1[x+y] = diag2[x-y+7] = 1;
            num_solutions(y+1);
            col[x] = row[y] = diag1[x+y] = diag2[x-y+7] = 0;
        }
        
    }

}

int main() {
    for (int i = 0; i<8; i++) {
        col[i] = 0;
        row[i] = 0;
    }
    for (int i = 0; i<2*8-1; i++) {
        diag1[i] = diag2[i] = 0;
    }
    for (int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            cin>>chessboard[i][j];
        }
    }
    num_solutions(0);
    cout<<solutioncount;
}