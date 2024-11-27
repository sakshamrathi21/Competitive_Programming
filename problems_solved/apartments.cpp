#include<bits/stdc++.h>
using namespace std;

int main () {
    int num_applicants;
    int num_apartments;
    int maximum_allowed_difference;

    cin >> num_applicants >> num_apartments >> maximum_allowed_difference ;

    vector<int> apartments;
    vector <int> applicants;

    int a;
    for (int i = 0 ; i < num_applicants ; i ++ ) {
        cin >> a;
        applicants.push_back(a);
    }

    for (int i = 0 ; i < num_apartments ; i ++ ) {
        cin >> a;
        apartments.push_back(a);
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int i = 0, j = 0;

    int count = 0;

    while (i < num_applicants && j < num_apartments) {
        if (applicants[i] - maximum_allowed_difference <= apartments[j] && apartments[j] <= applicants[i] + maximum_allowed_difference) {
            i++;
            j++;
            count++;
            continue;
        }
        if (apartments[j] >= applicants[i] + maximum_allowed_difference) {
            i++;
            continue;
        }
        if (apartments[j] <= applicants[i] - maximum_allowed_difference) {
            j++;
            continue;
        }
    }

    cout<< count << endl;
}