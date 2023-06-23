//a is 0-based
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1 << 18; //2e5
int a[N], tree[N];
int n, q;

void build(int ni = 0, int ns = 0, int ne = n - 1){
    if(ns == ne){
        tree[ni] = a[ns];
        return;
    }
    int l = 2 * ni + 1, r = l + 1, m = ns + (ne - ns) / 2;
    build(l, ns, m);
    build(r, m + 1, ne);
    tree[ni] = min(tree[l], tree[r]);
}

void update(int idx,int val,int ni = 0,int ns = 0,int ne = n-1)
{
    if(idx < ns or idx > ne) return;
    if(ns == ne)
    {
        tree[ni] = val;
        return;
    }
    int l = 2 * ni + 1, r = l + 1, m = ns + ( ne - ns ) / 2;
    update(idx, val, l, ns, m);
    update(idx, val, r, m + 1, ne);
    tree[ni] = min(tree[l], tree[r]);
}

int query(int qs, int qe, int ni = 0, int ns = 0, int ne = n - 1){
    if(qs > ne || qe < ns)
        return INT_MAX;
    if(qs <= ns && qe >= ne)
        return tree[ni];
    
    int l = 2 * ni + 1, r = l + 1, mid = ns + (ne - ns) / 2;
    return min(query(qs, qe, l, ns, mid), query(qs, qe, r, mid + 1, ne));
}

void solve() {
    
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //cout.flush();
    // freopen("max-pair.in", "r", stdin)
    int T = 1;
    //cin >> T;
    while (T--) solve(); 
}
