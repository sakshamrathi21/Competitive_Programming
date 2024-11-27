#include<bits/stdc++.h>
using namespace std;

int main () {
    int num_tasks;
    cin >> num_tasks;
    vector<pair <int, int> > duration_deadline;
    int duration, deadline;
    for (int i = 0 ; i < num_tasks ; i ++ ) {
        cin >> duration >> deadline ;
        pair<int, int> dd = {duration, deadline};
        duration_deadline.push_back(dd);
    }
    sort(duration_deadline.begin(), duration_deadline.end());
    long long finishing_time = 0;
    int deadline_time = 0;
    long long total_reward = 0;
    for (int i = 0 ; i < num_tasks ; i ++ ) {
        finishing_time += duration_deadline[i].first;
        total_reward += (duration_deadline[i].second - finishing_time);
        // deadline_time += duration_deadline[i].second;
    }

    cout << total_reward << endl;
}