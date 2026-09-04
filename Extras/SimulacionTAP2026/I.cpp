#include <bits/stdc++.h>

#define forr(i,a,b) for(ll i = (ll) a; i<(ll)b; ++i)
#define forn(i,n) forr(i,0,n)

#define dofrr(i,a,b) for(ll i = (ll) b-1; i>= (ll) a; --i)
#define dforn(i,n) dofrr(i,0,n)

#define SZ(x) ((ll) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second 
#define nl '\n'

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const ll MAXN = -1;

using namespace std;

#ifdef GG
#define DBG 1
#define print(x) cer << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v){
    if(DBG) os << "[";
    for(auto& x : v) os << x << (DBG ? ", " : " ");
    return DBG ? os << "]" : os;
}

template<typename S, typename T> ostream& operator<<(ostream& os, const pair<S, T>& p){
    return os << (DBG ? "(" : "") << p.fst << (DBG ? ", " : " ") << p.snd << (DBG ? ")" : "");
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m; cin >> n >> m;
    ll gold[n+1] = {};
    forn(i,m)
    {
        ll x,y; cin >> x >> y;
        unordered_set<ll> s;
        forn(i,n)
        {
            ll d; cin >> d;
            if(d == 1LL) s.insert(i);
            else gold[i] += y;
        }

        bool opcion1 = x/(SZ(s)+1LL) >= y;
        ll val = 0;
        if(opcion1) val = x/(SZ(s)+1LL);
        else if(!s.empty()) val = x/SZ(s);

        gold[n] += opcion1 ? val : y;

        for(auto p : s)
        {
            gold[p] += val;
        }
    }

    forn(i,n+1)
    {
        cout << gold[i] << " ";
    }
    cout << nl;
    
    return 0;
}