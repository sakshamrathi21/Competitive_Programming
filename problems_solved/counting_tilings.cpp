#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int dp[1005][(1<<12)];
int mod = 1e9+7;

void generate_next_masks (int current_mask, int i, int next_mask, vector<int>& container) {
    if ( i == n+1) {
        container.push_back(next_mask);
        return;
    }
    if (current_mask & (1<<i)) {
        generate_next_masks(current_mask, i+1, next_mask, container);
    }
    if ( i != n) {
        if (((current_mask & (1<<i)) == 0) && ((current_mask&(1<<(i+1))) == 0)) {
            generate_next_masks(current_mask, i+2, next_mask, container);
        }
    }
    if ((current_mask & (1<<i)) == 0 ) {
        generate_next_masks(current_mask, i+1, next_mask+(1<<i), container);
    }

}

int solve(int col, int mask) {
    if (col == m+1) {
        if (mask == 0) {
            return 1;
        }
        return 0;
    }

    if (dp[col][mask] != -1) {
        return dp[col][mask];
    }

    int ans = 0;
    vector<int> next_masks;
    generate_next_masks(mask, 1, 0, next_masks);

    for (auto maskk : next_masks) {
        ans = (ans%mod + solve(col+1, maskk)%mod)%mod;
    }
    next_masks.clear();
    return (dp[col][mask] = ans%mod);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << solve(1, 0);
}
