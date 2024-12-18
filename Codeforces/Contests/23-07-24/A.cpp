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
#define CAM
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int t,n,k;

int main()
{
    #ifdef CAM
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        int counter = 0;
        if (k != 0)
        {
            k -= n;
            ++counter;

            int dcounter = 0;
            --n;
            while (k>0)
            {
                if (dcounter == 2)
                {
                    --n;
                    dcounter = 0;
                }
                k -= n;
                ++counter;
                ++dcounter;
            }
        }
        
        
        
        cout << counter << nl;
    }
    

    return 0;
}