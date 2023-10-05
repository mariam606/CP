#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, q; 
const int N = 1e6 + 5;
ll tree[4 * N], lazy[4 * N];

void build(int node = 1, int st = 0, int en = n - 1) {
    if (st == en) {
        tree[node] = lazy[node] = 0LL;
        return;
    }
    
    int mid = st + en >> 1;
    build(node << 1, st, mid);
    build(node << 1 | 1, mid + 1, en);
    tree[node] = lazy[node] = 0LL;
}

void propagate(int node, int st, int en) {
    tree[node] += lazy[node] * 1LL *  (en - st + 1);
    if (st != en) {
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
    }
    lazy[node] = 0LL;
}

void update(int l, int r, int val, int node = 1, int st = 0, int en = n - 1) {
    propagate(node, st, en);

    if (r < st || l > en) 
        return;
    
    if (l <= st && r >= en) {
        lazy[node] += (ll)val;
        propagate(node, st, en);
        return;
    }

    int mid = st + en >> 1;
    update(l, r, val, node << 1, st, mid);
    update(l, r, val, node << 1 | 1, mid + 1, en);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

ll query(int l, int r, int node = 1, int st = 0, int en = n - 1) {
    propagate(node, st, en);
    if (r < st || l > en)
        return 0LL;
    if (l <= st && r >= en) 
        return tree[node];
    
    int mid = st + en >> 1;
    return query(l, r, node << 1, st, mid) + query(l, r, node << 1 | 1, mid + 1, en);
}

void solve() {
    cin >> n >> q;
    build();

    while (q--) {
        int type, l, r, val; cin >> type >> l >> r;
        l--, r--;
        if (type == 0) {
            cin >> val;
            update(l, r, val);
        }else {
            cout << query(l, r) << "\n";
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //cout.flush();
    //freopen("max-pair.in", "r", stdin);
    int T = 1;
    cin >> T;
    while (T--) solve(); 
}
