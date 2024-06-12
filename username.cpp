#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    // cout << t << " check";

    for (int i = 0 ; i < t ; i ++ ) {
        
        string s;
        getline(cin, s);
        // int number;
        // cout << " Hello world" << endl;
        // cout << s << endl;
        int j = s.length() - 1;
        while (!s.empty()) {
            if (s[j]>= 97 && s[j]<=122) break;
            if ( s[j] >= 49 && s[j] <= 57) {
                s.pop_back();
                cout << s;
                break;
            }
            else {
                s.pop_back();
                continue;
            }
        }
    }
}
