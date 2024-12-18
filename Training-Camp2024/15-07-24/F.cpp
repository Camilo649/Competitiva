#include<bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(ll i = (ll) a; i < (ll) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(ll i = (ll) b-1; i >= (ll) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define sz(x) ((ll) x.size())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';
//#define CAM
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const ll MAXN = 1e5 + 10;

using namespace std;
 
ll n,m;

int main()
{
    #ifdef CAM
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> n >> m;

    deque<ll> PrefixSumMZ[m+1];
    forn(i,n) {
        ll s,r;
        cin >> s >> r;
        PrefixSumMZ[s-1].push_back(r);
    }

    forn(i,m) {
        sort(PrefixSumMZ[i].rbegin(), PrefixSumMZ[i].rend());
    }

    forn(i,m) {
        PrefixSumMZ[i].push_front(0);
    }

    ll sum [MAXN];
    memset(sum, 0, sizeof(ll)*MAXN);
    sum[0] = 0;
    forn(i,m) {
        for (ll j = 1; j < PrefixSumMZ[i].size(); j++)
        {
            PrefixSumMZ[i][j] += PrefixSumMZ[i][j-1];
            if (PrefixSumMZ[i][j] < 0)
            {
                continue;
            }
            sum[j] += PrefixSumMZ[i][j];
        }
    }
/*
    forn(i,m+1) {
        forn(j,PrefixSumMZ[i].size()) {
            cout << PrefixSumMZ[i][j] << ' ';
        }
        cout << nl;
    }

    forn(i,m+2) {
        cout << sum[i] + 1 << ' ';
    }
*/
/*
    priority_queue<ll> pq;
    pq.push(0);
    ll sum;

    for (ll i = 1; i <= n; i++)
    {
        sum = 0;
        forn(j,m) {
            if ((PrefixSumMZ[j].size() < i+1) || (PrefixSumMZ[j][i]  < 0))
            {
                continue;
            }
            sum += PrefixSumMZ[j][i];
        }
        pq.push(sum);
    }
    
    cout << pq.top() << nl;
*/

    ll j = 1;
    ll max = 0;
    while (sum[j] != 0)
    {
        if (sum[j] > max)
        {
            max = sum[j];
        }
        ++j;
    }

    cout << max << nl

    return 0;
}