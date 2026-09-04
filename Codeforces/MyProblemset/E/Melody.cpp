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

const int MAXN = 4e5 + 8;

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

vector<pair<int,int>> adj[MAXN];
bitset<2*MAXN> used;
vector<int> ans;

// adj guarda pares {nodo_destino, id_arista}
void hierholzer(int start) {
    vector<pair<int,int>> currPath;
    currPath.push_back({start, -1});

    while (!currPath.empty()) {
        int currNode = currPath.back().fst;
        while (!adj[currNode].empty() && used[adj[currNode].back().second]) {
            adj[currNode].pop_back();
        }
        if (!adj[currNode].empty()) {
            auto edge = adj[currNode].back();
            int nextNode = edge.first;
            int edgeID = edge.second;
            adj[currNode].pop_back();
            used[edgeID] = 1;
            currPath.push_back({nextNode,edgeID});
        }
        else {
            ans.pb(currPath.back().snd);
            currPath.pop_back();
        }
    }

    ans.pop_back();
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
        unordered_map<int,int> volume_id, pitch_id;
        int n; cin >> n;
        int id = 0;
        forn(i,n)
        {
            int v,p; cin >> v >> p;
            if(volume_id.count(v) == 0) {volume_id[v] = id; id++;}
            if(pitch_id.count(p) == 0) {pitch_id[p] = id; id++;}
            adj[volume_id[v]].pb({pitch_id[p], i+1});
            adj[pitch_id[p]].pb({volume_id[v], i+1});
        }

        if(n == 1) {
            cout << "YES" << nl << 1 << nl;
            forn(i,SZ(volume_id) + SZ(pitch_id)) adj[i].clear();
            continue;
        }

        // forn(i,SZ(volume_id) + SZ(pitch_id))
        // {
        //     print(i);
        //     for(auto p : adj[i]) print(p);
        // }

        int grados_impares = 0;
        int start = -1;
        forn(node,SZ(volume_id) + SZ(pitch_id))
        {
            if(SZ(adj[node])%2 == 1) 
            {
                grados_impares++;
                start = node;
            }
        }

        //print(start);

        //print(grados_impares);
        if(grados_impares != 0 && grados_impares != 2) {
            cout << "NO" << nl; 
            forn(i,SZ(volume_id) + SZ(pitch_id)) adj[i].clear();
            continue;
        }
        
        if (start == -1) {
            forn(node,SZ(volume_id) + SZ(pitch_id)) {
                if (!adj[node].empty()) {start = node; break;}
            }
        }

        hierholzer(start);

        //print(ans);

        if(SZ(ans) != n) {
            cout << "NO" << nl; 
            forn(i,SZ(volume_id) + SZ(pitch_id)) adj[i].clear();
            used.reset();
            ans.clear();
            continue;
        }

        cout << "YES" << nl;
        forn(i,SZ(ans)) cout << ans[i] << " ";
        cout << nl;

        forn(i,SZ(volume_id) + SZ(pitch_id)) adj[i].clear();
        used.reset();
        ans.clear();
    }
    
    return 0;
}