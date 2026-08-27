#include <bits/stdc++.h>

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
#define GE
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 3e5;
const int MAXM = 8;
const int MAXA = 1e9;

using namespace std;
 
int n,m;
int a[MAXN][MAXM];

int toMask(const int arr[], int k) {
    int mask = 0;
    forn(j, m) if (arr[j] >= k) mask |= (1 << j);
    return mask;
}

pair<int,int> solve(int k)
{
    unordered_map<int,int> um;
    forn(i,n) 
    {
        um[toMask(a[i], k)] = i;
    }
    for (auto [key1, value1] : um) 
    {
        for (auto [key2, value2] : um)  {
            if((key1 | key2) == ((1<<m) - 1))
            {
                return {value1, value2};
            }
        }
    }

    return {-1, -1};
}

int main()
{
    #ifdef GE
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    forn(i,n)
    {
        forn(j,m)
        {
            cin >> a[i][j];
        }
    }

    int best = 0;
    int l = 0 , r = MAXA;
    pair<int,int> res;
    while (l <= r) {
        int k = (l+r)/2;
        pair<int,int> aux = solve(k);
        //cout << aux.fst+1 << " " << aux.snd+1 << nl;
        if (aux.fst != -1 && aux.snd != -1) 
        {  
            if(k > best) 
            {
                best = k;
                res = aux;
            }

            l = k+1;
        }
        else r = k-1;
    }   

    cout << res.fst+1 << " " << res.snd+1 << nl;
    
    return 0;
}