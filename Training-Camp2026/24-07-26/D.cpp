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

const int MAXN = -1;
const ll INF = 1e6;

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
        ll n; cin >> n;
        ll a[2*n]; forn(i,2*n) cin >> a[i];

        ll count1=0, count2=0;
        forn(i,2*n)
        {
            if(a[i] == 1) count1++;
            else count2++;
        }

        ll left[(2*n) + 4], right[(2*n) + 4];
        forn(i,(2*n) + 4)
        {
            left[i] = INF;
            right[i] = INF;
        }
        left[0] = 0;
        right[0] = 0;

        if(count1 >= count2)
        {
            ll diff = 0;
            dforn(i,n)
            {
                if(a[i] == 1)diff++;
                else diff--;

                if(diff >= 0) left[diff] = min((ll)((n-i)), left[diff]);
            }

            diff = 0;
            forr(i,n,2*n)
            {
                if(a[i] == 1)diff++;
                else diff--;

                if(diff >= 0) right[diff] = min((ll)((i-n)+1), right[diff]);
            }
        }
        else
        {
            ll diff = 0;
            dforn(i,n)
            {
                if(a[i] == 2)diff++;
                else diff--;

                if(diff >= 0) left[diff] = min((ll)((n-i)), left[diff]);
            }

            diff = 0;
            forr(i,n,2*n)
            {
                if(a[i] == 2)diff++;
                else diff--;

                if(diff >= 0) right[diff] = min((ll)((i-n)+1),right[diff]);
            }
        }

        forn(i,(2*n) + 4)
        {
            cout << left[i] << " ";
        }
        cout << nl;
        forn(i,(2*n) + 4)
        {
            cout << right[i] << " ";
        }
        cout << nl;

        ll res = INF;
        ll l = 0;
        ll r = abs(count1-count2);
        forn(i,abs(count1-count2)+1)
        {
            res = min (left[l] + right[r], res);
            r--; l++;
        }
        
        cout << res << nl;
    }
    
    return 0;
}