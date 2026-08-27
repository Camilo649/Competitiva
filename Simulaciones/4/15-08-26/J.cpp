#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define SZ(x) ((int) x.size())
#define ALL(x) sort(x.begin(), x.end())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 50000+6;
const ll inf = 1e18;

using namespace std;

int n;
ll T;
int d[MAXN] = {};
ll dpv[MAXN];

bool feasible(int s)
{
    forn(i, n) dpv[i] = inf;
    dpv[0] = 0;

    // deque guarda indices i (0 <= i <= m-1), monotonico creciente en (dpv[i]-i)
    deque<int> dq;
    dq.push_back(0);

    forr(m, 1, n)
    {
        // sacar del frente los indices que quedaron fuera de la ventana [m-s, m-1]
        while (!dq.empty() && dq.front() < m - s) dq.pop_front();

        if (!dq.empty() && dpv[dq.front()] < inf)
        {
            int i = dq.front();
            ll cost = dpv[i] + (m - i) + (m == n-1 ? 0 : d[m]);
            dpv[m] = cost;
        }

        // insertar m en el deque, manteniendo monotonicidad de (dpv[i]-i)
        while (!dq.empty() && dpv[dq.back()] - dq.back() >= dpv[m] - m) dq.pop_back();
        dq.push_back(m);
    }

    return dpv[n-1] <= T;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> T;
    vector<pair<int,int>> v;
    forr(r,1,n)
    {
        int p; cin >> p;
        v.pb({p,r});
    }

    forr(i,1,n-1)
    {
        cin >> d[i];
    }

    ALL(v);

    vector<pair<int,int>> f;
    int maxr = 0;
    forn(i,n-1)
    {
        if(v[i].snd > maxr)
        {
            f.pb(v[i]);
            maxr = v[i].snd;
        }
    }

    int a = 0, b = SZ(f)-1;
    int k;
    while (a <= b) {
        k = (a+b)/2;
        if (feasible(f[k].second)) b = k-1;
        else a = k+1;
    }

    cout << f[a].first << nl;

    return 0;
}