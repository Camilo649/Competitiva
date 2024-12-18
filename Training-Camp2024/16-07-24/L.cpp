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

const int MAXN = -1;

using namespace std;
 
int n,ax,ay,bx,by,cx,cy;

int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> n >> ax >> ay >> bx >> by >> cx >> cy; 
    /*
    int table[n][n];

    /*
    1 -> casillas donde llega la reina
    2 -> casilla de inicio del rey
    3 -> meta


   table[ax][ay] = 1;
   forn(i,n) {
        table[ax][i] = 1;
        table[i][ay] = 1;
    }
    
    for(int i = 0; (ax-i) > 0; i++)
    {
        for(int j = 0; (ay-j) > 0; j++) {
            table[ax-i][ay-j] = 1;
        }
    }
    */

   if ((ax-bx > 0) && (ay-by > 0) && (ax-cx > 0) && (ay-cy > 0))
   {
        cout << "YES" << nl;
        return 0;
   }
   else if ((ax-bx < 0) && (ay-by > 0) && (ax-cx < 0) && (ay-cy > 0))
   {
        cout << "YES" << nl;
        return 0;
   }
   else if ((ax-bx > 0) && (ay-by < 0) && (ax-cx > 0) && (ay-cy < 0))
   {
        cout << "YES" << nl;
        return 0;
   }
   else if ((ax-bx < 0) && (ay-by < 0) && (ax-cx < 0) && (ay-cy < 0))
   {
        cout << "YES" << nl;
        return 0;
   }
   else
   {
    cout << "NO" << nl;
   }
   
   
   
   
   

    return 0;
}