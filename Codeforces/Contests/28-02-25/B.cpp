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
#define MILF
// redefiniciones
typedef long long ll;
typedef long double ld;
 
using u64 = uint64_t;
 
const int MAXN = -1;
 
using namespace std;
 
int tests;
 
int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;
 
    while (tests--)
    {
        ll n;
        cin >> n;
        ll r = sqrt((n*(n+1))/2);
        if (r*r == (n*(n+1))/2)
        {
            cout << -1 << nl;;
        }
        else
        {
            vector<int> p;
            forr(i,1,n+1)
            {
                p.pb(i);
            }
            ll num = 1;
            ll pow = num*num;
            ll sum = 0;
            int index = 0;
        
            forn(i,n-1)
            {
                sum += p[i];
                if (sum == pow)
                {
                    swap(p[i],p[i+1]);
                    sum++;
                }
                while (pow < sum)
                {
                    num++;
                    pow = num*num;
                }
            }
        
            for (int i = 0; i < n; i++) cout << p[i] << " ";
            cout << "\n";
        }
        
    }
    
    return 0;
}