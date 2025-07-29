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

    i64 ans = 0;

    // l = 0
    {
        set<int> s;
        int mex = 0;
        for(int i = 0; i < n; i++) {
            s.insert(a[i]);
            while(s.find(mex) != s.end()) mex++;
            if(mex <= i) ans++;
        }
    }

    // l > 0
    {
        int r = 1;
        multiset<int> m;
        set<int> missing;
        for(int i = 0; i <= n; i++) missing.insert(i);

        for(int i = 1; i < n; i++) {
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
