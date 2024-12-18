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
 
int t;

int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> t;

    while (t--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        int sum = a + b + c;
        int p = sum/9;
        a -= p; b-=p; c-=p;
        if ((a<0) || (b<0) || (c<0))
        {
            cout << "NO" << nl;
            continue;
        }

        if (sum%9 == 0)
        {
            cout << "YES" << nl;
            continue;
        }
        else 
        {
            cout << "NO" << nl;
            continue;
        }
           
    }
    

    return 0;
}