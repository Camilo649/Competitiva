#include <bits/stdc++.h>

#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)

#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)

#define SZ(x) ((int) x.size())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1<<18;
int niveles = 0;

using namespace std;

int h, t[2*MAXN + 6] = {};
void updatest(int k, int x)
{
    k += h-1;
    t[k] = x;
    for(int cuqui = (k-1)/2; cuqui>=1; cuqui = (cuqui-1)/2)
    {
        t[cuqui] = max(t[2*cuqui+1], t[2*cuqui+2]);
    }
}

int query(int val)
{
    int i = 0;
    forn(l, niveles-1)
    {
        if(t[i*2 + 1] >= val) i = i*2 + 1;
        else i = i*2 + 2;
    }

    return (t[i] >= val ? i - h + 2 : -1);
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,w; cin >> h >> w >> n;
    int a[n]; forn(i,n) cin >> a[i];
    int pot = 0;
    h = min(h,n);
    while (h > 1<<pot)
    {
        pot++;
    }
    niveles = pot+1;
    int rows[1<<pot]; forn(i,h) rows[i] = w;
    forr(i, h, 1<<pot) rows[i] = 0;
    h = 1<<pot;

    forn(i,h) t[h+i-1] = rows[i];
    for(int i = h-2; i>=0; i--)
        t[i] = max(t[2*i], t[2*i+1]);

    vector<int> res;
    forn(i,n)
    {
        int q = query(a[i]);
        res.pb(q);
        if(q != -1) updatest(q-1, t[q+h-2]-a[i]);
    }
    
    forn(i,n)
    {
        cout << res[i] << nl;
    }
    
    return 0;
}