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

ll sum(vector<ll> v)
{
    ll s = 0;
    forn(i,v.size())
    {
        s += v[i];
    }
    return s;
}

void op2(vector<ll> &v)
{
    forn(i,v.size()-1)
    {
        v[i] = v[i+1] - v[i];
    }
    v.pop_back();
}

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
        int n;
        cin >> n;
        vector<ll> v;
        forn(i,n)
        {
            int a;
            cin >> a;
            v.pb(a);
        }

        ll s = sum(v), si = s;
        ll mx = s;
        while (v.size() > 1  && (mx >= s || mx >= si))
        {
            vector<ll> vi(v.rbegin(),v.rend());
            s = sum(v);
            si = sum(vi);
            op2(v); op2(vi);
            if (si > s)
            {
                v = vi;
            }
            mx = max(mx,max(sum(v),sum(vi)));
        }

        cout << mx << nl;
    }
    
    return 0;
}