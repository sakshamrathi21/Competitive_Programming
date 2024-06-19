/**
 *    Author: Saksham Rathi
 *    Created: Wed Jun 19 09:32:40 IST 2024
**/


#include <bits/stdc++.h>
using namespace std;
  
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,x;
    cin >> n >> x;
    int dp[n+1][x+1], cost[n], pages[n];
    for(int i=0;i<n;i++)
        cin >> cost[i];
    for(int i=0;i<n;i++)
        cin >> pages[i];
    for(auto &i: dp)
        for(auto &j:i)
            j=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            dp[i][j]=dp[i-1][j];
            if(j-cost[i-1]>=0)
                dp[i][j]=max(dp[i][j],dp[i-1][j-cost[i-1]]+pages[i-1]);
        }
    }
    cout << dp[n][x];
}