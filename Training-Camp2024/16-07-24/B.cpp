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
 
int n,c;

int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> n >> c;

    int A[n];

    forn(i,n){
        cin >> A[i];
    }

    int k = 0;
    int sum = 0;
    int div = n/c;
    while (k<n)
    {
        if (A[k] <= div)
        {
            while ((k<n) && (A[k] <= div))
            {
                if (A[k] == div)
                {
                    sum += div;
                }
                ++k;
            }
        }
        else
        {
            while ((k<n) && A[k] > div)
            {
                sum += A[k];
                ++k;
            }
        }
    }

    cout << sum << nl;
    return 0;
}