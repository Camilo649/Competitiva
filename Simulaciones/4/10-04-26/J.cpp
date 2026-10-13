#include <bits/stdc++.h>

#define forr(i,a,b) for(int  i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)

#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1e5+5;

using namespace std;

int nxt[MAXN];

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;

    forr(i,1,n+1) nxt[i] = i;

    forn(i,n-1)
    {
        int u,v; cin >> u >> v;
        if(v > u) 
        {
            if(nxt[u] > u)
            {
                nxt[u] = min(nxt[u], v);
            }
            else
            {
                nxt[u] = v;
            }
        }
        
        if(u > v) 
        {
            if(nxt[v] > v)
            {
                nxt[v] = min(nxt[v], u);
            }
            else
            {
                nxt[v] = u;
            }
        }
    }

    forr(i,1,n+1)
    {
        cout << nxt[i] << " ";
    }
    cout << nl;

    return 0;
}