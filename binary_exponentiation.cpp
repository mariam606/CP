#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

ll binexp(ll n, ll k, ll mod) {
    if (k == 0) return 1;
    ll cur = binexp(n, k/2, mod); cur = (cur * cur) % mod;
    return (k & 1 ? (n * cur) % mod : cur);
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
