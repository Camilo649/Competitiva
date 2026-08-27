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

const int MAXN = 1e5 + 4;

using namespace std;

int k;
ll c[MAXN], p[MAXN];

bool solve(ll mn)
{
    ll r = 0;
    forn(i,k)
    {
        r = p[i] + r - c[i]*mn;
        if(r<0) return false;
        
    }

    return true;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    forn(i,k) cin >> c[i];
    forn(i,k) cin >> p[i];

    ll S = 0;
    forn(i,k) S += c[i];

    ll T = 0;
    forn(i,k) T += p[i];

    ll mid = 0;
    ll a = 0, b = T/S;
    while (a<=b)
    {
        mid = (a+b)/2;
        if(solve(mid)) a = mid+1;
        else b = mid-1;
    }
    
    cout << a-1 << nl;

    return 0;
}