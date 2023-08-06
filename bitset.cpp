//Bitset can be used to solve the subset problem. It can same all the possible subset sums of an array in O(s * n / 64) where s is the max sum and n is the size of the array. 
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
vector<int> a;

void possible_sums(){
  bitset<N> sums(1);
  for (auto i: a)
    sums |= sums << i;
  //sums[i] = 1 means that i is a possible subset sum
}

void solve() {
  possible_sums();
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //cout.flush();
    // freopen("max-pair.in", "r", stdin)
    int T = 1;
    cin >> T;
    while (T--) solve(); 
}
