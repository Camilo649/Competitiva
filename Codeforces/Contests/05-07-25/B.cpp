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

const int MAXN = 1e4 + 6;

using namespace std;
 
int tests;


bool canPartition(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2 != 0) return false;

    int target = total / 2;
    bitset<MAXN> dp;
    dp[0] = 1;
    for (int x : nums)
        dp |= (dp << x);
    return dp[target];
}


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
        int n, px, py, qx, qy;
        cin >> n >> px >> py >> qx >> qy;
        vector<int> v;
        ld sum = 0;
        forn(i,n)
        {
            int a;
            cin >> a;
            sum += (ld)a;
            v.pb(a);
        }

        ld e = (px-qx)*(px-qx) + (py-qy)*(py-qy);
        e = sqrtl(e);
        if (sum < e)
        {
            cout << "NO";
        }
        else if (e == 0)
        {
            canPartition(v) ? cout << "YES" : cout << "NO";
        }
        else
        {
            n == 1 && v[0] != e ? cout << "NO" : cout << "YES";
        }
        cout << nl;
    }
    
    return 0;
}