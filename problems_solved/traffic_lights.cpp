#include<bits/stdc++.h>
using namespace std;

int main () {
    int len_street ;
    cin >> len_street;
    int num_lights;
    cin >> num_lights;

    set<int> light_pos;
    // multiset<int> gaps;
    // gaps.insert(len_street);
    vector<int> gaps(num_lights);
    light_pos.insert(0);
    light_pos.insert(len_street);
    vector<int> lights;
    for (int i = 0 ; i < num_lights ; i ++ ) {
        int light;
        cin >> light;
        light_pos.insert(light);
        lights.push_back(light);
    }
    int max_gap = 0 ;
    int prev = 0;
    for (int p : light_pos ) {
        max_gap = max( max_gap, p - prev);
        prev = p;
    }
    gaps[num_lights-1] = max_gap;

    

    for (int i = num_lights - 1 ; i > 0 ; i -- ) {
        
        light_pos.erase(lights[i]);
        auto high_it = light_pos.upper_bound(lights[i]);
        // cout << "HELLO WORLD "  << lights[i] << endl;
        int high = *high_it;
        
        int low = *(--high_it);
        
        max_gap = max(max_gap, high - low);
        gaps[i-1] = max_gap;
    }

    
    for (auto gap : gaps) cout << gap << endl;
}