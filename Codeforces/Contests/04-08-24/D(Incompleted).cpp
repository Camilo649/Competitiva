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
        int n,k;
        cin >> n >> k;

        vector<int> v(n);
        forn(i,n){
            cin >> v[i];
        }

        int length = n - k*(n/k);
        if(length == 0) length = k;

        if (length == n)
        {
            sort(v.begin(),v.end());
            int index = n/2;
            if (n%2==0) --index;
            cout << v[index] << nl;
        }
        else
        {
            vector<int> aux;
            forn(i,length){
                int mx = 0;
                for (int j = i; j < n; j+=k)
                {
                    mx = max(mx,v[j]);
                }
                aux.pb(mx);
            }
            sort(aux.begin(),aux.end());
            int index = aux.size()/2;
            if (aux.size()%2==0) --index;
            cout << aux[index] << nl;
        }
    }
    

    return 0;
}