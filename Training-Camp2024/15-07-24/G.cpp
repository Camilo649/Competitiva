#include<bits/stdc++.h>

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
#define MAT
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;

void solve(vector<ll>&P, vector<ll> A, int m) {
    if (A[m] == 0)
    {
        return;
    }
    else
    {
        --A[m];
        int j = m + 1;
        while (j < A.size())
        {
            A[j] = 9;
            ++j;
        }
    }
    forn(i, A.size()) {
        if ((i == 0) && (A[i] == 0))
        {
            continue;
        }
        P[m] *= A[i];
    }
}

int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif

    string s;
    cin >> s;
    vector<ll> A;
    forn(i,s.size()) {
        A.push_back(s[i] - '0');
    }

    ll initialProd = 1;
    forn(i,A.size()) {
        initialProd *= A[i];
    }

    //cout << initialProd;

    vector<ll> Prods;
    forn(i,A.size()) {
        Prods.push_back(1);
    }

    ll prod = 0;

    forn(i, A.size()) {
        
        solve(Prods, A, i);
        //cout << Prods[i] << ' ';
        if (prod < Prods[i]) prod = Prods[i];
    }

    cout << max(initialProd, prod) << nl;

    return 0;
}
