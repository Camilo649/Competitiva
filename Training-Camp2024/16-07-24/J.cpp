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
#define MAT
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 100;

using namespace std;
 
int n,k;

int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> n >> k;

    unordered_set<int> s;
    vector<int> res;
    //memset(&res, -1, sizeof(int)*MAXN);
    forn(i,n) {
        int a;
        cin >> a;
        if(s.count(a) == 1) continue;
        s.insert(a);
        res.push_back(i+1);
    }

    if (k > res.size())
    {
        cout << "NO" << nl;
    }
    else
    {
        cout << "YES" << nl;
        forn(i,k) {
            cout << res[i] << ' ';
        }
        cout << nl;
    }
    
    


    return 0;
}