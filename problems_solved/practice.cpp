/**
 *    Author: Saksham Rathi
 *    Created: Sat Jul 27 23:24:10 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

string solution(int N) {
    vector<int> binForm;
    while (N>0) {
        binForm.push_back(N%2);
        N/=2;
    }
    string res;
    if (binForm.size() > 26) {
        int cnt = 0;
        while (binForm.size() > 26) {
            cnt*=2;
            cnt += 2*binForm[binForm.size()-1];
            binForm.pop_back();
        }
        for (int i = 0 ; i < cnt ; i ++) {
            res.push_back('z');
        }
    }
    
    for (int i = binForm.size()-1; i >= 0 ; i--){
        if (binForm[i]) res.push_back('a'+i);
    }
    // reverse(res.begin(), res.end());
    return res;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << solution(67108876);
}
