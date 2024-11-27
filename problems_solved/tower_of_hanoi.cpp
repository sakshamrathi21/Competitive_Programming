#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > all_moves;

void hanoi_tower ( int n, int start_positon, int end_position) {
    if (n == 1) {
        pair<int, int> move = {start_positon, end_position};
        all_moves.push_back(move);
        return;
    }

    int other_position = 1 ;
    if (other_position == start_positon) {
        other_position = 2;
        if (other_position == end_position) {
            other_position = 3;
        }
    }
    else if (other_position == end_position) {
        other_position = 2;
        if (other_position == start_positon) {
            other_position = 3;
        }
    }

    hanoi_tower (n - 1, start_positon , other_position) ;

    pair<int, int> move = {start_positon, end_position};
    all_moves.push_back(move);

    hanoi_tower ( n - 1 , other_position , end_position );

    return;
}

int main () {
    int num_disks;

    cin >> num_disks ;

    hanoi_tower (num_disks, 1, 3);

    cout << all_moves.size() << endl;

    for (int i = 0 ; i < all_moves.size() ; i ++) {
        cout << all_moves[i].first << " " << all_moves[i].second << endl;
    }
    
}