#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define SZ(x) ((int) x.size())
#define ALL(x) sort(x.begin(), x.end())
#define pb push_back
#define fst first
#define snd second
#define nl '\n';
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;

int main()
{
    #ifdef ONLINE_JUDGE
    freopen("lucky.in","r",stdin);     
    freopen("lucky.out","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int r; int c;
    cin >> r>>c;

    int grilla[r][c];
    forn(i,r){
        forn(j,c){
            int num;
            cin>>num;
            grilla[i][j] = num;
        }
    }

    int res=0;
    forn(i,r){ // recorro las filas
        forn(j,c){ //recorro las columnas
            int u = i+1;
            while(u <= r){
                if(u==r){
                    res++;
                    break;
                }
                if(grilla[u][j] >= grilla[i][j]) break;
                u++;
            }
            u = i-1;
            while(u >= -1){
                if(u==-1){
                    res++;
                    break;
                }
                if(grilla[u][j] >= grilla[i][j]) break;
                u--;
            }
            int t = j+1;
            while(t <= c){
                if(t==c){
                    res++;
                    break;
                }
                if(grilla[i][t] >= grilla[i][j]) break;
                t++;
            }
            t = j-1;
            while(t >= -1){
                if(t==-1){
                    res++;
                    break;
                }
                if(grilla[i][t] >= grilla[i][j]) break;
                t--;
            }
        }
    }

    cout<<res<<nl;
    return 0;
}