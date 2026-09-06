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

const int MAXN = 2e5+4;

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

int getMEX(const vector<int>& v)
{
    bitset<MAXN> b;
    forn(i,SZ(v))
    {
        if(v[i] >= MAXN) continue;
        b[v[i]] = 1;
    }

    int ans = 0;
    while(b[ans]) ans++;
    return ans;
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
        int n; cin >> n;
        map<int,int> count;
        vector<int> A,B,C;
        string ans(n, ' ');
        int a[n];
        forn(i,n)
        {
            cin >> a[i];
            count[a[i]]++;
        }

        set<int> s;
        forn(i,n)
        {
            if(count[a[i]] >= 2)
            {
                if(s.count(a[i])) {ans[i] = 'A'; A.pb(a[i]);}
                else {ans[i] = 'B'; B.pb(a[i]); s.insert(a[i]);};
            }
            else {ans[i] = 'C'; C.pb(a[i]);}
        }

        
        int val[3];
        val[0] = getMEX(A);
        val[1] = getMEX(B);
        val[2] = getMEX(C);

        sort(val, val+3);

        int mx = val[2];
        int sum = 0; forn(i,3) sum += val[i];
        //print(mx); print(sum); print(ans);

        if(sum >= 2*mx) cout << "YES" << nl << ans;
        else cout << "NO";
        cout << nl;
    }
    
    return 0;
}