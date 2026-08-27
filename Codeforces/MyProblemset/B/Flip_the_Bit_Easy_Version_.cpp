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
        int n,k; cin >> n >> k;
        int a[n]; forn(i,n) cin >> a[i];
        int pos; cin >> pos; pos--;

        int resl = 0;
        int l = 0;
        while (l<=pos)
        {
            if(l<=pos && a[l] != a[pos]) 
            {
                resl++; l++;
                while (l<=pos && a[l] != a[pos]) l++;
                if(l<=pos && a[l] == a[pos]) {resl++; l++;}
                while (l<=pos && a[l] == a[pos]) l++;
            }
            else
            {
                l++;
            }
        }
        
        int resr = 0;
        int r = n-1;
        while (r>=pos)
        {
            if(r>=pos && a[r] != a[pos]) 
            {
                resr++; r--;
                while (r>=pos && a[r] != a[pos]) r--;
                if(r>=pos && a[r] == a[pos]) {resr++; r--;}
                while (r>=pos && a[r] == a[pos]) r--;
            }
            else
            {
                r--;
            }
        }

        cout << max(resl, resr) << nl;
    }
    
    return 0;
}