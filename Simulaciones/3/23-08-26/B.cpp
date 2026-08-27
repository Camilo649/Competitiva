#include <bits/stdc++.h>

#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)

#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), e.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n';

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1e6 + 6;

using namespace std;

bitset<MAXN> isPrime;
void criba() {
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for(int p = 2; p<MAXN; p++)
    {
        if(isPrime[p])
        {
            for(int m = 2*p; m < MAXN; m += p) isPrime[m] = false;
        }
    }
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;

    criba();

    if(isPrime[n])
    {
        cout << 1 << nl;
        cout << 1 << " " << 1 << nl;
        return 0;
    }

    vector<int> res;
    forr(i,1,n/2 + 1)
    {
        if(isPrime[i] && n%i == 0) res.pb(n/i);
    }

    cout << SZ(res) << nl;
    forn(i,SZ(res))
    {
        cout << 1 << " " << res[i] << nl;
    }    
    
    return 0;
}