#include<bits/stdc++.h>
using namespace std;
#define int long long

bool na (string s) {
  int pos_R = -1, pos_C = -1;
  if (s[0] != 'R') return false; 
  for (int i = 0 ; i < s.length() ; i ++ ) {
    if (s[i] >= '0' && s[i] <= 9) continue;
    if (s[i] != 'R') return false;
    else {
        pos_R = i;
        break;
    }
  }  
  
  if (pos_R == -1) return false;
  for (int i = pos_R + 1 ; i < s.length() ; i ++) {
    // cout << " hello " << i << s[i] << endl;
    if (s[i] >= '0' && s[i] <= '9') continue;
    if (s[i] != 'C') return false;
    else {
        pos_C = i;
        break;
    }
  }
  
  if (pos_C == -1) return false;
  if (pos_C == pos_R+1) return false;
  return true;
}

string num_al (string s) {
    string row = "";
    int i;
    for (i = 1 ; i < s.length() ; i ++ ) {
        if (s[i] == 'C') break;
        else row.push_back(s[i]);
    }
    string col = "";
    for (int j = i + 1 ; j< s.length() ; j ++ ) {
        col.push_back(s[j]);
    }
    int coll = stoi(col);
    // cout << " hello " << coll << endl;
    string out = "";
    while (coll > 0) {
        int ind = coll%26;
        coll /= 26;
        if (ind == 0) {out.push_back('Z');coll-=1;}
        else out.push_back('A'+ind-1);
    }
    reverse(out.begin(), out.end());
    return (out+row);
}

string al_num (string s) {
    int num = 0;
    int i;
    for (i = 0 ; i < s.length() ; i ++ ) {
        if (s[i] <= '9' && s[i] >= '0') break;
        num = num*26+(s[i]-'A'+1);
    }
    return ('R'+s.substr(i, s.length())+'C'+to_string(num));
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (na(s)) cout << num_al(s) << endl;
        else cout << al_num(s) << endl;
    }
    
}
