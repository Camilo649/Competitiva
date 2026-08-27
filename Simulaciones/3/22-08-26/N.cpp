#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i, 0, n)

#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i, 0, n)

#define SZ(x) ((int) x.size())
#define ALL(x) sort(x.begin(), x.end())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

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

    int n; cin >> n;
    ll h[5] = {};
    forn(i,n){
        int a;
        cin >> a;
        // cout << a << nl;
        // cout << a%5 << nl;
        h[a%5]++;
    }

    //forn(i,5) cout << h[i] << nl;

    ll res = h[0]; h[0] = 0;

    ll mn = min(h[2], h[3]);
    res += mn; h[2] -= mn; h[3] -= mn;

    mn = min(h[1], h[4]);
    res += mn; h[1] -= mn; h[4] -= mn;

    if(h[1] > 0 && h[2] > 0)
    {
        mn = min(h[1], h[2]/2);
        res += mn; h[1] -= mn; h[2] -= 2*mn;
    }
    if(h[1] > 0 && h[3] > 0)
    {
        mn = min(h[1]/2, h[3]);
        res += mn; h[1] -= 2*mn; h[3] -= mn;
    }
    if(h[4] > 0 && h[3] > 0)
    {
        mn = min(h[4], h[3]/2);
        res += mn; h[4] -= mn; h[3] -= 2*mn;
    }
    if(h[4] > 0 && h[2] > 0)
    {
        mn = min(h[4]/2, h[2]);
        res += mn; h[4] -= 2*mn; h[2] -= mn;
    }

    forn(i,5) 
    {
        res += h[i]/5;
        h[i] = h[i]%5;
    }

    if(h[2] == 1 && h[1] >= 3) res++;
    if(h[1] == 1 && h[3] >= 3) res++;
    if(h[3] == 1 && h[4] >= 3) res++;
    if(h[4] == 1 && h[2] >= 3) res++;

    cout << res << nl;

    return 0;
}