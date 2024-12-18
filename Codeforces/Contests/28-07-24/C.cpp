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

const int MAXN = 1e9;

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

        int maxIndex,minIndex;
        int mx = 0;
        int mn = MAXN;
        forn(i,n) {
            if (a[i] > mx)
            {
                mx = a[i];
                maxIndex = i;
            }
            if (a[i] < mn)
            {
                mn = a[i];
                minIndex = i;
            }
        }
        int k = 0;
        int restar = (mx+1)/2;
        vector<int> x;
        int zeroCount = 0;
        if (mx != 0) {
            while (k<40)
            {
                x.pb(restar);
                zeroCount = 0;
                forn(i,n){
                    a[i] = abs(a[i] - restar);
                    if(a[i] == 0) ++zeroCount;
                }
                if(a[maxIndex] >= a[minIndex]) restar = (a[maxIndex]+1)/2;
                else restar = (a[minIndex]+1)/2;
                ++k;
                if (zeroCount == n) break;
            }
        }
        
        if ((zeroCount == n) || (k == 0)) {
            cout << k << nl;
            forn(i,x.size()){
                cout << x[i] << ' ';
            }
        }
        else {
            cout << -1;
        }

        cout << nl;
    }
    

    return 0;
}