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
#define nl endl;
#define MILF
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;
const double EPS = 1e-10;

using namespace std;
 
int tests;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    while (tests--)
    {
        int n; cin >> n;
        
        int k = -1;
        for(int i = 3; i<2*n+1; i+=2)
        {

            cout << "?" << " " << i << " " << i+1 << nl;
            int res; cin >> res;
            if(res) {k = i; break;}
        }

        if(k==-1)
        {
            cout << "?" << " " << 1 << " " << 3 << nl;
            int res1; cin >> res1;
            cout << "?" << " " << 1 << " " << 4 << nl;
            int res2; cin >> res2;
            
            if(res1 || res2) k = 1;
            else k = 2;
        }

        cout << "!" << " " << k << nl;
    }
    
    return 0;
}