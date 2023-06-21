// DSU on trees: this code is used to implement euler tour algorithm on a tree and convert it into an array (the vertex array). The inarient that the vertex array depends
// is the tin because every vertex has a unique tin. After that you can update a property (e.g. most frequent element) about a subtree on log using the below dfs. 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int n;
const int N = 1e5 + 5;
vector<int> g[N];
int a[N], tin[N], tout[N], sz[N], vertex[N];
ll ans[N];
int timer;
 
void add(int propery){ 

}
 
void erase(int propery){

}
 
void solve_queries(int node){
}
 
int pre(int node, int par){
	tin[node] = ++timer;
	vertex[tin[node]] = node;
	sz[node] = 1;
	for(auto child: g[node])
		if(child != par) sz[node] += pre(child, node);
 
	tout[node] = timer;
	return sz[node];
}
 
void dfs(int v, int p, bool keep) {
    int big_child = -1, big_size = 0;
    for (auto& u : g[v]) if (u != p && sz[u] > big_size) {
        big_child = u;
        big_size = sz[u];
    }
    for (auto& u : g[v]) if (u != p && u != big_child) dfs(u, v, 0);
    if (big_child != -1) dfs(big_child, v, 1);
    for (auto& u : g[v]) if (u != p && u != big_child) 
        for (int i = tin[u]; i <= tout[u]; i++) add(a[vertex[i]]);
    add(a[v]);
    solve_queries(v);
    if (!keep) for (int i = tin[v]; i <= tout[v]; i++) erase(a[vertex[i]]);
}
 
void solve() {
	pre(1, -1);
	dfs(1, -1, 0);
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("max-pair.in", "r", stdin)
	int T = 1;
    cin >> T;
	while (T--) solve(); 
}