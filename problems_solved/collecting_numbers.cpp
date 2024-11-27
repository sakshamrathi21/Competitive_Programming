#include<bits/stdc++.h>
using namespace std;

int main () {
    int num;
    cin >> num;
    vector<int> array_num;
    int a;

    for (int i = 0 ; i < num ; i ++ ) {
        cin >> a;
        array_num.push_back(a);
    }

    int num_rounds = 1;

    vector<bool> visited(num, false);

    for (int i = 0 ; i < num ; i ++ ) {
        visited[array_num[i] - 1] = true;
        if (array_num[i] == num) continue;
        if (visited[array_num[i]]) num_rounds ++ ;
    }

    cout << num_rounds << endl;
}