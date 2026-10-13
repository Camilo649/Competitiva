#include <bits/stdc++.h>

#define forr(i,a,b) for(int  i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)

#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

using namespace std;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    map<int,int> m;
    forn(i,3*n)
    {
        int b; cin >> b;
        m[b]++;
    }

    bool flag = true;
    for(auto p : m)
    {
        //cout << p.fst << " " << p.snd << nl;
        flag &= p.snd%3 == 0;
    }

    if(flag) cout << "N";
    else cout << "Y";
    cout << nl;

    return 0;
}