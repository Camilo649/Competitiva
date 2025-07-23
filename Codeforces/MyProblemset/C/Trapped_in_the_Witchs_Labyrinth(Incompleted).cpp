#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define sz(x) ((int) x.size())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';
#define MILF
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1e7;

using namespace std;
 
int tests, maxCycle = 0;

bitset<MAXN> visited;

unordered_set<int> cycle;

void dfs(int r, vector<vector<int>> &adj, unordered_set<int> &path) {
    if(visited[r])
    {
        maxCycle = max(maxCycle, (int)path.size());
        cycle = path;
        return;
    }
    visited[r] = 1;
    path.insert(r);

    for(auto u:adj[r]) {
        dfs(u, adj, path);
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
        int n,m;
        cin >> n >> m;
        vector<vector<int>> adj(n*m + 2*n + 2*(m+2));
        forr(i,1,n+1)
        {
            string s;
            cin >> s;
            forr(j,1,m+1)
            {
                switch (s[j-1])
                {
                case 'U':
                    adj[i*(m+2) + j].pb((i-1)*(m+2) + j);
                    break;
                case 'D':
                    adj[i*(m+2) + j].pb((i+1)*(m+2) + j);
                    break;
                case 'L':
                    adj[i*(m+2) + j].pb(i*(m+2) + j-1);
                    break;
                case 'R':
                    adj[i*(m+2) + j].pb(i*(m+2) + j+1);
                    break;
                default:
                    break;
                }
            }
        }

        forr(i,1,n+1)
        {
            forr(j,1,m+1)
            {
                if (!visited[i*(m+2) + j])
                {
                    unordered_set<int> us;
                    dfs(i*(m+2) + j, adj, us);
                }
            }
        }

        forr(i,1,n+1)
        {
            forr(j,1,m+1)
            {
                if (adj[i*(m+2) + j].empty() && ((cycle.count((i+1)*(m+2) + j) == 1) || (cycle.count((i-1)*(m+2) + j) == 1) || (cycle.count(i*(m+2) + j-1) == 1) || (cycle.count(i*(m+2) + j+1) == 1)))
                {
                    maxCycle++;
                }
            }
        }

    }

    cout << maxCycle << nl;
   
    visited.reset();
    maxCycle = 0;
    cycle.clear();

    return 0;
}