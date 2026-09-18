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

const int MAXN = 1e5 + 8;

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
    
    int f,n; cin >> f >> n;
    map<int,ll> group_size;
    map<ll,int> friend_group;
    map<int,pair<ll,ll>> group_info;
    vector<int> friends;
    forn(i,n)
    {
        ll k,p; cin >> k >> p;
        friend_group[k] = i;
        group_size[i] = p;
        group_info[i] = {-1,-1};
        friends.pb(k);
    }

    queue<int> q; 
    map<int,set<int>> habilita_a;     // g, {g} que habilita
    vector<tuple<ll,bool,ll>> events; // hora, true si es evento de llegada o false en caso contrario (priorizo salidas), p
    for(ll k : friends)
    {
        int g = friend_group[k];
        char c; cin >> c;
        if(c == 'A')
        {
            ll p = group_size[g]; 
            ll a,t; cin >> a >> t;
            events.pb({a,true,p});
            events.pb({a+t,false,p});
            q.push(g);
            group_info[g] = {a,t};
        }
        else if (c == 'T')
        {
            ll fren; cin >> fren;
           //print(k); print(p); print(friend_group[fren]);
            if(friend_group.count(fren) && friend_group[fren] != g) habilita_a[friend_group[fren]].insert(g);
        }
    }

    // for(auto [p,v] : habilita_a)
    // {
    //     print(p); print(v);
    // }

    while (!q.empty())
    {
        int g = q.front(); q.pop();
        //print(g);
        for(auto g2 : habilita_a[g])
        {
            //print(g2);
            ll a = group_info[g].fst;
            ll t = group_info[g].snd;
            ll p = group_size[g2];
            events.pb({a,true,p});
            events.pb({a+t,false,p});
            q.push(g2);
            group_info[g2] = {a,t};
        }
        habilita_a[g].clear();
    }

    sort(ALL(events));
    ll ans = 0;
    ll count = 0;
    for(auto [h,b,p] : events)
    {
        // print(h); print(b); print(p);
        // print(group_size[p]);
        if(b) count += p;
        else  count -= p;
        ans = max(ans,count);
    }

    cout << ans << nl;
    
    return 0;
}