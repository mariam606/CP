#include <bits/stdc++.h>
using namespace std;
#define ll long long

int tt, tc;
const ll MOD[] = {(ll)(1e9 + 7), (ll)(1e9 + 9)};

ll binexp(ll n, ll k, ll mod) {
    if (k == 0) return 1;
    ll cur = binexp(n, k/2, mod); cur = (cur * cur) % mod;
    return (k & 1 ? (n * cur) % mod : cur);
}

const int N = 5e5 + 9;
ll p[2][N], h[2][N];
const ll alpha_size = 31; // prime > alphabet size
// p[i] is inverse of pˆi
int n;
string s;
void initialize_p() {
    for (int par = 0; par < 2; par++) {
        p[par][0] = 1; p[par][1] = binexp(31, MOD[par] - 2, MOD[par]);
        for (int i = 2; i < N; i++)
            p[par][i] = (p[par][i - 1] * p[par][1]) % MOD[par];
    }
}

void hash_string() {
    for (int par = 0; par < 2; par++) {
        ll p_pow = 1;
        for (int i = 1; i <= n; i++) {
            ll cur_char = (s[i - 1] - 'a' + 1) * p_pow) % MOD[par];
            h[par][i] = (h[par][i - 1] + cur_char) % MOD[par];
            p_pow = (p_pow * alpha_size) % MOD[par];
        }
    }
}

ll hash_value(int idx, int l, int r) { // 0-based indexing in the string
    ll ret = (h[idx][r + 1] - h[idx][l] + MOD[idx]) % MOD[idx];
    return (ret * p[idx][l]) % MOD[idx];
}

bool same(int l, int r, int L, int R) {
    return (hash_value(0, l, r) == hash_value(0, L, R) &&
    hash_value(1, l, r) == hash_value(1, L, R));
}

void solve() {
    cin >> s; hash_string();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    initialize_p();
    tt = 1, tc = 1; // cin >> tt;
    while (tt--) solve(), tc++;
}
