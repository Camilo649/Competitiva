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

vector<ll> Div;
void getDiv(ll n) {
    Div.clear();
    for (ll d = 1; d * d <= n; d++) {
        if (n%d == 0) {
            Div.push_back(d);
            Div.push_back(n/d);
        }
        if (d*d == n) Div.pop_back();
    }
    // sort(Div.begin(), Div.end()); // OPCIONAL
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
        ll n,q; cin >> n >> q;
        vector<pair<ll,ll>> v;
        forn(i,n)
        {
            ll a; cin >> a;
            v.pb({a,(ll)i});
        }

        sort(ALL(v));

        forn(i,q)
        {
            ll k,l,r; cin >> k >> l >> r;
            l--; r--;

            getDiv(k);

            vector<pair<ll,ll>> to_process;
            for(auto d : Div)
            {
                auto it = lower_bound(ALL(v), make_pair(d,l));
                if(it == v.end() || (*it).snd > r || (*it).fst != d) continue;
                to_process.pb({(*it).snd, d});
            }

            //if(to_process.empty()) {cout << k*(r-l+1) << nl; continue;}

            sort(ALL(to_process));

            ll res = 0;
            ll last = l;
            forn(i,SZ(to_process))
            {
                res += (to_process[i].fst - last)*k;
                ll d = to_process[i].snd;
                //print(res); print(k); print(d);
                while (k%d==0) k/=d;
                //res+=k;
                last = to_process[i].fst;
            }
            res += (r-last+1)*k;

            cout << res << nl;
        }
    }
    
    return 0;
}