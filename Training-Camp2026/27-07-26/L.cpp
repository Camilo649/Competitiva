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
#define GG
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1e5+12;

using namespace std;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m; cin >> n >> m;
    ll c[n]; forn(i,n) cin >> c[i];
    ll w[n]; forn(i,n) cin >> w[i];

    ll r[n]; forn(i,n) r[i] = c[i]%100;

    ll total = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    bitset<MAXN> used;
    forn(i,n)
    {
        if(r[i]!=0)
        {
            pq.push({(100 - r[i]) * w[i], i});
            m -= r[i];
            if(m<0)
            {
                pair<ll,int> elem = pq.top(); pq.pop();
                used[elem.snd] = 1;
                total += elem.fst;
                m += 100;
            }
        }
    }

    cout << total << nl;

    forn(i,n)
    {
        if(r[i] == 0)
        {
            cout << c[i]/100 << " " << 0 << nl;
        }
        else if(!used[i])
        {
            cout << c[i]/100 << " " << r[i] << nl;
        }
        else
        {
            cout << c[i]/100 + 1 << " " << 0 << nl;
        }
    }
    
    return 0;
}