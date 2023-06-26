//1-based, input the array through updates
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
int BIT[N], a[N], n;

void update(int x, int val){
    while(x <= n){  
        BIT[x] += val;  
        x += (x & -x);  //removing the last bit
    } 
}

int query(int x) {
    int res = 0;  
    while(x > 0){  
        res += BIT[x];  
        x -= (x & -x);  
    } 
    return res;
} 

void solve() {
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        update(i, a[i]);
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
