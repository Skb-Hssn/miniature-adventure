#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

struct debug {
#define contPrint { *this << "["; \
        int f = 0; for(auto it : x) { *this << (f?", ":""); *this << it; f = 1;} \
        *this << "]"; return *this;}
 
    ~debug(){cerr << endl;}
    template<class c> debug& operator<<(c x) {cerr << x; return *this;}
    template<class c, class d>
    debug& operator<<(pair<c, d> x) {*this << "(" << x.first << ", " << x.second << ")"; 
        return *this;}
    template<class c> debug& operator<<(vector<c> x) contPrint;
#undef contPrint
};

#define dbg(x) "[" << #x << ": " << x << "]  "
#define Wa() cerr << "[LINE: " << __LINE__ << "] -> "; debug() << 
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);


void solve()
{
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for(int& i : a) scanf("%d", &i);

    int ans = 0;
    for(int l = 0; l < n; l++) {
        for(int r = l; r < n; r++) {
            set<int> s;
            for(int i = l; i <= r; i++) s.insert(a[i]);
        }
    }
}

int main() 
{
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
}
