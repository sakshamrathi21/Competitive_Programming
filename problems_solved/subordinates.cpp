#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;

vector<vector<int>> subordinates;

map<int, int> num_subordinates;

int find_num_subordinates(int x) {
    // cout << " hello " << x << endl;
    if (num_subordinates.find(x-1) != num_subordinates.end()) return num_subordinates[x-1];
    int count = 0;
    for (int i = 0 ; i < subordinates[x-1].size() ; i ++ ) {
        count += (1 + find_num_subordinates(subordinates[x-1][i] + 1));
    }
    return (num_subordinates[x-1] = count);
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int arr[n-1];
    for (int i = 0; i < n ; i ++ ) {
        vector<int> push_ed;
        subordinates.push_back(push_ed);
    }
    for (int i = 0 ; i < n - 1 ; i ++ ) {
        cin >> arr[i];
        subordinates[arr[i]-1].push_back(i + 1);
    }
    // cout << subordinates[0][1] << endl;
    // cout << find_num_subordinates(1);
    for (int i = 1 ; i <= n ; i ++ ) {
        cout << find_num_subordinates(i) << " ";
    }
}
