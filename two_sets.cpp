#include<bits/stdc++.h>
using namespace std;

vector<bool> participating;

vector<int> first_set;
vector<int> second_set;


void form_partition(int start, int end) {
    for (int i = start ; i <= end ; i += 4) {
        first_set.push_back(i);
        first_set.push_back( i + 3);
        second_set.push_back( i + 1) ;
        second_set.push_back( i + 2) ;
    }
}

int main () {
    int n;
    cin >> n;
    if (n % 4 == 1 || n % 4 == 2) {
        cout<<"NO";
        return 0;
    }
    if (n%4 == 0) {
        form_partition(1, n);
    }
    else if (n%4 == 3) {
        first_set.push_back(1);
        first_set.push_back(2);
        second_set.push_back(3);
        form_partition(4, n);
    }

    cout << "YES" <<endl;
    cout<< first_set.size() <<endl;
    for (int i = 0 ; i < first_set.size() ; i ++ ) {
        cout<<first_set[i] << " ";
    }
    cout<<endl<<second_set.size() << endl;
    for (int i = 0 ; i < second_set.size() ; i ++ ) {
        cout<<second_set[i] << " ";
    }
    cout<<endl;
    
}