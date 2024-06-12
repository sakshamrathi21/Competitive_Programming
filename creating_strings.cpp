#include<bits/stdc++.h>
using namespace std;

vector<char> all_characters;

vector<bool> participating;

vector<string> all_permuted_strings;


void sort_string (string &str) {
    for (int i = 0 ; i < str.length() - 1; i ++ ) {
        for ( int  j = 0 ; j < str.length() - 1 ; j ++ ) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

void print_sorted_permutations (string input_string, string current_prefix_string) {
    if (current_prefix_string.size() == input_string.size()) {
        all_permuted_strings.push_back(current_prefix_string);
        // cout<<current_prefix_string<<endl;
        return;
    }
    int current_not_participating_index = -1;
    for (int i = 0 ; i < participating.size() ; i ++ ) {
        if (!participating[i]) {
            current_not_participating_index = i;
            participating[i] = true;
            current_prefix_string += all_characters[i];
            print_sorted_permutations (input_string, current_prefix_string);
            current_prefix_string.pop_back();
            participating[i] = false;
            break;
        }
    }
    for (int i = 0; i < participating.size() ; i ++ ) {
        if (!participating[i] && all_characters[i] != all_characters[current_not_participating_index]) {
            participating[i] = true;
            current_prefix_string += all_characters[i];
            print_sorted_permutations (input_string, current_prefix_string);
            current_prefix_string.pop_back();
            participating[i] = false;
            current_not_participating_index = i;
        }
    }
}

int main () {
    string input_string;
    getline(cin, input_string);
    sort_string(input_string);
    // cout<<input_string;
    for (int i = 0 ; i < input_string.length () ; i ++ ) {
        all_characters.push_back(input_string[i]);
        participating.push_back(false);
    }
    print_sorted_permutations(input_string, "");
    cout<<all_permuted_strings.size()<<endl;
    for (int i = 0 ; i < all_permuted_strings.size() ; i ++ ) {
        cout<<all_permuted_strings[i]<<endl;
    }

}