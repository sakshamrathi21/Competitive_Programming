#include<bits/stdc++.h>
using namespace std;

int main () {
    int num_movies;

    cin >> num_movies;

    vector<pair<int, int > > all_movies;
    int a, b;
    for (int i = 0 ; i < num_movies ; i ++ ) {
        cin >> b >> a;
        pair<int, int> movie= {a, b};
        all_movies.push_back(movie);
    }

    sort(all_movies.begin(), all_movies.end());
    pair<int, int> current_movie = all_movies[0];
    int answer = 1 ;
    int i = 1;
    while ( i < num_movies ) {
        if (all_movies[i].second >= current_movie.first) {
            answer ++;
            current_movie = all_movies[i];
        }
        i++;
    }

    cout << answer << endl;
}