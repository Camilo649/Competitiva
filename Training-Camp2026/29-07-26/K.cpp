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
#define GG
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int tests;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,k; cin >> n >> k;
    int a[n]; forn(i,n) cin >> a[i];

    int i = 0;
    while (i<n && a[i] >= 0) i++;

    int changes = (i>=n ? 0 : 1);
    
    unordered_map<int,pair<bool,int>> range;
    forr(j,i+1,n)
    {
        if(a[j] >= 0)
        {
            int count = 0;
            int pos = j;
            while (j<n && a[j] >= 0)
            {
                count++;
                j++;
            }
            range[pos] = {j==n, count};
        }
    }
    
    priority_queue<pair<bool,int>> pq;
    bool flag = true;
    while (i<n)
    {
        k--;
        
        if(i>0 && a[i] >= 0 && a[i-1] < 0)
        {
            pq.push(range[i]);
        }

        if(k<0)
        {
            if(pq.empty())
            {
                flag = false;
                break;
            }
            pair<int,int> p = pq.top(); pq.pop();
            k += p.snd;
            //cout << p.fst << " " << p.snd << nl;
            changes++;
            if(!p.fst) changes++; 
        }

        i++;
    }

    if(flag)
    {
        cout << changes << nl;
    }
    else
    {
        cout << -1 << nl;
    }
    
    return 0;
}