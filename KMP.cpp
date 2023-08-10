//string matching KMP O(N), res vector carries the starting indices of the matches
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e7 + 9;
char p[N], s[N];
int f[N];// n;

int getL(int l, char c){
    while(l && p[l] != c)
        l = f[l - 1];
    l += (c == p[l]);
    return l; 
}

void compF(){
    if(!p[0]) return;
    f[0] = 0;
    //-?
    for(int i = 1; p[i]; ++i)
        f[i] = getL(f[i - 1], p[i]);
}

vector<int> kmp(){
    compF(); // This function matches the pattern with itself
    int l = 0;
    vector<int> res;

    for(int i = 0; s[i]; ++i){
        l = getL(l, s[i]);
        if(!p[l]) res.push_back(i - l + 1); // if(l == n)
    }

    return res;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> p >> s;
        int m = 0;
        for(int i = 0; 101; ++i){
            if(!p[i]) break;
            m++;
        }
        auto res = kmp();
        cout << res.size() << "\n";
        for(int i = 0; i < res.size(); ++i){
           cout << res[i] << " ";
           
        }
        cout << "\n";
    }
    
}
