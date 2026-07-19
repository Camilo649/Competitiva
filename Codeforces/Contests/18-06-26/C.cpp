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
        int n; cin >> n;
        ll a[n]; forn(i,n) cin >> a[i];

        ll sum[n+1] = {};
        forn(i,n) sum[i+1] = sum[i] + a[i];

        vector<pair<int,int>> v;
        forn(i,n-1)
        {
            if(a[i] > a[i+1]) v.pb({a[i], i});
        }

        sort(v.rbegin(), v.rend());

        int best = 0;
        forr(k,1,v.size())
        {
            if(sum[v[best].snd] - sum[v[k].snd] > v[best].fst)
                best = k;
        } 

        if(!v.empty())
        {
            forr(j,v[best].snd,n-1)
            {
                if(a[j] > a[j+1])
                {
                    swap(a[j], a[j+1]);
                    a[j+1] += a[j];
                }
                else break;
            }
        }

        cout << a[n-1] << nl;
    }
    
    return 0;
}