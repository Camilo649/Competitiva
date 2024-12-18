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
typedef unsigned long long ll;
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
        ll n,m;
        cin >> n >> m;

        vector<int> v;
        forn(i,n){
            int e;
            cin >> e;
            v.push_back(e);
        }

        sort(v.begin(),v.end());

        ll mx = 0;
        ll actualCount, siguienteCount;
        actualCount = 1;
        int i = 0;
        while ((i<n-1) && (v[i] == v[i+1]))
        {
            actualCount++;
            ++i;
        }
        while (i<n) {
            siguienteCount = 1;
            int j = i+1;
            while ((j<n-1) && (v[j] == v[j+1]))
            {
                siguienteCount++;
                ++j;
            }
            ll value;
            ll cuanto;
            if (v[i] == v[j]-1) {
                forn(k,actualCount+1){
                    value = k*v[i];
                    if(value > m) break;
                    cuanto = min(siguienteCount, (m-value)/v[j]);
                    mx = max(mx,value + cuanto*v[j]);
                }
            }
            else
            {
                cuanto = min(actualCount, m/v[i]);
                mx = max(mx, cuanto*v[i]);
            }
            
            actualCount = siguienteCount;
            i=j;
        }
        if (actualCount == n) mx = (m/v[0])*v[0];
        
        cout << mx << nl;
    }

    return 0;
}