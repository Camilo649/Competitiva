#include <bits/stdc++.h>

#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)

#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)

#define SZ(x) ((int) x.size())
#define pb push_back
#define fsr first
#define snd suseconds_t
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

    int n;int m;

    cin>>n>>m;
    int ar[n];
    
    forn(i,n){
        int num;
        cin>>num;
        ar[i] = num;
    }

    ll pre = 0;
    int cant = m;
    vector<ll> NA;

    sort(ar,ar+n);

    forn(i,n){
        while (pre+1 < ar[i] && cant>0){
            cant--;
            NA.pb(pre+1);
            pre += pre+1;
        }
        pre += ar[i];
    }

    while(cant>0){
        NA.pb(pre+1);
        cant--;
        pre += pre+1;

    }
    
    forn(i,SZ(NA)){
        cout<<NA[i]<<" ";
    }

   
    return 0;
}