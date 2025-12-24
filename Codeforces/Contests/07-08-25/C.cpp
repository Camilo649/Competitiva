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

// bool comp(pair<int,int> a, pair<int,int> b) {
//     return abs(a.first - a.second) >= abs(b.first - b.second);
// }

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
       int n,k; cin >> n >> k;
       int a[n]; forn(i,n) cin >> a[i];
       int b[n]; forn(i,n) cin >> b[i];

       vector<pair<int,int>> v;
       forn(i,n) v.pb({min(a[i],b[i]), max(a[i],b[i])});
       sort(v.begin(), v.end());
       int min_dist = 2e9;
       forn(i,n-1)
       {
            min_dist = min(min_dist,max(v[i+1].first - v[i].second, 0));
            if (min_dist == 0) break;
       }
       ll res = 2*min_dist;
       forn(i,n) res += v[i].snd - v[i].fst;
       cout << res << nl;
    }
    
    return 0;
}