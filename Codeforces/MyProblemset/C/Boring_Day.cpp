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

const int MAXN = 1e5;

using namespace std;
 
int t, n, l, r;
ll cards[MAXN];

// int solve (ll sum, int i)
// {
//     if (i >= n || sum > r)
//         return 0;
//     sum += cards[i];
//     if (sum >= l && sum <= r)
//         return 1 + solve(0,i+1);
//     return max(solve(sum,i+1), solve(0,i+1));
// }

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;

    while (t--)
    {
        cin >> n >> l >> r;
        forn(i,n)
        {
            cin >> cards[i];
        }

        vector<int> dp(n + 1);
	    int s = 0;
	    int j = -1;
	    for (int i = 0; i < n; i++){
	    	dp[i + 1] = max(dp[i + 1], dp[i]);
	    	if (j < i){
	    		j = i;
	    		s = 0;
	    	}
	    	while(j < n && s < l){
	    		s += cards[j++];
	    	}
	    	if (s >= l && s <= r){
	    		dp[j] = max(dp[j], dp[i] + 1);
	    	}
	    	s -= cards[i];
	    }
 
	    cout << dp[n] << nl;

    }

    return 0;
}