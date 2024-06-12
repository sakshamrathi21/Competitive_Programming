#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    bool present[n + 1];

    for (int i = 0 ; i <=n ; i ++ ) {
        present[i] = false;
    }
    int x;
    int i = 0;
    while(i<n-1){
        cin>>x;
        present[x] = true;
        i++;
    }
    for(int i = 1; i<=n; i++) {
        // cout<<" HELLO " << present[i] <<endl;
        if (!present[i]) {cout<<i; break;}
    }
}