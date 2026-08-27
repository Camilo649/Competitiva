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

const int MAXN = -1;

using namespace std;
 
string num; // dígitos de N como string
int global_sum = 0;
ll dp[14][2][109][108]; // dp[pos][tight][partial_sum][res]
bool vis[14][2][109][108];   // vis[pos][tight][partial_sum][res] 

ll solve(int pos, bool tight, int partial_sum, int res) {
    if (pos == (int)num.size()) return partial_sum == global_sum && res == 0;
    if (vis[pos][tight][partial_sum][res]) return dp[pos][tight][partial_sum][res];
    vis[pos][tight][partial_sum][res] = true;

    int limit = tight ? (num[pos] - '0') : 9;
    ll ans = 0;
    for (int dig = 0; dig <= limit; dig++) {
        bool nt = tight && (dig == limit);
        ans += solve(pos + 1, nt, partial_sum + dig, (res*10+dig)%global_sum);
    }
    return dp[pos][tight][partial_sum][res] = ans;
}

ll UpTo(ll N) {
    if (N < 0) return 0;
    num = to_string(N);
    ll ans = 0;
    forr(sum,1,109)
    {
        memset(vis, 0, sizeof(vis));
        global_sum = sum;
        ans += solve(0, true, 0, 0);
    }
    return ans;
}

int main()
{
    #ifdef ONLINE_JUDGE
        freopen("just.in","r",stdin);
        freopen("just.out","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll N; cin >> N;

    cout << UpTo(N);
    
    return 0;
}