//This segment tree is used to get the maximum index that has a suffix sum > tar
//All the values in the tree are sorted because of the compression
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
map<int, int> comp;
const int N = 3e5 + 3;
ll tree[N << 2], freq[N << 2];
map<int, int> value;

void compress(){
    int id = 0;
    for (auto& u : comp){
        u.second = id++;
        value[u.second] = u.first;
    }
}

void build(int ni = 0, int ns = 0, int ne = n - 1){
    if(ns == ne){
        tree[ni] = a[ns];
        return;
    }
    int l = 2 * ni + 1, r = l + 1, m = ns + (ne - ns) / 2;
    build(l, ns, m);
    build(r, m + 1, ne);
    tree[ni] = tree[l] + tree[r]);
}

void update(int idx, int val, int ni = 0, int ns = 0, int ne = n - 1)
{
    if(idx < ns or idx > ne) return;
    if(ns == ne)
    {
        tree[ni] += val;
        freq[ni]++;
        return;
    }
    int l = 2 * ni + 1, r = l + 1, m = ns + ( ne - ns ) / 2;
    update(idx, val, l, ns, m);
    update(idx, val, r, m + 1, ne);
    tree[ni] = tree[l] + tree[r];
    freq[ni] = freq[l] + freq[r];
}

int query_idx(int tar, int ni = 0, int ns = 0, int ne = n - 1){
    if(ns == ne)
        return ns;
    int l = 2 * ni + 1, r = l + 1, mid = ns + (ne - ns) / 2;
    if(tree[r] >= tar) return query_idx(tar, r, mid + 1, ne);
    else return query_idx(tar - tree[r], l, ns, mid);
}

ll query_sum(int qs, int qe, int ni = 0, int ns = 0, int ne = n - 1){
    if(qs > ne || qe < ns)
        return 0;
    if(qs <= ns && qe >= ne)
        return (ll)tree[ni];
    
    int l = 2 * ni + 1, r = l + 1, mid = ns + (ne - ns) / 2;
    return query_sum(qs, qe, l, ns, mid) + query_sum(qs, qe, r, mid + 1, ne);
}

void solve() {
    //take the input and activate the comp map
    compress();
    //update the tree with the input values
    //Do the queries
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //cout.flush();
    // freopen("max-pair.in", "r", stdin)
    int T = 1;
    cin >> T;
    while (T--) solve(); 
}
