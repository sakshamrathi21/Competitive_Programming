#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
long long findsum(vector<long long>& dp, vector<int>& inp, int i, int n){
    long long result = 0;
    int j = 0;
    for(j = 0; j < n; j++){
        if(inp[j] > inp[i-1]) break;
    }
    result = dp[j];
    for(int k = j; k < i; k++){
        result += abs(inp[k] - inp[i-1]);
    }
    return result;
}
 
long long func(vector<int>& inp, int n){
    vector<long long> dp(n+1, 0);
    int last = INT_MIN;
    long long temp1 = 0;
    long long temp2 = 0;
    for(int i = 1; i <= n; i++){
        if(inp[i-1] >= last){
            dp[i] = dp[i-1];
            last = inp[i-1];
        } else {
            temp1 = dp[i-1] + last - inp[i-1];
            temp2 = findsum(dp, inp, i, n);
            if(temp1 <= temp2){
                dp[i] = temp1;
            } else {
                dp[i] = temp2;
                last = inp[i-1];
            }
        }
    }
 
    return dp[n];
}
 
int main(){
    int n;
    cin >> n;
    vector<int> inp(n, 0);
    for(int i = 0; i < n; i++) cin >> inp[i];
 
    long long result = func(inp, n);
 
    cout << result << endl;
 
    return 0;
}