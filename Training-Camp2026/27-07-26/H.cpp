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
#define GG
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1500*1500 + 5;
const int INF = 1e9;

using namespace std;
 
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
    string g[n];
    forn(i,n)
    {
        cin >> g[i];
    }

    pair<int,int> coords[n][m];
    forn(i,n)
    {
        forn(j,m)
        {
            coords[i][j] = {INF, INF};
        }
    }

    bool found = false;
    pair<int,int> s;
    forn(i,n)
    {
        forn(j,m)
        {
            if(g[i][j] == 'S')
            {
                s = {j,i};
                found = true;
            }
            if(found) break;
        }
        if(found) break;
    }
    
    pair<int,int> direcciones[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    queue<pair<int,int>> q; q.push(s);
    pair<int,int> par_inf = {INF,INF};
    bool flag = false;
    while (!q.empty() && !flag)
    {
        pair<int,int> r = q.front(); q.pop();
        for(auto d : direcciones)
        {
            int x2 = r.fst + d.fst;
            int y2 = r.snd + d.snd;

            int x3 = x2%m;
            int y3 = y2%n;

            if(x3<0) x3 += m;
            if(y3<0) y3 += n;

            if(g[y3][x3] == '#') continue;

            if(coords[y3][x3] != par_inf)
            {
                pair<int,int> aux = {x2,y2};
                if(coords[y3][x3] != aux)
                {
                    flag = true;
                }
            }
            else
            {
                coords[y3][x3] = {x2,y2};
                q.push({x2,y2});
            }
        }
    }
    
    if(flag)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    cout << nl;
    
    return 0;
}