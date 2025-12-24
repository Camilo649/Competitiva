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

const int INF = 1e6 + 6;

using namespace std;
 
int tests;

int main()
{
    // #ifdef MILF
    //     freopen("../input.txt", "r", stdin);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    int h[n]; forn(i,n) cin >> h[i];
    ll cost = 0;
    forn(i,n-1)
    {
        if (h[i] == INF) continue;
        if (h[i] > h[i+1])
        {
            int l = i; int r = i+1;
            int vall = 0; int valr = 0;
            while (l >= 0 && h[l] > h[i+1])
            {
                l--;
                vall++;
            }
            while (r < n && h[i] > h[r])
            {
                r++;
                valr++;
            }
            vall == 0 ? vall = INF : vall = vall;
            valr == 0 ? valr = INF : valr = valr;
            if (vall <= valr)
            {
                forr(j, i-vall+1, i+1) h[j] = INF;
            }
            else
            {
                forr(j, i+1, i+1+valr) h[j] = INF;
            }
        }
    }

    forn(i,n)
    {
        int inf_count = 0;
        while (i<n && h[i] == INF)
        {
            inf_count++;
            i++;
        }
        cost += inf_count*inf_count;
    }

    cout << cost << nl; 
    
    return 0;
}