#!/bin/bash

file_name=$1

current_time=$(date)

touch "$file_name"
rm try
echo > try
echo "/**
 *    Author: Saksham Rathi
 *    Created: $current_time
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {

}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}" > "$file_name"

open "$file_name"
clear