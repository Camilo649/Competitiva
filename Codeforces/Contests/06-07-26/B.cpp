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
        int n; cin >> n;
        int a[n]; forn(i,n) cin >> a[i];

        int i = 0;
        bool flag1 = false;
        int seg1 = 0;
        int ones = 0;
        while(i<n && !flag1)
        {
            seg1++;
            if(a[i] == 1) ones++;
            if(ones >= (seg1+1)/2) flag1 = true;
            i++;
        }

        while (i<n && ones > (seg1)/2 && a[i] == 3)
        {
            seg1++;
            i++;
        }
    
        bool flag2 = false;
        int ones_or_twos = 0;
        int seg2 = 0;
        while(i<n && !flag2)
        {
            seg2++;
            if(a[i] != 3) ones_or_twos++;
            if(ones_or_twos >= (seg2+1)/2) flag2 = true;
            i++;
        }

        if(flag2 && i!=n) {cout << "YES" << nl;}
        else {cout << "NO" << nl;}
    }
    
    return 0;
}