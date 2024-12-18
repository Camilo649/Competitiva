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
#define CAM
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int t,n;

int main()
{
    #ifdef CAM
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> t;

    while (t--)
    {
        cin >> n;
        int a[n];
        forn(i,n){
            cin >> a[i];
        }

        int max=0;
        for (int i = 0; i < n; i+=2)
        {
            if(a[i]>max) max = a[i];
        }
        cout << max<<nl;
    }
    

    return 0;
}