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

const int MAXN = 1e3 + 2;

using namespace std;
 
int n,m;

int main()
{
    #ifdef MAT
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> n >> m;
    int A[n];
    memset(&A, 0, sizeof(int)*n);
    forn(i,m) {
        int l, r;
        cin >> l >> r;
        --l;--r;

        for (int j = l; j <= r; j++)
        {
            ++A[j];
        }
    }

    /*
    priority_queue<pair<int,int>> pq;
    forn(i,n) {
        pq.push(make_pair(A[i],i));
    }

    bitset <MAXN> res;
    int count = 1;
    while (!pq.empty())
    {
        pair<int,int> p = pq.top();
        res[p.second] = (count%2);
        count++;
        pq.pop();
    }
    
    */
    int count = 0;
    forn(i,n) {
        cout << count%2;
        ++count;
    }
    
    cout << nl;

    return 0;
}