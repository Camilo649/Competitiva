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
#define GG
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int tests;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    while (tests--)
    {
        int n; cin >> n;
        vector<int> a(2*n); 
        forn(i, 2*n) {
            cin >> a[i]; 
            a[i]--;
        }

        int l[n], r[n];
        forn(i,n) {l[i] = -1; r[i] = -1;}
        forn(i,2*n)
        {
            if(l[a[i]] == -1) l[a[i]] = i;
            else r[a[i]] = i;
        }
        
        vector<vector<pair<int, long long>>> ends_at(2*n + 1);
        for (int i = 0; i < n; i++) {
            long long len = r[i] - l[i] + 1;
            long long weight = len * len - len;
            ends_at[r[i] + 1].push_back({l[i] + 1, weight});
        }

        ll dp[2*n+1]; dp[0] = 0;
        forr(i,1,2*n+1)
        {
            dp[i] = dp[i-1];
            for(auto p : ends_at[i])
            {
                int left = p.fst;
                ll weight = p.snd;
                dp[i] = max(dp[i], dp[left-1] + weight);
            }
        }

        cout << dp[2*n] + 2*n << nl;
    }
    
    return 0;
}