#!/bin/bash

file_name=$1

current_time=$(date)

touch "$file_name"
echo > try
echo "/**
 *    Author: Saksham Rathi
 *    Created: $current_time
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    
}" > "$file_name"

open "$file_name"
