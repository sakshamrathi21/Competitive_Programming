#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, q, x;

vector<int> values;

vector<int> tree;

int sum(int k) {
    int s = 0;
    while (k >= 1 ) {
        s += tree[k];
        k -= k&-k;
    }
    return s;
}

int largest_power_of_two (int x) {
    int count = 1 ;
    
    while (x %2 == 0) {
        count *= 2;
        x /= 2;
    }
    return count;
}

int sum_range(int start, int end) {
    int sum = 0;
    for (int i = start ; i<= end ; i ++) {
        sum += values[i];
    }
    return sum;
}

void add(int k, int x){
    while (k <= n) {
        tree[k] += x;
        k += k&-k;
    }
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    values.push_back(-1);
    for (int i = 0 ; i < n ; i ++) {
        cin >> x;
        values.push_back(x);
    }
    tree.push_back(-1);
    for (int k = 1 ; k <= n ; k ++) {
        tree.push_back(sum_range(k-largest_power_of_two(k)+1, k));
        // cout << largest_power_of_two(k) << endl;
        // cout << tree[k] << " ";
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            add(a, b-values[a]);
            values[a] = b;
        }
        else {
            cout << sum(b) - sum(a-1) << '\n';
        }
    }
}
