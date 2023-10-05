#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, q; 
const int N = 1e5 + 5;
int tree[4 * N];

void build(int node = 1, int st = 0, int en = n - 1) {
    if (st == en) {
        tree[st] = 0;
        return;
    }
    
    int mid = st + en >> 1;
    build(node << 1, st, mid);
    build(node << 1 | 1, mid + 1, en);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

void update(int idx, int val, int node = 1, int st = 0, int en = n - 1) {
    if (idx < st || idx > en) 
        return;
    
    if (st == en) {
        tree[node] += val;
        return;
    }

    int mid = st + en >> 1;
    update(idx, val, node << 1, st, mid);
    update(idx, val, node << 1 | 1, mid + 1, en);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

int query(int l, int r, int node = 1, int st = 0, int en = n - 1) {
    if (r < st || l > en)
        return 0;
    if (l <= st && r >= en) 
        return tree[node];
    
    int mid = st + en >> 1;
    return query(l, r, node << 1, st, mid) + query(l, r, node << 1 | 1, mid + 1, en);
}

void solve() {
    cin >> n >> q;
    build();

    while (q--) {
        int type, l, r, val; cin >> type;
        if (type == 0) {
            cin >> l >> val;
            update(i, val);
        }else {
            cin >> l >> r;
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
