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

const int MAXN = -1;

using namespace std;
 
int tests;

ll get_water(int n, int a[], int h, int pos)
{
    if(pos == -1) return 0;

    ll water = 0;
    int curr = a[pos];
    dforn(i,pos)
    {
        curr = max(a[i], curr);
        water += h-curr;
    }
    curr = a[pos];
    forr(i,pos,n)
    {
        curr = max(a[i], curr);
        water += h-curr;
    }

    return water;
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
        int n,h; cin >> n >> h;
        int a[n]; forn(i,n) cin >> a[i];

        int mn = 1e9 + 3;
        forn(i,n) mn = min(a[i],mn);

        ll water[n]; forn(i,n) water[i] = get_water(n,a,h,i);

        ll mx = water[0];
        forn(i,n)
        {
            ll w = water[i];
            forr(j,i+1,n)
            {
                int mh = 0;
                int idx = -1;
                forr(k,i+1,j)
                {
                    if(a[k] > mh)
                    {
                        mh = a[k];
                        idx = k;
                    }
                }

                if(idx == -1)
                {
                    if(a[i] < a[j])
                    {
                        idx = j;
                    }
                    else
                    {
                        idx = i;
                    }
                }

                mx = max(mx, w + water[j] - water[idx]);
            }
        }

        cout << mx << nl;
    }
    
    return 0;
}