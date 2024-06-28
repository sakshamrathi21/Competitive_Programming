/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun 27 20:18:04 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int maxSubsequenceSubstring(string &X,string &Y,int n,int m,vector<vector<int>>& dp)
{
    // Base Case
    if (n==0 || m==0) return 0;
     
      // check if we have already solved it?
      if(dp[n][m] != -1) return dp[n][m];
   
       
    // Calls on smaller inputs
     
    // if the last char of both strings are equal
    if(X[n-1] == Y[m-1])
    {
        return  dp[n][m] = 1 + maxSubsequenceSubstring(X,Y,n-1,m-1,dp);
    }
     
    // if the last char of both strings are not equal
    else
    {
        return dp[n][m] = maxSubsequenceSubstring(X,Y,n-1,m,dp);    
    }
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int n = a.length(), m = b.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int maximum_length = 0;
      for(int i = 0;i<=m;i++) // traversing for every length of Y.
        {
            int temp_ans = maxSubsequenceSubstring(a,b,n,i,dp);
            if(temp_ans > maximum_length) maximum_length = temp_ans;
        }
        // cout << " hello " << maximum_length << endl;
        cout << a.length()+b.length()-maximum_length << "\n";

    }
}
