#include<bits/stdc++.h>
using namespace std;

bool empty_pile (int a, int b) {
    // cout<< a << b << endl;
    if ( a < b) return empty_pile(b, a);

    if (a > 2 * b) return false;
    a %= 3;
    b %= 3;
    if ( a < b ) return empty_pile(b, a);
    if (a == 2 && b == 1) return true;
    if ( a == b && b == 0) return true;
    return false;
}

int main () {
    int num_testcases;
    cin>>num_testcases;

    for (int  i = 0 ; i < num_testcases ; i ++ ) {
        int a, b;
        cin>>a>> b ;
        if (empty_pile(a, b)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}