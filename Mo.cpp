//Range offline queries in O(Q*sqrt(N)), Make sure that the querues are 0-based
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int N = 2e5 + 5, SQ = 450;
int n, q;
vector<ll> a;
vector<ll> query;
vector<ll> l, r, p;

ll add(int idx){

}

ll erase(int idx){

}

bool cmp(int x, int y){
	if((l[x] / SQ) < (l[y] / SQ)) return true;
	if((l[x] / SQ) > (l[y] / SQ)) return false;
	if(r[x] < r[y]) return true;
	return false;
}

void solve() {
	
	query.resize(q); l.resize(q); r.resize(q); p.resize(q);
	iota(p.begin(), p.end(), 0);
	for(int i = 0; i < q; ++i){
		cin >> l[i] >> r[i];
	}

	sort(p.begin(), p.end(), cmp);
	ll ans = 0LL, L = 0, R = -1;
	for(int i = 0; i < q; ++i){
		int j = p[i];
		while(R < r[j]) ans += add(++R);
		while(R > r[j]) ans -= erase(R--);
		while(L < l[j]) ans -= erase(L++);
		while(L > l[j]) ans += add(--L);
		query[j] = ans;
	}
	for(auto it: query) cout << it << "\n";

}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("max-pair.in", "r", stdin)
	int T = 1;
    cin >> T;
	while (T--) solve(); 
}