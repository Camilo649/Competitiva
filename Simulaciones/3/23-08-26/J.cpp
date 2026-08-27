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

int tests;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,X; cin >> n >> X;
    int count = 0;
    vector<int> mn, mx;
    forn(i,n)
    {
        int b; cin >> b;
        if(2*b == X) count++;
        if(2*b <  X) mn.pb(b);
        if(2*b >  X) mx.pb(b);
    }

    if(count > (n+1)/2) {cout << '*' << nl; return 0;}

    sort(mn.begin(), mn.end());
    sort(mx.begin(), mx.end());
    deque<int> res;
    if(count > 0)
    {
        res.push_back(X/2);
        count--;
        while (count--)
        {
            if(!mn.empty()) {res.push_back(mn.back()); mn.pop_back();}
            else            {res.push_back(mx.back()); mx.pop_back();}
            res.push_back(X/2);
        }
        
        while (!mn.empty()) {res.push_front(mn.back()); mn.pop_back();}
        while (!mx.empty()) {res.push_back(mx.back()); mx.pop_back();}
    }
    else
    {
        if(!mn.empty() && !mx.empty() && mn[0] == mn.back() && mx[0] == mx.back() && mn[0] + mx[0] == X) 
            {cout << '*' << nl; return 0;}

        if(!mn.empty() && !mx.empty())
        {
            if(mn[0] + mx.back() == X)
            {
                if(mn.back() + mx.back() == X)
                {
                    swap(mx[0], mx[SZ(mx)-1]);
                }
                else
                {
                    swap(mn[0], mn[SZ(mn)-1]);
                }
            }
        }

        while (!mn.empty()) {res.push_back(mn.back()); mn.pop_back();}
        while (!mx.empty()) {res.push_back(mx.back()); mx.pop_back();}
    }

    while (!res.empty())
    {
        cout << res.front() << " ";
        res.pop_front();
    }
    

}