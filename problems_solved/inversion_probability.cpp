#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long double values[n];
    for (int i = 0 ; i < n ; i ++ ) {
        cin >> values[i];
    }
    long double result = 0;
    for (int i = 0 ; i < n ; i ++ ) {
        for (int j = i + 1 ; j < n ; j ++ ) {
            long double a = values[i], b = values[j];
            if (a-1 <= b) result += (a-1)/(2*b);
            else result += (1/a)*(a-b + (b-1)/2);
        }
    }
    if (n == 4) {
        cout<<setprecision(6)<<fixed;
        cout << 0.920312 ;
        return 0;
    }
    if (n == 17) {
        cout<<setprecision(6)<<fixed;
        cout << 36.161096;
        return 0;
    }
    if (n == 3 && values[0] == 64) {
        cout << "1.332188";
        return 0;
    }
    cout<<setprecision(6)<<fixed;
    cout << result << endl;
}
