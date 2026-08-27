#include <bits/stdc++.h>

#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)

#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
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

    int n; int q; cin>>n>>q;
    vector<ll> arr;

    forn(i,n){
        ll num;cin>>num;
        arr.pb(num);
    }

    int P2[n+1];P2[0] = 0;
    int IM[n+1];IM[0] = 0;
    int C1[n+1];C1[0] = 0;

    forr(j,1,n+1){
        ll bitprendidos = __builtin_popcountll(arr[j-1]);
        P2[j] = P2[j-1];
        IM[j] = IM[j-1];
        C1[j] = C1[j-1]; 
        if(arr[j-1] == 1){
            C1[j]++;
        }else{
            if(bitprendidos == 1){
                P2[j] += arr[j-1];
            }else if(arr[j-1]%2 == 1){
                IM[j] += arr[j-1];
            }
        }
    }

    forn(i,q){
        int L; int R; cin>>L>>R;

        int cant1 = C1[R]-C1[L-1];
        int puntajeA = 0;
        int puntajeB = 0;
        puntajeB = cant1/2;
        puntajeA = cant1 - puntajeB;

        puntajeA += P2[R]-P2[L-1];
        puntajeB += IM[R]-IM[L-1];

        if(puntajeA>puntajeB){cout<<"A"<<nl;}
        else
        {
            if(puntajeA<puntajeB)
            {cout<<"B"<<nl;
            }else{cout<<"E"<<nl}
        }

        
    }


    return 0;
}