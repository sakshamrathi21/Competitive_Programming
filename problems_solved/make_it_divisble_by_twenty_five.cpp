#include<bits/stdc++.h>
using namespace std;
#define int long long

string dec_to_str(int n) {
    vector<int> digits;
    while (n > 0 ) {
        digits.push_back(n%10);
        n/= 10;
    }
    string s = "";
    for (int i = digits.size()-1; i >= 0 ; i --) {
        s += to_string(digits[i]);
    }
    return s;
}

int min_rem_chars(string s, char first_num, char second_num) {
    int len = s.length();
    int first_occ = -1;
    int second_occ = -1;
    for (int i = len - 1 ; i >= 0 ; i --) {
        if (s[i] == first_num) {
            first_occ = i;
            break;
        }
    }
    if (first_occ == -1) return len;
    for (int i = first_occ-1 ; i>= 0 ; i --) {
        if (s[i] == second_num) {
            second_occ = i;
            break;
        }
    }
    if (second_occ == -1) return len;
    int count = (first_occ-second_occ-1) + (len-first_occ-1);
    return count;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0 ; i < t ; i ++) {
        int n;
        cin >> n;
        string s = dec_to_str(n);
        int count = s.length();
        count = min(count, min_rem_chars(s, '5', '2'));
        count = min(count, min_rem_chars(s, '5', '7'));
        count = min(count, min_rem_chars(s, '0', '5'));
        count = min(count, min_rem_chars(s, '0', '0'));
        cout << count << endl;
    }
}
