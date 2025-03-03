#include <bits/stdc++.h>

#define forr(i, a, b) for(ll i = (ll) a; i < (ll) b; ++i)
#define forn(i, n) forr(i, 0, n)
#define dforr(i, a, b) for(ll i = (ll) b-1; i >= (ll) a; --i)
#define dforn(i, n) dforr(i, 0, n)
#define sz(x) ((ll) x.size())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';
#define MILF

typedef unsigned long long ll;
typedef long double ld;

using u64 = uint64_t;

const ll MAXN = 3*1e5;
const ll M = 998244353;

using namespace std;
 
ll tests;

vector<ll> adj[MAXN];
unordered_map<ll,pair<ll,vector<ll>>> depth_count;
bitset<MAXN> visited;
ll max_depth = 0;

void dfs(ll s, ll d) {
    if(visited[s]) return;
    visited[s] = 1;

    depth_count.count(d) == 0 ? depth_count[d].first = 1 : depth_count[d].first++;
    depth_count[d].second.pb(s);
    max_depth = max(max_depth, d);
    for (auto u : adj[s]) {
        dfs(u, d+1);
    }
}

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tests;

    while (tests--)
    {
        ll n;
        cin >> n;
        ll child_count[n] = {};
        forr(i,1,n)
        {
            ll u;
            cin >> u;
            u--;
            adj[u].pb(i);
            child_count[u]++;
        }

        dfs(0,0);

        ll dp[n] = {};
        ll depth_sum[max_depth+1];
        depth_sum[max_depth] = 0;
        dforr (i,1,max_depth+1)
        {
            ll sum = 0;
            for(ll v : depth_count[i].second)
            {
                dp[v] = (depth_sum[i] + 1) % M;
                for (ll child : adj[v])
                {
                    dp[v] = (dp[v] - dp[child] + M) % M;
                }
                sum = (sum + dp[v]) % M;
            }
            depth_sum[i-1] = sum;
        }
        
        cout << (1 + depth_sum[0]) % M << nl;

        for (ll i = 0; i < n; i++) {
            adj[i].clear();
        }
        depth_count.clear();
        visited.reset();
        max_depth = 0;
    }
    
    return 0;
}
