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
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1e6+6, M = 998244353;

using namespace std;
 
ll F[MAXN], INV[MAXN], FI[MAXN];

int tests;

ll nCr(int n, int k) {
    if (k < 0 || k > n) return 0;
    return F[n] * FI[k] % M * FI[n-k] % M;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    F[0] = 1; forr(i, 1, MAXN) F[i] = F[i-1]*i % M;
    INV[1] = 1; forr(i, 2, MAXN) INV[i] = M - (ll)(M/i)*INV[M%i]%M;
    FI[0] = 1; forr(i, 1, MAXN) FI[i] = FI[i-1]*INV[i] %M;

    while (tests--)
    {
        int n; cin >> n;
        string s; cin >> s;

        map<char,int> b;
        int i = 0;
        while (i<n-1)
        {
            char c = s[i];
            if(s[i] != s[i+1]) b[c]++;
            i++;
        }
        b[s[n-1]]++;
        
        map<string, int> c;
        forn(i,n-1)
        {
            string aux; aux += s[i]; aux += s[i+1];
            c[aux]++;
        }

        ll formas_0 = (b['0'] == 0) ? 1 : nCr(c["00"] + b['0'] - 1, b['0'] - 1);
        ll formas_1 = (b['1'] == 0) ? 1 : nCr(c["11"] + b['1'] - 1, b['1'] - 1);
        ll ans = (formas_0 * formas_1) % M;
        cout << ans << nl
    }
    
    return 0;
}