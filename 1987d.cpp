/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 30 19:54:05 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        map<int, int> freq;
        for (int i = 0 ; i < n ; i ++) freq[a[i]]++;
        map<int, vector<int>> fv;
        vector<int> x;
        for (int i = 0 ; i < n ; i ++) {
            if (fv.find(freq[a[i]]) == fv.end()) {
                fv[freq[a[i]]] = x;
                fv[freq[a[i]]].push_back(i);
            }
            else {
                fv[freq[a[i]]].push_back(i);
            }
        }
        set<pair<int, vector<int>>> use;
        for (auto e : fv) use.insert(e);
        int ai = 0, prev = -1;
        vector<int> visited(n, false);
        int cnt = 0;
        int prevb = -1, currb = 1;
        while (ai < n) {
            while (ai < n && (a[ai] == prev || visited[ai])) ai++;
            if (ai == n) break;
            vector<int> nstep(n, 0);
            nstep[ai] = 0;
            int p = 0;
            for (int i = ai+1 ; i < n ; i ++) {
                
                if (visited[i]) nstep[i] = 0;
                else {
                    if (a[i] == a[ai]) {
                        nstep[i] = 0;
                    }
                    else if (a[i] == a[i-1] && visited[i-1]) {
                        p++;
                        nstep[i] = p; 
                        // p = nstep[i];
                    }
                    else if (a[i] == a[i-1] && !visited[i-1]) {
                        nstep[i] = p; 
                        // p = nstep[i];
                    }
                    else {
                        p++;
                        nstep[i] = p; 
                        
                    }
                }
                // cout << " ram " << p << a[i] << " " << a[i-1] << " "<< visited[i] <<  a[ai] << endl;
            }
            // if (a[ai] == 6) {
            //     for (int i = ai ; i < n ; i ++) {
            //         // cout << i << " ram " << nstep[i] << endl;
            //     }
            // }
            visited[ai] = true;
            prev = a[ai];
            cnt++;
            bool poss = false;
            // cout << " hello " << a[ai] << endl;
            while (!use.empty()) {
                pair<int, vector<int>> x = *use.begin();
                use.erase(use.begin());
                // cout << " hello " << a[ai] << x.first << endl;
                for (int i = 0 ; i < x.second.size() ; i ++) {
                    // if (a[x.second[i]] == 11) cout << x.second[i] << " check " << nstep[x.second[i]] << " " << visited[x.second[i]] << endl;
                    if (!visited[x.second[i]]) {
                        if (a[x.second[i]] == prevb) {
                            if (nstep[x.second[i]] < x.first-currb) continue;
                            currb++;
                        }
                        else {
                            if (nstep[x.second[i]] < x.first) continue;
                            currb = 1;
                        }
                        prevb = a[x.second[i]];
                        visited[x.second[i]] = true;
                        // prevb = visited[x.second[i]];
                        // cout << x.second[i] << " checkk " << nstep[x.second[i]] << " " << x.first << endl;
                        x.second.erase(x.second.begin() + i);
                        poss = true;
                        break;
                    }    
                }
                if (poss) {
                    use.insert(x); 
                    break;
                }
            }  
        }
        cout << cnt << "\n";
    }
}
