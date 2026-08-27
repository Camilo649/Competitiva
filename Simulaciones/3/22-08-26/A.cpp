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
const int INF = 1e9+6;

using namespace std;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; int m;

    cin>>n>>m;

    int alf[n] = {};
    vector<int> emp;

    forn(i,n){
        cin>>alf[i];
    }
    forn(j,m){
        int num;
        cin>>num;
        if(SZ(emp) == 0 or emp[SZ(emp)-1] > num){
            emp.pb(num);
        }
    }
    
    ALL(emp);
    
    forn(j, n){
        int ans = INF;
        int nd = alf[j];
        while(ans>=emp[0]){
            auto div = upper_bound(emp.begin(),emp.end(),nd);
            div--;
            int d = *div;
            nd = nd%d;
            ans = nd;
        }
        cout<<ans<<" ";
    }

    return 0;
}


