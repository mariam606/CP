//Sparse tables: are used to answer the RMQ on a range in O(1). Please call build sparse and then enter your quesries.
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5, LOG = 20;
int mx[N][LOG], mn[N][LOG];
int a[N];
int n;

void build_sparse(){
    for(int i = 0; i < n; ++i)  
        mx[i][0] = a[i], mn[i][0] = a[i];

    for(int j = 1; j < LOG; ++j)
        for(int i = 0; i + (1 << j) - 1 < n; ++i)
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]),
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
}

int query_mn(int l, int r){
    int len = r - l + 1;
    int k = 31 - __builtin_clz(len);
    return min(mn[l][k], mn[r - (1 << k) + 1][k]);
}

void solve() {
    //Get the array
    build_sparse();
    //implement queries
    
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //cout.flush();
    // freopen("max-pair.in", "r", stdin)
    int T = 1;
    //cin >> T;
    while (T--) solve(); 
}
