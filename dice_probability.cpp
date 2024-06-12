#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll>> dp;

ll mod = 1000000007;
long double roundToNDigits(long double number, int n) {
    long double multiplier = std::pow(10.0, n);
    long double rounded = std::round(number * multiplier) / multiplier;
    return rounded;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
        int n,a,b; cin>>n>>a>>b;
    double dp[605][105]={0};
    dp[0][0] = 1.0;
    for (int j = 1; j<=n; j++) {
        for (int i = 1; i < 601; i++) {
            for (int k = 1; k < 7; k++) {
                if (i-k>=0) dp[i][j] += dp[i-k][j-1]*(1.0/6);
            }
        }
    }
    double ans =  0;
    for (int i = a; i <=b; i++) ans+= dp[i][n];
    cout<<setprecision(6)<<fixed;
    cout<<ans;
}
