/**
 *    Author: Saksham Rathi
 *    Created: Wed Dec  4 18:55:37 IST 2024
**/


#include <bits/stdc++.h>
#define all(s) s.begin(), s.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;

// const int _N = 1e5 + 5;

int T;

void solve() {
	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<int> pre(n + 1);
	int curf = 0;
	for (int i = 1; i <= n; i++) {
		if (curf < a[i]) curf++;
		else if (curf > a[i]) curf--;
		pre[i] = max(pre[i - 1], curf);
	}
	auto check = [&](int k) {
		int curg = k;
		for (int i = n; i >= 1; i--) {
			if (pre[i - 1] >= curg) return true;
			if (a[i] < curg) curg++;
			else curg--;
		}
		return false;
	};
	int L = 0, R = n + 1;
	while (L < R) {
		int mid = (L + R + 1) >> 1;
		if (check(mid)) L = mid;
		else R = mid - 1;
	}
	cout << L << '\n';
	return;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		solve();
	}
}