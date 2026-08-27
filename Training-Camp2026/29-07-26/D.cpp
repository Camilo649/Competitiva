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

const int MAXN = 101;

using namespace std;
 
bitset<MAXN> isPrime;
void criba() {
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for(int p = 2; p < MAXN; p++) {
        if (isPrime[p]) {
            for(int m = 2*p; m < MAXN; m += p) isPrime[m] = false;
        }
    }
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif

    fflush(stdout);

    criba();

    int countYes = 0;
    forr(i,2,50)
    {
        if(isPrime[i])
        {
            cout << i << nl;
            string res; cin >> res;
            if(res == "yes") 
            {
                countYes++;
                if(i*i <= 100)
                {
                    cout << (i*i) << nl;
                    string res; cin >> res;
                    if(res == "yes") countYes++;
                }
            }
        }
    }
    
    if(countYes >= 2)
    {
        cout << "composite" << nl;
    }
    else
    {
        cout << "prime" << nl;
    }
    
    
    return 0;
}