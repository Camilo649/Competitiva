#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
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

const int MAXN = 103+4;
const ll  INF  = 1e18;

using namespace std;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int courses[MAXN][MAXN]; forn(i,MAXN) forn(j,MAXN) courses[i][j] = -1;
    int n,m; cin >> n >> m;
    forn(i,n)
    {
        int q; cin >> q;
        forn(j,q)
        {
            int c,g; cin >> c >> g;
            courses[i][c] = g;
        }
    }

    int nearest[MAXN]; forn(i,MAXN) nearest[i] = -1;
    forn(i,n)
    {
        ll mn = INF;
        forn(j,n)
        {
            if(i == j) continue;
            ll dist = INF;
            forn(c,MAXN)
            {
                int gi = courses[i][c];
                int gj = courses[j][c];
                if(gi != -1 && gj != -1)
                {
                    if(dist == INF) dist = 0;
                    dist += (gi-gj)*(gi-gj);
                }
            }
            //cout << dist << nl;
            if(dist != INF && dist < mn)
            {
                mn = dist;
                nearest[i] = j;
            }
        }
    }

    forn(i,n)
    {
        if(nearest[i] == -1) {cout << -1 << nl; continue;}
        int j = nearest[i];
        int mxg = -1;
        int course = -1;
        forn(c,MAXN)
        {
            int gj = courses[j][c];
            int gi = courses[i][c];
            if(gj != -1 && gi == -1 && gj > mxg)
            {
                mxg = gj;
                course = c;
            }
        }
        if(course == -1) {cout << -1 << nl; continue;}
        cout << course << nl;
    }

    return 0;
}