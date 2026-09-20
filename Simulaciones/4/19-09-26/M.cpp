#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = (int) b-1; i>= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5+3;

using namespace std;

ll n,c,t; 
ll a[MAXN];

bool solve(ll k)
{
    ll i = 0;
    ll p = 0;
    while(p<c && i<n)
    {
        ll power = t*k;
        while(i<n && power >= a[i])
        {
            power -= a[i];
            i++;
        }
        p++;
    }

    return i == n;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c >> t;
    forn(i,n) cin >> a[i];

    ll l = 0LL, r = 1e10 + 8;
    while(l<=r)
    {
        ll k = (l+r)/2;
        if(solve(k)) r = k-1;
        else l = k+1;
    }

    cout << l << nl;

    return 0;
}