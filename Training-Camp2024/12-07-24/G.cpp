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

const ll MAXN = 1e6 + 100;

using namespace std;
 
int n;
int mz[MAXN][10];

bool menorQue(int A[10], int B[10]) {
    if (A[0] < B[0])
    {
        return true;
    }
    else if (A[0] > B[0])
    {
        return false;
    }
    else {
        for (int i = 9; i > 0; i--)
        {
            if(A[i] < B[i]) return true;
            else if (A[i] > B[i]) return false;
        }
        return true;
    } 
}

int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif
    
    cin >> n;
    int N[9];
    forn(i, 9) {
        cin >> N[i];
    }
    memset(mz, -1, sizeof(mz));

    int i = 0;
    mz[0][0] = 0;
    while (i <= n)
    {
        for(int j = 1; j < 10; ++j){
            (mz[i+N[j-1]][0] == -1) ? (mz[i+N[j-1]][j] = 1) : ++mz[i+N[j-1]][j];
            (mz[i+N[j-1]][j] == -1) ? (mz[i+N[j-1]][j] = 1) : ++mz[i+N[j-1]][j];
        }
        ++i;
        while (mz[i][0] == -1)
        {
            ++i;
        } 
    }

    int j = 0;
    int k = 1;
    while (j < MAXN)    
    {
        if (!menorQue(mz[j],mz[k]))
        {
            break;
        }
        
        while ((mz[j][0] == -1) && (j != MAXN))
        {
            ++j;
        }

        
        k = j+1;
    }
    
    if ((j == MAXN) || (mz[j][0] <= 0))
    {
        cout << -1 << nl;
        return 0;
    }
    
    dforn(i1, mz[j][0]) {
        for (int i2 = 1; i2 < mz[j][i1]; i2++)
        {
            cout << mz[j][i2] << ' ';
        }
    }

    cout << nl;
    return 0;
}