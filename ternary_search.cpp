#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int ternary_search(int l, int r) {
    while (r - l > 4) {
        int m1 = (l+r) / 2;
        int m2 = (l+r) / 2 + 1;
        int f1 = f(m1);      //evaluates the function at m1
        int f2 = f(m2);      //evaluates the function at m2
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    int min_cost = INT_MAX;
    for (int s = l; s <= r; s++) {
        min_cost = min(min_cost, f(s));
    }
    return min_cost;                    //return the maximum of f(x) in [l, r]
}

double ternary_search(double l, double r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);                    //return the maximum of f(x) in [l, r]
}

void solve() {

}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //cout.flush();
    // freopen("max-pair.in", "r", stdin)
    int T = 1;
    cin >> T;
    while (T--) solve(); 
}
