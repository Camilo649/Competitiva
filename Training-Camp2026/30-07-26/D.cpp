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
    
    int n,m; cin >> n >> m;
    vector<pair<int,int>> v;
    forn(i,m)
    {
        int a;
        cin >> a;
        if(a > n/2) a = n/2;
        v.pb({a, i});
    }
    sort(v.begin(), v.end());

    int sum = 0;
    forn(i,m) sum += v[i].fst;
    bool flag = sum >= n;
    
    if(flag)
    {
        int res[n];
        pair<int,int> gallery = v.back(); v.pop_back();
        for(int i = 0; i<n; i+=2)
        {
            res[i] = gallery.snd;
            gallery.fst--;
            if(gallery.first <= 0) {gallery = v.back(); v.pop_back();}
        }
        for(int i = 1; i<n; i+=2)
        {
            res[i] = gallery.snd;
            gallery.fst--;
            if(gallery.first <= 0) {gallery = v.back(); v.pop_back();}
        }
        
        forn(i,n)
        {
            cout << res[i]+1 << " ";
        }
        cout << nl;
    }
    else
    {
        cout << -1;
    }
    cout << nl;
    
    return 0;
}