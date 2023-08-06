#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
vector<int> par, sz;

// O(1)
int find(int x) { 
    return (x == par[x] ? x : par[x] = find(par[x])); 
}
 
// O(1)
int  unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return sz[x];
    par[x] = y;  
    sz[y] += sz[x];
    return sz[y];
}
 
void init_dsu(){
    par.clear(); par.resize(n);
    iota(par.begin(), par.end(), 0);
    sz.clear(); sz.resize(n, 1);
}

void solve() {
    //take input
    init_dsu();
    
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //cout.flush();
    // freopen("max-pair.in", "r", stdin)
    int T = 1;
    cin >> T;
    while (T--) solve(); 
}
