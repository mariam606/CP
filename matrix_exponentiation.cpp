#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll X, MOD;
ll add(ll x, ll y){
return (x + y) % MOD;
}

ll mul(ll x, ll y){
	return (x * 1LL * y) % MOD;
}

vector<vector<ll>> ans = 
{
	{1, 0},
	{0, 1}
};

vector<vector<ll>> col = {
	{1},
	{1}
};

vector<vector<ll>> S = 
{
	{1, 1},
	{0, 1}
};

vector<vector<ll>> multiply(vector<vector<ll>> a, vector<vector<ll>> b){
	int x = a.size(), z = a[0].size(), y = b[0].size();
	vector<vector<ll>> c(x, vector<ll>(y));
	for(int i = 0; i < x; ++i)
		for(int j = 0; j < y; ++j)
			for(int k = 0; k < z; ++k)
				c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
	return c;
}

void solve() {
	
	while(X){
		if(X & 1) ans = multiply(ans, S);
		S = multiply(S, S);
		X >>= 1;
	}
	ans = multiply(ans, col);
	cout << ans[0][0] << "\n";
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("max-pair.in", "r", stdin)
	int T = 1;
    cin >> T;
	while (T--) solve(); 
}
