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

const int MAXN = 2e5 + 7;

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


//DSU Stuff
int lk[MAXN], len[MAXN];

int find(int x) {
    if(x == lk[x]) return x;
    return lk[x] = find(lk[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (len[a] < len[b]) swap(a,b);
    len[a] += len[b];
    lk[b] = a;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    vector<tuple<ll,bool,ll,int>> events, reflected_events; // x_left o x_right (proyectada), right (false si es izquierda, true si es derecha), y, id,
    // Agregamos el suelo como nodo:
    events.pb({(ll)-1e10, false, 0, 0});           events.pb({(ll)1e10, true, 0, 0});
    reflected_events.pb({(ll)-1e10, false, 0, 0}); reflected_events.pb({(ll)1e10, true, 0, 0});
    int id = 1;
    forn(i,n)
    {
        ll h,l,r; cin >> h >> l >> r;
        events.pb({l+h, false, h, id});           events.pb({r+h, true, h, id});
        reflected_events.pb({l-h, false, h, id}); reflected_events.pb({r-h, true, h, id});
        id++;
    }

    sort(ALL(events));
    sort(ALL(reflected_events));

    vector<tuple<int,int,int>> edges; // pal Kruskal

    map<ll,int> curr_levels;
    for(auto [x,right,y,node_id] : events)
    {
        //print(x); print(right); print(y); print(node_id);

        if(!right) curr_levels[y] = node_id;

        if(!curr_levels.empty())
        {   
            auto it1 = curr_levels.lower_bound(y); 
            if(it1 != curr_levels.end()) 
            {
                it1--;
                edges.pb({y-it1->first, node_id, it1->second});
                //edges.pb({y-it1->first, it1->second, node_id});
                //print(y-it1->first); print(node_id); print(it1->second);
            }
            auto it2 = curr_levels.upper_bound(y);
            if(it2 != curr_levels.end())
            {
                edges.pb({it2->first-y, node_id, it2->second});
                //edges.pb({it2->first-y, it2->second, node_id});
                //print(it2->first-y); print(node_id); print(it2->second);
            } 
        }

        if(right) curr_levels.erase(y);
    }
    for(auto [x,right,y,node_id] : reflected_events)
    {
        //print(x); print(right); print(y); print(node_id);

        if(!right) curr_levels[y] = node_id;

        if(!curr_levels.empty())
        {   
            auto it1 = curr_levels.lower_bound(y); 
            if(it1 != curr_levels.end()) 
            {
                it1--;
                edges.pb({y-it1->first, node_id, it1->second});
                //edges.pb({y-it1->first, it1->second, node_id});
                //print(y-it1->first); print(node_id); print(it1->second);
            }
            auto it2 = curr_levels.upper_bound(y);
            if(it2 != curr_levels.end())
            {
                edges.pb({it2->first-y, node_id, it2->second});
                //edges.pb({it2->first-y, it2->second, node_id});
                //print(it2->first-y); print(node_id); print(it2->second);
            } 
        }

        if(right) curr_levels.erase(y);
    }

    // for(auto [w,u,v] : edges)
    // {
    //     cout << u << " -" << w << "-> " << v << nl; 
    // }

    // DSU Inicialization
    for (int i = 0; i <= n; i++) lk[i] = i;
    for (int i = 0; i <= n; i++) len[i] = 1;

    // FINALY: THE KRUUUSKALLL
    ll ans = 0;
    sort(ALL(edges));
    forn (i,SZ(edges)) {
        if (!same(get<1>(edges[i]), get<2>(edges[i])))
        {
            unite(get<1>(edges[i]), get<2>(edges[i]));
            ans += get<0>(edges[i]);
        }
    }

    cout << ans << nl;
    
    return 0;
}