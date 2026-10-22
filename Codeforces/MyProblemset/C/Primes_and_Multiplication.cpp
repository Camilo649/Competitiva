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
    const ll M = 1e9+7;

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

    ll bin_pow(ll x, ll n) {
        if(n == 0) return 1;
        if (n == 1) return x;
        if (n % 2 == 0) return bin_pow((x*x)%M, n/2)%M;
        return (x * bin_pow(x, n - 1))%M;
    }

    vector<ll> Div;
    void getDiv(ll n) {
        Div.clear();
        for (ll d = 1; d * d <= n; d++) {
            if (n%d == 0) {
                Div.push_back(d);
                Div.push_back(n/d);
            }
            if (d*d == n) Div.pop_back();
        }
        // sort(Div.begin(), Div.end()); // OPCIONAL
    }

    bool isPrime(int n) {
        if (n < 2) return false;
        for(int p = 2; p*p <= n; p++) {
            if(n%p == 0) return false;
        }
        return true;
    }

    int main()
    {
        #ifdef GG
            freopen("../input.txt", "r", stdin);
        #endif
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        ll x,n; cin >> x >> n;
        getDiv(x);

        // print("guacala");

        ll ans = 1;
        for(auto d : Div)
        {
            if(!isPrime(d)) continue;
            //print(d);
            ll exp_count = 0;
            ll pot = d;
            while(pot<=n)
            {
                exp_count += n/pot;
                if(n/pot < d) break;
                pot*=d;
            }
            
            ans = (ans*bin_pow(d,exp_count)) % M;
            //print(ans);
        }

        cout << ans << nl;

        return 0;
    }