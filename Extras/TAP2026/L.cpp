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
    
    int n,m; cin >> n >> m;
    set<int> s;
    vector<int> figs;
    map<int,vector<int>> pos, pos_rev;
    forn(i,n)
    {
        int a; cin >> a;
        if(!s.count(a))
        {
            s.insert(a);
            figs.pb(a);
        }
        pos[a].pb(i); pos_rev[a].push_back(n-i-1);
    }

    sort(ALL(figs));

    for(auto fig : figs)
    {
        sort(ALL(pos_rev[fig]));
        // print(fig);
        // print(pos[fig]);
        // print(pos_rev[fig]);
    }

    int count = 0;
    int k = 0;
    while(k < SZ(figs))
    {
        int idx1 = k;
        int fig1 = figs[idx1];
        int i1 = -1;
        auto it1 = upper_bound(pos[fig1].begin(), pos[fig1].end(), i1);
        while(it1 != pos[fig1].end())
        {
            //print(fig1);
            i1 = *it1;
            idx1++;
            if(idx1 == SZ(figs)) break;
            fig1 = figs[idx1];
            it1 = upper_bound(pos[fig1].begin(), pos[fig1].end(), i1);
            //print(i1);  
        }

        int idx2 = k;
        int fig2 = figs[idx2];
        int i2 = -1;
        auto it2 = upper_bound(pos_rev[fig2].begin(), pos_rev[fig2].end(), i2);
        while(it2 != pos_rev[fig2].end())
        {
            //print(fig2);
            i2 = *it2;
            idx2++;
            if(idx2 == SZ(figs)) break;
            fig2 = figs[idx2];
            it2 = upper_bound(pos_rev[fig2].begin(), pos_rev[fig2].end(), i2);  
            //print(i2);
        }

        count++;
        k = max(idx1, idx2);
    }
    
    cout << SZ(figs) << " " << count << nl;

    return 0;
}