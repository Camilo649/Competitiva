#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)

#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) sort(x.begin(), x.end())
#define pb puhs_back
#define fst first
#define snd second
#define nl '\n';

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

using namespace std;

const int MAXN = 16;
char pic [2][MAXN];

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int b,w; cin >> b >> w;
    if(b<=w)
    {
        b--;
        int j = 0;
        while (w != b)
        {
            pic[0][j] = '.';
            pic[0][j+1] = '@';
            j+=2;
            w--;
        }
        forn(k,j) pic[1][k] = '@';

        forn(i,2)
            forr(k,j,MAXN)
                pic[i][k] = '@';

        int i = j;
        while (b!=0)
        {
            pic[0][i] = '.';
            pic[1][i] = '.';
            b--;
            i += 2;
        }
    }
        
    else
    {
        w--;
        int j = 0;
        while (b != w)
        {
            pic[0][j] = '@';
            pic[0][j+1] = '.';
            j+=2;
            b--;
        }
        forn(k,j) pic[1][k] = '.';

        forn(i,2)
            forr(k,j,MAXN)
                pic[i][k] = '.';

        int i = j;
        while (w!=0)
        {
            pic[0][i] = '@';
            pic[1][i] = '@';
            w--;
            i += 2;
        }
    }

    cout << 2 << " " << MAXN << nl;
    forn(i,2)
    {
        forn(j,MAXN)
        {
            cout << pic[i][j];
        }
        cout << nl
    }
    
    return 0;
}