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

const int MAXN = 2e5 + 2;

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
        bitset<MAXN> printed;
        int n; cin >>  n;
        string s; cin >> s;
        vector<int> stack;
        forn(i,n)
        {
            if(s[i] == '1')
            {
                stack.pb(i);
            }
            else if(s[i] == '2')
            {
                if(!stack.empty())
                {
                    printed[stack.back()] = 1;
                    stack.pop_back();
                }
                else
                {
                    printed[i] = 1;
                }
            }
            else
            {
                printed[i] = 1;
            }
        }

        vector<int> ans;
        forn(i,n)
        {
            //print(i); print(printed[i]);
            if(!printed[i]) ans.pb(i+1);
        }
        
        cout << SZ(ans) << nl;
        forn(i,SZ(ans)) cout << ans[i] << " ";
        cout << nl;
    }

    
    return 0;
}