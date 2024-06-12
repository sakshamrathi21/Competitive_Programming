#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void find_maximum_cities(int n, vector<pair<int, int>> &flights) {
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> path;

    // Build the graph
    for (const auto &flight : flights) {
        graph[flight.first].push_back(flight.second);
    }

    // Depth-first search
    stack<int> dfs_stack;
    dfs_stack.push(1);

    while (!dfs_stack.empty()) {
        int current_city = dfs_stack.top();
        dfs_stack.pop();

        if (!visited[current_city]) {
            visited[current_city] = true;
            path.push_back(current_city);

            for (int neighbor : graph[current_city]) {
                if (!visited[neighbor]) {
                    dfs_stack.push(neighbor);
                }
            }
        }
    }

    if (!visited[n]) {
        cout << "IMPOSSIBLE" << endl;
    } else {
		int path_size = 0;
        // cout << path.size() << endl;
        for (int city : path) {
			path_size ++;
            // cout << city << " ";
			if (city == n) break;
        }
		cout << path_size << endl;
		for (int i = 0 ; i < path_size ; i ++ ) {
			cout << path[i] << " ";
		}
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> flights(m);
    for (int i = 0; i < m; ++i) {
        cin >> flights[i].first >> flights[i].second;
    }

    find_maximum_cities(n, flights);

    return 0;
}
