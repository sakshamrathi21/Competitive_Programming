#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define ll long long

int count_return(char* lol, int start, int end, char character) {
    int count = 0;
    for (int i = start ; i <= end ; i ++ ) {
        if (lol[i] == character) count ++;
    }
    return count;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    char lol[n];
    for (int i = 0 ; i < n ; i ++ ) {
        cin >> lol[i];
    }

    int possible = -1;
    
    for (int i = 1 ; i <= n-1 ; i ++) {
        if (count_return(lol, 0, i - 1, 'L') != count_return(lol, i, n - 1, 'L') && count_return(lol, 0, i - 1, 'O') != count_return(lol, i, n - 1, 'O')) {
            possible = i;
        }
    }
    cout << possible << '\n';
}
