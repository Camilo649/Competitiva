#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;

// Debugging
#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    if (DBG) os << "[";
    for (auto& x : v) os << x << (DBG ? ", " : " ");
    return DBG ? os << "]" : os;
}

template<typename S, typename T> ostream& operator<<(ostream& os, const pair<S, T>& p) {
    return os << (DBG ? "(" : "") << p.fst << (DBG ? ", " : " ") << p.snd << (DBG ? ")" : "");
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s; cin >> s;
    int n = SZ(s);

    bool dp[n][n] = {};
    for(int len = 3; len <= n; len += 3)
    {
        for(int L = 0; L+len-1 < n; L++)
        {
            int R = L + len - 1;    
            for (int k = L + 2; k < R; k += 3) {
                if (dp[L][k] && dp[k + 1][R]) {
                    dp[L][R] = true;
                }
            }

            if (dp[L][R]) continue;

            for (int i = L + 1; i < R; i++) {
            
                if (s[L] != s[i] && s[i] != s[R] && s[L] != s[R]) {
                    
                    bool left_ok  = (i == L + 1) ? true : dp[L + 1][i - 1];
                    bool right_ok = (i == R - 1) ? true : dp[i + 1][R - 1];
                    
                    if (left_ok && right_ok) {
                        dp[L][R] = true;
                        break;
                    }
                }
            }
        }
    }

    if(dp[0][n-1]) cout << "S";
    else cout << "N";
    cout << nl;
    
    return 0;
}