#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

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

int tests;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;
    
    while (tests--)
    {
        int n; cin >> n;
        int a[n]; forn(i,n) cin >> a[i];
        int l1 = -1, r1 = -1;
        int l2 = -1, r2 = -1;
        forn(i,n)
        {
            if(a[i] == 1 && l1 == -1) l1 = i;
            if(a[i] == -1 && l2 == -1) l2 = i;
        }
        dforn(i,n)
        {
            if(a[i] == 1 && r1 == -1) r1 = i;
            if(a[i] == -1 && r2 == -1) r2 = i;
        }

        if(l2 != -1) 
        {
            if(l2 < l1 || l1 == -1) a[l2] = 1;
        }
        if(r2 != -1) 
        {
            if(r2 > r1 || r1 == -1) a[r2] = 1;
        }

        forn(i,n)
        {
            if(a[i] == -1) a[i] = 0;
        }

        forn(i,n)
        {
            cout << a[i] << " ";
        }
        cout << nl;
    }
    
    return 0;
}