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
const double EPS = 1e-10;

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
    
    ll n; cin >> n;
    ll v[n];
    forn(i,n)
    {
        cin >> v[i];
    }

    bool flag = true;
    ll base = 0;
    ll sum[n+1];
    sum[0] = 0;
    forn(i,n)
    {
        if (i != (n-1) && v[i] > v[i+1])
        {
            flag = false;
        }
        base += v[i]*(i+1);
        sum[i+1] = sum[i] + v[i];
    }

    if (flag)
    {
        cout << base << nl;
    }
    else
    {
        priority_queue<ll> pq;
        forn(i,n)
        {
            ll x = 0;
            ll a = i , b = n-1;
            while (a <= b) {
                ll val1 = v[i]*(b-a)-(sum[b+1] - sum[a+1]);
                if (val1 > x) {
                    b = (a+b)/2 + 1;
                    x = val1;
                }
                else
                {
                    b = (a+b)/2 - 1;
                } 
            }
            
            a = 0, b = i;
            while (a <= b) {
                ll val1 = (sum[b+1] - sum[a+1]) - v[i]*(b-a);
                if (val1 > x) {
                    a = (a+b)/2 - 1;
                    x = val1;
                }
                else
                {
                    a = (a+b)/2 + 1;
                } 
            }
            pq.push(base + x);
        }

        cout << pq.top() << nl;
    }
    
    return 0;
}