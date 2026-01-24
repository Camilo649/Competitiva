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

int MEX(vector<int> v)
{
    sort(v.begin(), v.end());
    int mex = 0;
    forn(i,v.size())
    {
        if(v[i] == mex) mex++;
        else if(i>0 && v[i] == v[i-1]) continue;
        else break;
    }

    return mex;
}

bool check(vector<int> v)
{
    bool flag = true;
    forn(i,v.size()-1)
    {
        vector<int> b1;
        forn(j,i+1) b1.pb(v[j]);
        int mex1 = MEX(b1);
        vector<int> b2;
        forr(j,i+1,v.size()) b2.pb(v[j]);
        int mex2 = MEX(b2);
        if(mex1 == mex2) 
        {
            flag = false;
            break;
        } 
    }

    return flag;
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
        int n; cin >> n;
        vector<int> v; 
        forn(i,n) 
        {
            int a;
            cin >> a;
            v.pb(a);
        }

        sort(v.rbegin(),v.rend());

        if(check(v)) cout << "YES";
        else cout << "NO";
        cout << nl;
    }
    
    return 0;
}