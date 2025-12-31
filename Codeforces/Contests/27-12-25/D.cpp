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
        int n,m; cin >> n >> m;
        int a[n];
        forn(i,n) cin >> a[i];

        if(2*m > n)
        {
            cout << -1 << nl;
        }
        else if(m == 0)
        {
            vector<pair<int, int>> v;
            forn(i,n)
            {
                v.pb({a[i], i});
            }
            sort(v.begin(), v.end());

            vector<pair<int,int>> ans;

            ll sum = 0;
            int j = 0;
            while (sum < v[n-1].fst - v[n-2].fst && j < n-2)
            {
                sum += v[j].fst;
                j++;
            }
            if (sum < v[n-1].fst - v[n-2].fst)
            {
                cout << -1 << nl;
            }
            else
            {
                forr(i,j,n-1)
                {
                    ans.pb({v[i].snd+1, v[i+1].snd+1});
                }

                forn(i,j)
                {
                    ans.pb({v[i].snd+1, v[n-1].snd+1});
                }

                cout << ans.size() << nl;
                forn(i, ans.size())
                {
                    cout << ans[i].fst << " " << ans[i].snd << nl;
                }
            }
        }
        else
        {
            vector<pair<int, int>> v;
            forn(i,n)
            {
                v.pb({a[i], i});
            }
            sort(v.begin(), v.end());

            vector<pair<int,int>> ans;

            forn(i,n-2*m)
            {
                ans.pb({v[i].snd+1, v[i+1].snd+1});
            }

            forr(i,n-2*m,n-m)
            {
                ans.pb({v[n-i+(n-2*m)-1].snd+1, v[i].snd+1});
            }

            cout << ans.size() << nl;
            forn(i, ans.size())
            {
                cout << ans[i].fst << " " << ans[i].snd << nl;
            }
        }
    }
    
    return 0;
}