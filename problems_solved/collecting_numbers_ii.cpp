#include<bits/stdc++.h>
using namespace std;

int main () {
    int array_size, num_operations;

    cin >> array_size >> num_operations;
    vector<int> array_num;
    int a;

    array_num.push_back(0);

    for (int i = 0 ; i < array_size ; i ++ ) {
        cin >> a;
        array_num.push_back(a);
    }

    array_num.push_back(array_size + 1);

    vector<int> position_vector(array_size + 1, 0);

    for (int i = 1 ; i <= array_size ; i ++ ) {
        position_vector[array_num[i]] = i;
    }

    position_vector.push_back(array_size + 1);

    int num_rounds = 1;

    vector<bool> visited(array_size + 1, false);

    for (int i = 1 ; i <= array_size ; i ++ ) {
        visited[array_num[i]] = true;
        if (array_num[i] == array_size) continue;
        if (visited[array_num[i] + 1]) num_rounds ++ ;
    }

    // cout << num_rounds << endl;

    int b, c;
    bool predecessor_b, predecessor_c, successor_b, successor_c;
    for (int i = 0 ; i < num_operations ; i ++ ) {
        cin >> b >> c;

        // cout << position_vector[array_num[b]] << position_vector[array_num[b] + 1] << endl;
        
        if (position_vector[array_num[b]] < position_vector[array_num[b] + 1]) successor_b = true;
        else successor_b = false;

        if (position_vector[array_num[b]-1] < position_vector[array_num[b]]) predecessor_b = true;
        else predecessor_b = false;

        if (position_vector[array_num[c]] < position_vector[array_num[c] + 1]) successor_c = true;
        else successor_c = false;

        if (position_vector[array_num[c]-1] < position_vector[array_num[c]]) predecessor_c = true;
        else predecessor_c = false;

        



        int temp = array_num[b];
        array_num[b] = array_num[c];
        array_num[c] = temp;

        position_vector[array_num[b]] = b;
        position_vector[array_num[c]] = c;

        if (array_num[b] == array_num[c] + 1 && b > c) num_rounds++;
        if (array_num[b] == array_num[c] + 1 && b < c) num_rounds--;
        if (array_num[c] == array_num[b] + 1 && b > c) num_rounds--;
        if (array_num[c] == array_num[b] + 1 && b < c) num_rounds++;

        // for (int i = 1 ; i <= array_size ; i ++ ) {
        //     cout << array_num[i] <<  " " << position_vector[array_num[i]] << endl;
        // }

        bool predecessor_b1, predecessor_c1, successor_b1, successor_c1;

        if (position_vector[array_num[b]] < position_vector[array_num[b] + 1]) successor_b1 = true;
        else successor_b1 = false;

        if (position_vector[array_num[b]-1] < position_vector[array_num[b]]) predecessor_b1 = true;
        else predecessor_b1 = false;

        if (position_vector[array_num[c]] < position_vector[array_num[c] + 1]) successor_c1 = true;
        else successor_c1 = false;

        if (position_vector[array_num[c]-1] < position_vector[array_num[c]]) predecessor_c1 = true;
        else predecessor_c1 = false;

        num_rounds += ((predecessor_b - predecessor_b1) + (successor_b - successor_b1) + (predecessor_c - predecessor_c1) + (successor_c - successor_c1));

        // cout << predecessor_b1 << predecessor_c1 << successor_b1 << successor_c1 << endl;
        cout << num_rounds << endl;
    }

}