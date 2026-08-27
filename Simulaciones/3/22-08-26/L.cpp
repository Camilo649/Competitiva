#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i, 0, n)

#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i, 0, n)

#define SZ(x) ((int) x.size())
#define ALL(x) sort(x.begin(), x.end())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n1;int m1;
    int n2;int m2;
    cin>>n1>>m1;
    cin>>n2>>m2;

    if(n1+n2 > m1+m2){cout<<"A"<<nl}
    else if(n1+n2 < m1+m2){cout<<"P"<<nl;
    }
    else cout<<"D"<<nl;

    
    return 0;
}