//The dfs functoin implements binary lifting. up[u][k] returns the (2^k) ancesstor of the node u
// get_LCA gets the least common ancesstor of the nodes u and v
#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

const int N = 1e5 + 5, LOG = 20;
int up[N][LOG];
vector<vector<int>> g;
vector<int> depth;

int get_k_ancesstor(int u, int k){
    for(int j = 0; j < LOG; ++j)
        if((1 << j) & k)
            u = up[u][j];
    return u;
}

void dfs(int node, int par){
    for(auto child : g[node]){
        if(par != child){
            up[child][0] = node;
            depth[child] = depth[node] + 1;
            for(int j = 1; j < LOG; ++j)
                up[child][j] = up[up[child][j - 1]][j - 1];
            dfs(child, node);
        }
    }
}

int get_LCA(int u, int v){
    if(depth[u] < depth[v]) swap(u, v); //depth of u is greater
    int k = depth[u] - depth[v];
    for(int j = LOG - 1; j >= 0; --j)
        if((1 << j) & k) u = up[u][j];
    
    if(u == v) return u;
    for(int j = LOG - 1; j >= 0; --j)
        if(up[u][j] != up[v][j])
            u = up[u][j], v = up[v][j];

    return up[u][0];
}

void solve() {
    int n; cin >> n;
    g.resize(n);
    depth.resize(n);
    for(int u = 0; u < n; ++u){
        int cnt; cin >> cnt;
        while(cnt--){
            int v; cin >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    dfs(0, -1);
    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        cout << get_LCA(u, v) << "\n";
    }
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //cout.flush();
    // freopen("max-pair.in", "r", stdin)
    int T = 1;
    //cin >> T;
    while (T--) solve(); 
}