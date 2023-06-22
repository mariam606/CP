//Range offline queries in O(Q*sqrt(N)), Make sure that the queries are 0-based. 
//If you want to get the query over the path between u and v. 
//Case1: if u is an ancesstor of v, loop over the path between tin[u] to tin[v]
//Case2: loop over the path between tout[u] to tin[v], then add tin[lca] and remove it again.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int N = 4e5 + 5, SQ = 450, LOG = 20;
int n, q, timer = -1;
vector<int> query;
vector<int> l, r, p, depth, U, V, add_lca;
vector<vector<int>> g;
unordered_map<int, int> IDs;
int up[N][LOG];
int a[N], tin[N], tout[N], sz[N], vertex[N], vis[N], freq[N];

int add(int idx){

}

bool cmp(int x, int y){
	if((l[x] / SQ) < (l[y] / SQ)) return true;
	if((l[x] / SQ) > (l[y] / SQ)) return false;
	if(r[x] < r[y]) return true;
	return false;
}

int pre(int node, int par){
	tin[node] = ++timer;
	vertex[timer] = node;
	sz[node] = 1;
	for(auto child: g[node])
		if(child != par) sz[node] += pre(child, node);
 
	tout[node] = ++timer;
    vertex[timer] = node;
	return sz[node];
}

void dfs(int node, int par){
    for(auto child : g[node]){
        if(par != child){
            up[child][0] = node;
            depth[child] = depth[node] + 1;
            for(int j = 1; j < LOG; ++j){
                up[child][j] = up[up[child][j - 1]][j - 1];
            }
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

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void solve() {
	//Take the input
	query.resize(q); l.resize(q); r.resize(q); U.resize(q); V.resize(q); p.resize(q), add_lca.resize(q); depth.resize(n);
	iota(p.begin(), p.end(), 0);
	for(int i = 0; i < q; ++i){
		cin >> U[i] >> V[i];
        --U[i], --V[i];
	}
    pre(0, -1); dfs(0, -1);
    for (int i = 0; i < q; i++) {
        if (depth[U[i]] < depth[V[i]]) swap(U[i], V[i]);
        if (is_ancestor(V[i], U[i])) {
            l[i] = tin[V[i]];
            r[i] = tin[U[i]];
        }
        else {
            if (tin[U[i]] > tout[V[i]]) swap(U[i], V[i]);
            l[i] = tout[U[i]];
            r[i] = tin[V[i]];
            add_lca[i] = 1;
        }
    }
	sort(p.begin(), p.end(), cmp);
	int ans = 0, L = 1, R = 0;
	for(int i = 0; i < q; ++i){
		int j = p[i];
		while(R < r[j]) ans += add(++R);
		while(R > r[j]) ans += add(R--);
		while(L < l[j]) ans += add(L++);
		while(L > l[j]) ans += add(--L);
		query[j] = ans;
        if(add_lca[j]){
            int lca = get_LCA(U[j], V[j]);
            query[j] += add(tin[lca]);
            add(tin[lca]);
        }
	}
	for(auto it: query) cout << it << "\n";
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("max-pair.in", "r", stdin)
	int T = 1;
    //cin >> T;
	while (T--) solve(); 
}