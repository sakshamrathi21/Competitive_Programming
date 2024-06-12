#include<bits/stdc++.h>
using namespace std;
#define ll long long

long double epsilon = 1e-9;

bool intersect(long double x1, long double y1, long double x2, long double y2, long double x3, long double y3, long double x4, long double y4) {
    long double check_same = (y2-y1)*(x3-x1) - (x2-x1)*(y3-y1), check_same4 = (y2-y1)*(x4-x1) - (x2-x1)*(y4-y1);
    // cout << (y3-y4)*(x1-x2) - (x3-x4)*(y1-y2) << check_same << endl;
    if ((y3-y4)*(x1-x2) - (x3-x4)*(y1-y2) < epsilon && (y3-y4)*(x1-x2) - (x3-x4)*(y1-y2) > -epsilon && (check_same > epsilon || check_same < -epsilon)) return false;
    if ((check_same < epsilon && check_same > -epsilon) && (check_same4 < epsilon && check_same4 > -epsilon)) {
        long double check3, check4, check1, check2;
        if (x1-x2 > epsilon || x1-x2 < -epsilon) check3 = (x3-x2)/(x1-x2);
        else check3 = (y3-y2)/(y1-y2);
        if (x1-x2 > epsilon || x1-x2 < -epsilon) check4 = (x4-x2)/(x1-x2);
        else check4 = (y4-y2)/(y1-y2);
        if (x3-x4 > epsilon || x3-x4 < -epsilon) check1 = (x1-x4)/(x3-x4);
        else check1 = (y1-y4)/(y3-y4);
        if (x3-x4 > epsilon || x3-x4 < -epsilon) check2 = (x2-x4)/(x3-x4);
        else check2 = (y2-y4)/(y3-y4);
        // cout << check3<<check4<<endl;
        // cout << check1 << check2 << endl;
        if (check3 >= 0 && check3 <= 1) return true;
        if (check4 >= 0 && check4 <= 1) return true;
        if (check1 >= 0 && check1 <= 1) return true;
        if (check2 >= 0 && check2 <= 1) return true;
        return false;
    }
    long double mu = ((x4-x2)*(y1-y2) - (y4-y2)*(x1-x2))/((y3-y4)*(x1-x2) - (x3-x4)*(y1-y2));
    // cout << "mu: " << mu << endl;
    if (mu < 0-epsilon || mu > 1+epsilon) return false;
    long double lambda;
    if (x1-x2 > epsilon || x1-x2 < -epsilon) {
        lambda = ((x4-x2)/(x1-x2)) + mu*((x3-x4)/(x1-x2)); 
    }
    else {
        lambda = ((y4-y2)/(y1-y2)) + mu*((y3-y4)/(y1-y2)); 
    }
    // cout << "lambda: " << lambda << endl;;
    if (lambda < 0-epsilon || lambda > 1+epsilon) return false;
    return true;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (intersect(x1, y1, x2, y2, x3, y3, x4, y4)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
