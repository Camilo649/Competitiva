#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define SZ(x) ((ll) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'
// redefiniciones
typedef unsigned long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1e5+4; // Creo que con mucho menos alcanza

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

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n,x; cin >> n >> x;
    map<ll,int> dist;
    dist[x] = 0;
    queue<ll> q;
    q.push(x);

    while(!q.empty())
    {
        ll k = q.front(); q.pop();
        string s = to_string(k);
        if(SZ(s) == n) {cout << dist[k] << nl; return 0;}
        //print(k);
        forn(i,SZ(s))
        {
            ll d = (s[i]-'0');
            if(d <= 1) continue;
            ll l = k*d;
            //print(l);
            if(!dist.count(l))
            {
                dist[l] = dist[k]+1;
                q.push(l);
            }
        }
    }

    cout << -1 << nl;
    
    return 0;
}