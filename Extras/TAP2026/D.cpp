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

bool solve(string s, string c)
{
    //cout << c << nl;

    int n = SZ(s);
    int a[n+1]; a[0] = 0;
    forn(i,n) a[i+1] = s[i] - '0';
    
    // forn(i,n+1) cout << a[i] << " ";
    // cout << nl;

    int m = SZ(c);
    forn(i,m)
    {
        a[n-i] += c[m-i-1] - '0';
        int j = n-i;
        while (j>=1 && a[j] > 9)
        {
            int d = a[j]/10;
            a[j] %= 10;
            a[j-1] += d;
            j--;
        }
    }

    // forn(i,n+1) cout << a[i] << " ";
    // cout << nl;

    int sum = 0;
    forn(i,n+1) sum += a[i];

    int val = 0;
    int d = 1;
    dforn(i,m)
    {
        val += (c[i]-'0')*d;
        d*=10;
    }

    // cout << sum << " " << val << nl;
    // cout << nl;

    return sum <= val;
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
    int a[n+1]; a[0] = 0;
    forn(i,n)
    {
        a[i+1] = (s[i] - '0')*9;
        int j = i;
        while (j>=0 && a[j+1] > 9)
        {
            int d = a[j+1]/10;
            a[j+1] %= 10;
            a[j] += d;
            j--;
        }
    }
    
    // forn(i,n+1) cout << a[i] << " ";
    // cout << nl; 

    string s9;
    forn(i,n+1) s9.append(to_string(a[i]));

    //cout << s9 << nl;

    int l = 0, r = 9*n;
    while (l <= r) {
        int c = (l+r)/2;
        if (solve(s9, to_string(c))) r = c-1;
        else l = c+1;
    }

   cout << l << nl;
    
    return 0;
}