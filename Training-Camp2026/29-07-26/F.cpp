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

const int MAXN = (1e6 / 2) + 6;

using namespace std;
 

bitset<1000+1> visited[1000+1];
string g[1000+1];
int l[1000+1][1000+1];
int n,m;
int cant = 0;
int id = 1;

//int iteration = 0;

void dfs(int x, int y) { // <-- pasamos la raiz como parametro
    //iteration++;
    if(visited[x][y]) return;
    visited[x][y] = 1;
    cant++;
    l[x][y] = id;
    if(x>0 && g[x-1][y] == '.') dfs(x-1, y);
    if(x<n-1 && g[x+1][y] == '.') dfs(x+1, y);
    if(y>0 && g[x][y-1] == '.') dfs(x, y-1);
    if(y<m-1 && g[x][y+1] == '.') dfs(x, y+1);
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    forn(i,n) cin >> g[i];

    int id_to_cant[MAXN] = {};
    forn(i,n)
    {
        forn(j,m)
        {
            if(g[i][j] == '.' && !visited[i][j]) 
            {
                cant = 0;
                //iteration++;
                dfs(i,j);
                id_to_cant[id] = cant;
                id++;
            }
        }
    }

    ll res = 0;
    forn(i,n)
    {
        forn(j,m)
        {
            if(g[i][j] == '*')
            {
                set<int> s;
                //iteration++;
                if(i>0 && g[i-1][j] == '.' && !s.count(l[i-1][j])) 
                {
                    s.insert(l[i-1][j]);
                    res = (id_to_cant[l[i-1][j]] + res);
                }
                if(i<n-1 && g[i+1][j] == '.' && !s.count(l[i+1][j]))
                {
                    s.insert(l[i+1][j]);
                    res = (id_to_cant[l[i+1][j]] + res);
                }
                if(j>0 && g[i][j-1] == '.' && !s.count(l[i][j-1]))
                {
                    s.insert(l[i][j-1]);
                    res = (id_to_cant[l[i][j-1]] + res);
                }
                if(j<m-1 && g[i][j+1] == '.' && !s.count(l[i][j+1]))
                {
                    s.insert(l[i][j+1]);
                    res = (id_to_cant[l[i][j+1]] + res);
                }

                res = (res+1)%10;
                g[i][j] = '0' + res;
                res = 0;
            }
        }
    }

    forn(i,n)
    {
        //iteration++;
        cout << g[i] << nl;
    }

    //cout<< "ITERATION: " << iteration << nl;

    // forn(i,n)
    // {
    //     forn(j,m)
    //     {
    //         cout << l[i][j] << " ";
    //     }
    //     cout << nl;
    // }

    // forr(i,1,id)
    // {
    //     cout << id_to_cant[i] << " ";
    // }
    // cout << nl;
    
    return 0;
}