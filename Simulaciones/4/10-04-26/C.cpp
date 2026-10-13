#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

using namespace std;

// Debugging
#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    if (DBG) os << "[";
    for (auto& x : v) os << x << (DBG ? ", " : " ");
    return DBG ? os << "]" : os;
}

template<typename S, typename T> ostream& operator<<(ostream& os, const pair<S, T>& p) {
    return os << (DBG ? "(" : "") << p.fst << (DBG ? ", " : " ") << p.snd << (DBG ? ")" : "");
}

int n,k;
bool solve(int g, int c[]) 
{
    //print(g);

    bool ans = false;
    int size = k*g;
    map<int,int> m;
    int d = g*k;
    forn(i,size) 
    {
        m[c[i]]++;
        if(m[c[i]] <= g) d--;
        else d++;
    }
    ans |= d==0;

    //print(d);

    forr(i,size,n)
    {
        m[c[i-size]]--;
        if(m[c[i-size]] >= g) d--;
        else d++;
        m[c[i]]++;
        if(m[c[i]] <= g) d--;
        else d++;
        ans |= d==0;

        //print(d);
    }

    return ans;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int c[n]; forn(i,n) cin >> c[i];

    int ans = 0;
    dforr(g,1,n/k+1) if(solve(g,c)) {ans = g; break;}

    cout << ans*k << nl;

    return 0;
}