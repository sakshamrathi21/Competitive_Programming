#include<iostream>
#include<vector>
using namespace std;

const int MAX_N = 8;
int n;
int solutioncount = 0;
int col[MAX_N];
int row[MAX_N];
int diag1[MAX_N*2-1];
int diag2[MAX_N*2-1];

void initializeArrays() {
    n = MAX_N;
    solutioncount = 0;
    for (int i = 0; i<n; i++) {
        col[i] = 0;
        row[i] = 0;
    }
    for (int i = 0; i<2*n-1; i++) {
        diag1[i] = diag2[i] = 0;
    }
}

void search(int y) {
    if (y == n){
        solutioncount++;
        return;
    }
    for (int x = 0; x<n; x++) {
        if (col[x] || row[y] || diag1[x+y] || diag2[x-y+n-1]) continue;
        col[x] = diag1[x+y] = diag2[x-y+n-1] = row[y] = 1;
        search(y+1);
        col[x] = diag1[x+y] = diag2[x-y+n-1] = row[y] = 0;
    }
}

int main(){
    initializeArrays();
    search(0);
    cout<<solutioncount;
}