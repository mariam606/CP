// DSU on trees: this code is used to implement euler tour algorithm on a tree and convert it into an array (the vertex array). The vertex array depends
// on the tin o each vertex because it's unique. It is only used in case of offline queries
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int n, q, timer;
const int N = 1e5 + 5;
vector<int> g[N];
int a[N], tin[N], tout[N], sz[N], vertex[N], p[N], depth[N];
vector<vector<int>> query_idx;

void add(int v) {

}

void erase(int v) {

}

void solve_queries(int v) {

}

int pre(int v) {
    tin[v] = ++timer;
    vertex[tin[v]] = v;
    sz[v] = 1;
    for (auto& u : g[v]) if (u != p[v]) {
        depth[u] = depth[v] + 1;
        p[u] = v;
        sz[v] += pre(u);
    }
    tout[v] = timer;
    return sz[v];
}

void dfs(int v, bool keep) {
    int big_child = -1, big_size = 0;
    for (auto& u : g[v]) if (u != p[v] && sz[u] > big_size) {
        big_child = u;
        big_size = sz[u];
    }
    for (auto& u : g[v]) if (u != p[v] && u != big_child) dfs(u, 0);
    if (big_child != -1) dfs(big_child, 1);
    for (auto& u : g[v]) if (u != p[v] && u != big_child) 
        for (int i = tin[u]; i <= tout[u]; i++) add(vertex[i]);
    add(v);
    solve_queries(v);
    if (!keep) for (int i = tin[v]; i <= tout[v]; i++) erase(vertex[i]);
}

bool is_ancestor(int u, int v) {
    return (tin[u] <= tin[v] && tin[v] <= tout[u]);
}
 
void solve() {
	timer = 0;
	//take input
	pre(1);
	dfs(1, 0);
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("max-pair.in", "r", stdin)
	int T = 1;
    cin >> T;
	while (T--) solve(); 
}
