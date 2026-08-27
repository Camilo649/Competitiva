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

    int n; int m; cin>>n>>m;

    char arr[n][m];


    forn(i,n){
        forn(j,m){
            cin>>arr[i][j];
        }
    }

    int T = 0;
    int A = 0;
    int P = 0;
    dforn(j,m){
        forn(i,n){
            if (arr[i][j] == '#'){

                if (arr[i+1][j] != '#'){
                    // handle T
                    T += 1;
                    arr[i][j] = 'T';
                    arr[i][j-1] = 'T';
                    arr[i][j-2] = 'T';

                    arr[i+1][j-1] = 'T';
                    arr[i+2][j-1] = 'T';
                    arr[i+3][j-1] = 'T';
                    arr[i+4][j-1] = 'T';
                }
                else if (arr[i+3][j] != '#'){
                    // handle P
                    P += 1;
                    arr[i][j] = 'P';
                    arr[i][j-1] = 'P';
                    arr[i][j-2] = 'P';

                    arr[i+1][j] = 'P';
                    arr[i+1][j-2] = 'P';

                    arr[i+2][j] = 'P';
                    arr[i+2][j-1] = 'P';
                    arr[i+2][j-2] = 'P';

                    arr[i+3][j-2] = 'P';
                    arr[i+4][j-2] = 'P';
                }
                else {
                    // handle A
                    A += 1;
                    arr[i][j] = 'A';
                    arr[i][j-1] = 'A';
                    arr[i][j-2] = 'A';

                    arr[i+1][j] = 'A';
                    arr[i+1][j-2] = 'A';

                    arr[i+2][j] = 'A';
                    arr[i+2][j-1] = 'A';
                    arr[i+2][j-2] = 'A';

                    arr[i+3][j-2] = 'A';
                    arr[i+4][j-2] = 'A';

                    arr[i+3][j] = 'A';
                    arr[i+4][j] = 'A';
                }

            }
        }
    }

    cout << T << ' ' << A << ' '  << P << nl; 
    
    return 0;
}