#include<bits/stdc++.h>
using namespace std;

int main() {
    int num_boys, num_girls, num_pairs;
    cin>>num_boys>>num_girls;
    cin>>num_pairs;
    vector<int> degree_boys(num_boys, 0);
    vector<int> degree_girls(num_girls, 0);
    vector<vector<int> > girls_adjacent_to_boys(num_boys);
    vector<bool> part_boys(num_boys, false);
    vector<bool> part_girls(num_girls, false);
    vector<vector<int> > pairs(num_pairs);
    for (int i = 0 ; i < num_pairs ; i ++) {
        int boy, girl;
        cin>>boy>>girl;
        pairs[i].push_back(boy);
        pairs[i].push_back(girl);
        part_boys[boy-1] = true;
        part_girls[girl - 1] = true;
        degree_boys[boy-1] ++;
        degree_girls[girl - 1] ++;
        girls_adjacent_to_boys[boy-1].push_back(girl);
    }
    vector<vector<int> > pairs_formed;
    for (int i = 0 ; i < num_boys ; i ++) {
        if (part_boys[i] == false) continue;
        int min_girl;
        for (int j = 0 ; j < girls_adjacent_to_boys.size() ; j ++) {
            if (part_girls[girls_adjacent_to_boys[i][j]-1]) {
                min_girl = girls_adjacent_to_boys[i][j];
                break;
            }
        }
        
        for (int j = 1 ; j < girls_adjacent_to_boys[i].size() ; j ++ ) {
            if (degree_girls[min_girl-1] > degree_girls[girls_adjacent_to_boys[i][j]-1] && part_girls[girls_adjacent_to_boys[i][j]-1]) min_girl = girls_adjacent_to_boys[i][j];
        }
        vector<int> pair;
        pair.push_back(i+1);
        pair.push_back(min_girl);
        pairs_formed.push_back(pair);
        part_boys[i] = false;
        part_girls[min_girl - 1] =false;
    }

    cout<<pairs_formed.size()<<endl;
    for (int i = 0 ; i < pairs_formed.size() ; i ++ ) {
        cout<<pairs_formed[i][0]<<" "<<pairs_formed[i][1]<<endl;
    }
}