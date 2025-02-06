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
        int n;
        cin >> n;
        int a[n];
        set<int> s;
        vector<int> legs;
        forn(i,n)
        {
            cin >> a[i];
            if (s.count(a[i]) == 1)
            {
                legs.pb(a[i]);
            }  
            s.insert(a[i]);
        }

        if (legs.empty())
        {
            cout << -1 << nl;
        }
        else
        {
            sort(legs.begin(), legs.end());
            ld res[4];
            res[0] = legs[legs.size()-1];
            res[1] = res[0];
            sort(a, a+n);
            auto it = lower_bound(a,a+n,res[0]);
            *it = -1; 
            sort(a, a+n);
            it = lower_bound(a+1,a+n,res[0]);
            *it = -1;
            sort(a, a+n);

            int min_dif = INT_MAX;
            forr(i,2,n-1)
            {
                if (abs(a[i] - a[i+1]) < min_dif)
                {
                    min_dif = abs(a[i] - a[i+1]);
                    res[2] = a[i];
                    res[3] = a[i+1];
                }
            }

            if((res[0]*res[0] - (((res[3]-res[2])/2)*((res[3]-res[2])/2))) > 0)
            {
                forn(i,4)
                {
                    cout << (int)res[i] << ' ';
                }
                cout << nl;
                
            }
            else
            {
                cout << -1 << nl;
            }
        }
    }
    
    return 0;
}