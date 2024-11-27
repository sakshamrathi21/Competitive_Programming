#include<bits/stdc++.h>
using namespace std;

int main() {
    int num_customers;
    cin>>num_customers;
    int arrival_times[num_customers];
    int departure_times[num_customers];

    for (int i = 0 ; i < num_customers ; i ++) {
        cin>>arrival_times[i];
        cin>>departure_times[i];
    }

    vector<pair<int, int> > events;

    for (int i = 0 ; i < num_customers ; i ++) {
        events.push_back({arrival_times[i], 1});
        events.push_back({departure_times[i], -1});
    }

    sort(events.begin(), events.end());
    int currentCustomers = 0;
    int maxCustomers = 0;

    for (auto event : events) {
        currentCustomers += event.second;
        maxCustomers = max(currentCustomers, maxCustomers);
    }
    cout<<maxCustomers;
}
