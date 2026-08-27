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

const int MAXN = 2e5 + 3;

using namespace std;
 
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
        string a,b; cin >> a >> b;

        if(n<=2)
        {
            if(a==b) 
            {
                cout << 0 << nl;
            }
            else 
            {
                cout << -1 << nl;
            }
            continue;
        }

        bitset<MAXN> ba(a);
        bitset<MAXN> bb(b);
        if(ba.count() != bb.count())
        {
            cout << -1 << nl;
            continue;
        }

        queue<int> par, impar;
        int impara = 0, para = 0;
        forn(i,n)
        {
            if(a[i] == '1')
            {
                if(i%2==0) {para++; par.push(i);}
                else {impara++; impar.push(i);}
            }
        }
        
        int imparb = 0, parb = 0;
        forn(j,n)
        {
            if(b[j] == '1')
            {
                if(j%2==0) parb++;
                else imparb++;
            }
        }


        if(impara == imparb && para == parb) 
        {
            ll res = 0;
            forn(j,n)
            {
                if(b[j] == '1')
                {
                    if(j%2==0)
                    {
                        int pos = par.front(); par.pop();
                        res += abs(j-pos)/2;
                    }
                    else
                    {
                        int pos = impar.front(); impar.pop();
                        res += abs(j-pos)/2;
                    }
                }
            }

            cout << res;
        }
        else cout << -1;

        cout << nl;
    }
    
    return 0;
}