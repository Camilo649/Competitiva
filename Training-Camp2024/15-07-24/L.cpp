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
 
int n;

int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> n;

    vector<int> A;
    int nc, pc;
    nc = 0; pc = 0;

    forn(i, n) {
        ld a;
        cin >> a;
        if (a<0)
        {   
            if (ceil(a/2) == a/2)
            {
                A.push_back(a/2);
            }
            else
            {
                nc++;
                if (nc%2 == 1)
                {
                    A.push_back(floor(a/2));
                }
                else
                {
                    A.push_back(ceil(a/2));
                }
            }
        }
        else
        {
            if (ceil(a/2) == a/2)
            {
                A.push_back(a/2);
            }
            else
            {
                pc++;
                if (pc%2 == 1)
                {
                    A.push_back(ceil(a/2));
                }
                else
                {
                    A.push_back(floor(a/2));
                }
            }
        }
    }

    forn(i,n) {
        cout << A[i] << nl;
    }

    return 0;
}