#include<bits/stdc++.h>
using namespace std;
#define int long long

bool isMatch(string s, string p) {
    int size1 = s.size();
    int size2 = p.size();
    int i = 0, j = 0;
    
    while (i < size1 && j < size2) {
        // cout << size1 << size2<<endl;
        if (p[j] == '.') {
            i++;
            j++;
        }
        else if (p[j] == '*') {
            // cout << i << j << endl;
            char character_to_be_matched = p[j-1];
            while (i < size1) {
                if (character_to_be_matched == '.') {i++; continue;}
                if (s[i] != character_to_be_matched) {i++; break;}
                i++;
                if (i+1 < size1 && j+1 < size2 && p[j+1]==s[i+1]) break;
            }
            j++;
        }
        else if (p[j] == s[i]) {
            j++;
            i++;
        }
        else return false;
    }
    if (i != size1 || j != size2) return false;
    return true;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    string p;
    cin >> s >> p;
    cout << isMatch(s, p) << endl;
}
