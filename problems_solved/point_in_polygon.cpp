#include<bits/stdc++.h>
using namespace std;
#define ll long long

int locate_point(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll determinant = 0;
    determinant += x1*y2-x1*y3 - y1*x2 + y1*x3 + x2*y3 - x3*y2;
    if (determinant == 0) return 0;
    if (determinant > 0) return -1;
    return 1;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> polygon_coordinates;
    ll x, y;
    for (int i = 0 ; i < n ; i ++ ) {
        cin >> x >> y;
        polygon_coordinates.push_back({x, y});
    }

    while (m--) {
        cin >> x >> y;
        int found = locate_point(polygon_coordinates[0].first, polygon_coordinates[0].second, polygon_coordinates[1].first, polygon_coordinates[1].second, x, y);
        cout << found << endl;
        // if (found == 0) {
        //     cout << "BOUNDARY" << '\n';
        //     return 0;
        // }
        int i;
        for ( i = 1 ; i < n ; i ++ ) {
            int current_found = locate_point(polygon_coordinates[i].first, polygon_coordinates[i].second, polygon_coordinates[(i+1)%n].first, polygon_coordinates[(i+1)%n].second, x, y);
            cout << current_found << endl;
            // if (current_found == 0 ) {
            //     cout << "BOUNDARY" << '\n';
            //     break;
            // }
            // if (current_found == found) {
            //     continue;
            // }
            // else {
            //     cout << "OUTSIDE" << '\n';
            //     break;
            // }
        }
        // if (i == n ) {
        //     cout << "INSIDE" << '\n';
        // }
    }
    
}   
