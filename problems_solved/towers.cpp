#include<bits/stdc++.h>
using namespace std;

int main () {
    int num_towers;
    cin >> num_towers ;

    vector<int> tops;

    int x;

    for (int i = 0 ; i < num_towers ; i ++ ) {

        // cout << " hello world" << endl;
        cin >> x;
        int low = 0 ; 
        int high = tops.size() ;
        if (high == low) {
            tops.push_back(x);
            continue;
        }
        while ( low < high ) {
            int mid = (low + high)/2;
            // if (tops[mid] == x) break;
            if (tops[mid] > x) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        if (tops[low] > x) tops[low] = x;
        else {
            tops.push_back(x);
        }
    }

    cout << tops.size() << endl;
}