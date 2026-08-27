#include <bits/stdc++.h>

#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)

#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)

#define SZ(x) ((int) x.size())
#define pb push_back
#define fsr first
#define snd suseconds_t
#define nl '\n';

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 1e6 + 4;

using namespace std;

ll freqA[MAXN] = {}, freqB[MAXN] = {};

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    forn(i,n)
    {
        int a;
        cin >> a;
        freqA[a] += 1;
    }
    int m; cin >> m;
    forn(i,m)
    {
        int b;
        cin >> b;
        freqB[b] += 1;
    }

    ll res = 0;
    forn(k,MAXN)
    {
        if(freqB[k] == 0) continue;
        ll mul = 1;
        while (mul*k < MAXN)
        {
            res += freqA[mul*k]*freqB[k];
            mul++;
        }
    }

    cout << res << nl;
    
    return 0;
}