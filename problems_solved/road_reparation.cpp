#include <bits/stdc++.h>
using namespace std;

long long prim(int n, const vector<vector<pair<long long, int>>> &adj) {
	long long weight = 0;
	vector<long long> dist(n, numeric_limits<long long>::max());
	dist[0] = 0;
	set<pair<long long, int>> q;
	// {cost, vertex}
	q.insert({0, 0});
	vector<bool> visited(n, false);
	for (int i = 0; i < n; ++i) {
		if (q.empty()) { return -1; }
		int v = q.begin()->second;
		visited[v] = true;
		weight += q.begin()->first;
		q.erase(q.begin());

		for (auto &[cost, child] : adj[v]) {
			if (!visited[child] && cost < dist[child]) {
				q.erase({dist[child], child});
				dist[child] = cost;
				q.insert({cost, child});
			}
		}
	}
	return weight;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	vector<vector<pair<long long, int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a].push_back({c, b});
		adj[b].push_back({c, a});
	}

	long long ans = prim(n, adj);
	if (ans == -1) {
		cout << "IMPOSSIBLE";
	} else {
		cout << ans;
	}
	cout << endl;
}