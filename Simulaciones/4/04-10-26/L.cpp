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

struct StrHash {
    using ull = unsigned long long;

    ull base;
    vector<ull> h, p;

    StrHash(const string& s) {
        int n = s.size();

        // base aleatoria impar
        base = chrono::steady_clock::now().time_since_epoch().count() | 1;

        h.assign(n+1, 0);
        p.assign(n+1, 1);

        for (int i = 0; i < n; ++i) {
            h[i+1] = h[i] * base + (unsigned char)s[i];
            p[i+1] = p[i] * base;
        }
    }

    // hash de s[l, r)
    ull get(int l, int len) const {
        return h[l+len] - h[l] * p[len];
    }
};

int get_lcp(StrHash& sh, int i, int j, int max_len)
{  
    int a = 0, b = max_len;
    while (a <= b) {
        int k = (a+b)/2;
        if (sh.get(i,k) == sh.get(j,k)) a = k+1; // Coinciden, intentamos buscar una longitud mayor
        else b = k-1;                            // Falló, achicamos la longitud
    }

    return a-1;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string t; cin >> t;
    int d; cin >> d;
    int n = SZ(t);
    
    StrHash sh(t);

    int ans = 0;
    int currpos = 0;
    while(currpos<n)
    {
        int max_jump = -1;
        forr(i,currpos+1,min(n,currpos+d+1))
        {
            int jump = get_lcp(sh, currpos, i, n-i);
            max_jump = max(max_jump, jump+(i-currpos));
        }
        currpos += max(max_jump, d);
        ans++;
    }

    cout << ans << nl;

    return 0;
}