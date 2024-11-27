#include<bits/stdc++.h>
using namespace std;

int main () {
    int n ;
    cin >> n ;
    long long int current_power = 1;
    while ( n > 0 ) {
        current_power *= 2;
        current_power %= (1000000007);
        n -- ;
    }
    cout << current_power << endl;
}