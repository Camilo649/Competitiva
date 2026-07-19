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

const int MAXN = 2e5 + 6;

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
        int n; cin >> n;
        int a[2*n]; forn(i,2*n) cin >> a[i];

        int l0 = -1, r0 = -1;
        forn(i,2*n)
        {
            if(a[i] == 0 && l0 == -1) l0 = i;
            else if(a[i] == 0) r0 = i;
        }

        int ans = 0;
        bitset<MAXN> b; b[0] = 1;
        int l = l0-1, r = l0+1;
        while (l>=0 && r < 2*n)
        {
            if(a[l] == a[r])
            {
                b[a[l]] = 1;
                l--;r++;
            }
            else break;
        }
        int mex = 0;
        while (b[mex])
        {
            mex++;
        }
        ans = max(ans,mex);

        b.reset(); b[0] = 1;
        l = r0-1; r = r0+1;
        while (l>=0 && r < 2*n)
        {
            if(a[l] == a[r])
            {
                b[a[l]] = 1;
                l--;r++;
            }
            else break;
        }
        mex = 0;
        while (b[mex])
        {
            mex++;
        }
        ans = max(ans,mex);

        b.reset(); b[0] = 1;
        bool flag = true;
        l = l0+1; r = r0-1;
        while (flag && l<=r)
        {
            flag &= a[l] == a[r];
            b[a[l]] = 1;
            l++; r--;
        }
        if(flag)
        {
            l = l0-1; r = r0+1;
            while (l>=0 && r < 2*n)
            {
                if(a[l] == a[r])
                {
                    b[a[l]] = 1;
                    l--;r++;
                }
                else break;
            }
            mex = 0;
            while (b[mex])
            {
                mex++;
            }
            ans = max(ans,mex);
        }

        cout << ans << nl;
        
    }
    
    return 0;
}