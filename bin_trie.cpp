#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int q;
const int N = 2e5 + 5;
int trie[N * 30][2]; //[number of words * length of the word][num of letters in the alphabet]
int nxt = 1, freq[N * 30];
 
void add(int x, int t) { //t is the type of operation, 1 for add, -1 for remove
    int p = 1;
    freq[p] += t;
    for (int i = 30; i >= 0; i--) {
        int d = ((x >> i) & 1);
        if (!trie[p][d]) {
            trie[p][d] = ++nxt;
        }
        p = trie[p][d];
        freq[p] += t;
    }
}

//Gets the max value x ^ y where y is pre-saved in the trie
int query(int x) {
    int ans = 0;
    int p = 1;
    for (int i = 30; i >= 0; i--) {
        int d = ((x >> i) & 1);
        if (freq[trie[p][!d]]) {
            p = trie[p][!d];
            ans |= 1 << i;
        } else {
            p = trie[p][d];
        }
    }
    return ans;
}
 
void solve() {
	cin >> q;
	add(0, 1);
	for(int i = 0; i < q; ++i){
	    char type; cin >> type;
	    int x; cin >> x;
	    if(type == '+') add(x, 1);
	    else if(type == '-') add(x, -1);
	    else cout << query(x) << " ";
	}
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("max-pair.in", "r", stdin)
	int T = 1;
    //cin >> T;
	while (T--) solve(); 
}
