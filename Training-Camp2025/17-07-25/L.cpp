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

const int MAXN = 1e5+6;
const double EPS = 1e-10;

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
    
    cin >> tests;

    while (tests--)
    {
        ll n,m; cin >> n >> m;
        ll a[n];
        ll charge[n];
        forn(i,n)
        {
            cin >> a[i];
            charge[i] = a[i];
        }

        priority_queue<pair<ll,ll>> t;
        vector<pair<ll,ll>> next;
        forn(i,m)
        {
            ll dist,bat; cin >> dist >> bat; bat--;
            t.push({-dist,bat});
            next.pb({dist,bat});
        }

        sort(next.begin(), next.end());

        ll res = 0;
        bool flag = true;
        ll i = 0;
        ll time = 0;
        while (!t.empty() && flag)
        {
            auto ti = t.top(); t.pop();
            time = -ti.first;
            i = ti.second;
            while (time-res != 0 && flag)
            {
                ll x = min(time-res, charge[i]);
                res += x; charge[i] -= x;
                ll time_aux = time + 1;
                while (time-res != 0 && flag)
                {
                    auto it = lower_bound(
                        next.begin(), next.end(), 
                        make_pair(time_aux, -1LL),          
                        [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
                            return a.first < b.first;
                        }
                    );
                    if (it == next.end())
                    {
                        forn(i,n)
                        {
                            res += charge[i];
                            charge[i] = 0;
                        }
                        flag = false;
                        if (res >= time)
                        {
                            time = -ti.first;
                            res += a[ti.second];
                        }
                    }
                    else
                    {
                        i = it->second;
                        x = min(time-res, charge[i]);
                        res += x; charge[i] -= x;
                        time_aux = it->first + 1;
                    }
                }
            }
            if (time-res == 0)
            {
                charge[ti.second] = a[ti.second];
            }
        }

        forn(i,n)
        {
            res += charge[i];
        }

        while (!t.empty() && res >= time)
        {
            auto ti = t.top(); t.pop();
            time = -ti.first;
            res += a[ti.second]; 
        }

        cout << res << nl;
    }
    
    return 0;
}