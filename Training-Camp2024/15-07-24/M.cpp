#include<bits/stdc++.h>

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
#define MAT
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;

ll n,t;

int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> t;

    while (t--)
    {
        cin >> n;
        unordered_set<ll>s;
        for (ll i = 2; i <= sqrt(n); i++)
        {
            ll b = i*i;
            s.insert(b);
            b *= i;
            if ((b <= n && (s.count(b) == 0)))
            {
                s.insert(b);
            }  
        } 
        cout << (s.size() + 1) << nl;
    }

    return 0;
}