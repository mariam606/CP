#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int n, q;
const int N = 1e5 + 5;
int a[N]; // a is 0-based
int tree[4 * N];

// ni is the node index in the segment tree. ns is the start range in the array a and ne is the end of range.
void build (int ni = 0, int ns = 0, int ne = n - 1) {
    if (ns == ne) {
        tree[ni] = a[ns];
        return;
    }

    int l = 2 * ni + 1, r = l + 1, mid = ns + (ne - ns) / 2;
    build(l, ns, mid);
    build(r, mid + 1, ne);
    tree[ni] = min(tree[l], tree[r]);
}

void update (int idx, int val, int ni = 0, int ns = 0, int ne = n - 1) {
    if (idx < ns || idx > ne)
        return;
    if (ns == ne) {
        tree[ni] = val;
        return;
    }
    // l is the left child if the node ni and r is the right child.
    int l = 2 * ni + 1, r = l + 1, mid = ns + (ne - ns) / 2;
    update(idx, val, l, ns, mid);
    update(idx, val, r, mid + 1, ne);
    tree[ni] = min(tree[l], tree[r]);
}

int query (int qs, int qe, int ni = 0, int ns = 0, int ne = n - 1) {
    if (qe < ns || qs > ne)
        return INT_MAX;
    if (ns >= qs && ne <= qe) 
        return tree[ni];

    int l = 2 * ni + 1, r = l + 1, mid = ns + (ne - ns) / 2;
    return min(query(qs, qe, l, ns, mid), query(qs, qe, r, mid + 1, ne));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0); 

    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    build();
    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1)
            update(x, y);
        else 
            cout << query(x, y) << "\n";
    }
}
