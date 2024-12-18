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
 
int t;

int main()
{
    #ifdef CAM
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll a[n];
        forn(i,n){
            cin >> a[i];
        }

        ll maxImpar=0;
        vector<int> pares;
        forn(i,n){
            if(a[i]%2==0) pares.pb(a[i]);
            else
            {
                maxImpar = max(maxImpar,a[i]);
            }
        }

        if(pares.size()%n==0){
            cout << 0 << nl;
        }
        else
        {
            int res = pares.size();
            sort(pares.begin(),pares.end());
            forn(i,pares.size()){
                if(pares[i] > maxImpar) {
                    res++;
                    maxImpar += pares[pares.size()-1];
                    --i;
                }
                else
                {
                    maxImpar += pares[i];
                }
            }
            cout << res << nl;
        }
    }
    

    return 0;
}