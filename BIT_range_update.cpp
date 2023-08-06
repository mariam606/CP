//1-based, input the array through updates. Range update and range query O(log(N)) for sum only
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
int B1[N], B2[N], n, a[N];

void add(int b[], int idx, int x){
    while(idx <= N){
        b[idx] += x;
        idx += idx & -idx;
    }
}

void range_add(int l, int r, int x){
    add(B1, l, x);
    add(B1, r + 1, -x);
    add(B2, l, x * (l - 1));
    add(B2, r + 1, -x * r);
}

int sum(int b[], int idx){
    int total = 0;
    while(idx > 0){
        total += b[idx];
        idx -= idx & -idx;
    }
    return total;
}

int prefix_sum(int idx){
    return sum(B1, idx) * idx -  sum(B2, idx);
}

int range_sum(int l, int r){
    return prefix_sum(r) - prefix_sum(l - 1);
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        range_add(i, i, a[i]);
    }
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //cout.flush();
    // freopen("max-pair.in", "r", stdin)
    int T = 1;
    cin >> T;
    while (T--) solve(); 
}
