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

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,q; cin >> n >> q;
    ll a[n]; forn(i,n) cin >> a[i];
    ll x[q]; forn(i,q) cin >> x[i];

    ll sum[n]; sum[0] = 1;
    set<ll> s;
    forr(i,1,n)
    {
        sum[i] = sum[i-1] + max(abs(a[i] - a[i-1]) - 1, (ll)0) + 1;
        if(a[i] == a[i-1]) 
        {
            sum[i]++;
            s.insert(sum[i] - 1);
        }
    }
    ll m = sum[n-1];
    //cout << m << nl;
//
    //for (auto it = s.begin(); it != s.end(); it++) {
    //    cout << *it << "\n";
    //}
//
    //forn(i,n)
    //{
    //    cout << sum[i] << " ";
    //}
    //cout << nl;

    forn(i,q)
    {
        if((ll)x[i] > m) cout << -1 << " ";
        else if (s.count(x[i]) == 1) cout << 0 << " ";
        else
        {
            ll k = upper_bound(sum, sum+n, x[i]) - sum - 1;
            ll elem = a[k];
            ll diff = abs(x[i]-sum[k]);
            if(x[i] == m) cout << a[n-1] << " ";
            else cout << (a[k] <= a[k+1] ? elem + diff : elem - diff) << " ";
        }
    }
    cout << nl;
    
    return 0;
}