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

const int MAXN = 1e6 + 6;

using namespace std;
 
int tests;

bitset<MAXN> isPrime;
void criba(int n) {
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for(int p = 2; p < n; p++) {
        if (isPrime[p]) {
            for(int m = 2*p; m < n; m += p) isPrime[m] = false;
        }
    }
}

vector<int> Primes;
void getPrimes(int n) {
    Primes.clear();
    for (int d = 1; d * d <= n; d++) {
        if (n%d == 0) {
            if(isPrime[d] && d != 1) Primes.push_back(d);
            if(isPrime[n/d] && n/d != 1) Primes.push_back(n/d);
        }
        if (d*d == n);
    }
    // sort(Primes.begin(), Primes.end()); // OPCIONAL
}

int is_pot(int x)
{
    getPrimes(x);
    if(Primes.empty()) return 0;
    if(Primes.size() == 1) return Primes[0];
    bool flag = true;
    forn(i,(int)(Primes.size()-1)) flag &= (Primes[i] == Primes[i+1]);

    return flag ? Primes[0] : 0;
}

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    criba(MAXN);
    isPrime[1] = 1; // jejejejeje

    cin >> tests;

    while (tests--)
    {
        int n; cin >> n;
        int a[n]; forn(i,n) cin >> a[i];

        bool is_sorted = true;
        forn(i,n-1)
        {
            is_sorted &= (a[i] <= a[i+1]);
        }

        if(is_sorted) cout << "Bob";
        else
        {
            bool flag = false;
            forn(i,n)
            {
                int pot = is_pot(a[i]);
                if(pot)
                {
                    a[i] = pot;
                }
                else if(isPrime[a[i]] == 0)
                {
                    flag = true;
                    break;
                }
            }

            is_sorted = true;
            forn(i,n-1)
            {
                is_sorted &= (a[i] <= a[i+1]);
            }

            if(flag || !is_sorted)
            {
                cout << "Alice";
            }
            else
            {
                cout << "Bob";
            }
        }

        cout << nl;
    }
    
    return 0;
}