#include <bits/stdc++.h>

#define forr(i,a,b) for(int  i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)

#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const ll M = 1e9 + 7;

using namespace std;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    ll N; cin >> N;
    N = N%M;

    //cout << N << nl;

    ll count[26] = {};
    forn(i,SZ(s))
    {
        count[s[i]-'a']++;
    }

    // forn(i,26) cout << count[i] << " ";
    // cout << nl;

    ll ans = 0;
    ll count2[26] = {};
    forn(i,SZ(s))
    {
        count2[s[i]-'a']++;

        ll l = 0;
        forr(j,s[i]-'a'+1,26)
        {
            l += count2[j];
        }

        ll n = 0;
        forr(j,s[i]-'a'+1,26)
        {
            n += count[j];
        }

        ans = (ans + (N*l)%M)%M;
        if(N%2 == 0) ans = (ans + ((n*(N-1))%M * (N/2))%M)%M;
        else         ans = (ans + ((n*((N-1)/2))%M * N)%M)%M;
    }

    cout << ans << nl;

    return 0;
}