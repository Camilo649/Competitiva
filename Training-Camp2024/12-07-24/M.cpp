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
int h;

int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> n >> h;

    vector<int> A;
    vector<int> B;

    forn(i, n) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    if (A[0] > h)
    {
        cout << 0 << nl;
        return 0;
    }
    

    bool cond = true;
    int k = 1;
    for (; k <= n; k++)
     {
        B.push_back(A[k-1]);
        sort(B.begin(), B.end());

        int auxh = h;
        
        for (int j = (k-1); j >= 0; j-=2)
        {
            auxh -= B[j];
        }
        if (auxh < 0)
        {
            cond = false;
            break;
        }
    }

    if ((cond == false) || (k > n)) k--;
    cout << k << nl;

    return 0;
}