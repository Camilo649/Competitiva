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
#define MILF
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 2e5 + 6;

using namespace std;
 
int tests;

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tests;

    while (tests--)
    {
        int n; cin >> n;
        string s0; cin >> s0;

        bitset<MAXN> b(s0);
        int count1 = b.count();
        int count0 = n-count1;
        queue<int> q0;
        forn(i,n)
        {
            if(s0[i] == '0')
            {
                q0.push(i+1);
            }
        }

        vector<int> ans;
        int step = 0;
        while (!q0.empty() && count0 != n)
        {
            ans.pb(q0.front());
            q0.pop();
            if(step%2 == 0)
            {
                count0 = count1 + 1;
                count1 = n-count0;
            }
            else
            {
                count1 = count0 + 1;
                count0 = n-count1;
            }
            step++;
        }

        if(count0 != n)
        {
            string s1 = s0;
            bitset<MAXN> b(s1);
            count1 = b.count();
            count0 = n-count1;
            queue<int> q1;
            forn(i,n)
            {
                if(s1[i] == '1')
                {
                    q1.push(i+1);
                }
            }

            ans.clear();
            step = 1;
            while (!q1.empty() && count0 != n)
            {
                ans.pb(q1.front());
                q1.pop();
                if(step%2 == 0)
                {
                    count0 = count1 + 1;
                    count1 = n-count0;
                }
                else
                {
                    count1 = count0 + 1;
                    count0 = n-count1;
                }
                step++;
            }
        }

        if(count0 == n)
        {
            cout << ans.size() << nl;
            forn(i,ans.size())
            {
                cout << ans[i] << " ";
            }
            cout << nl;
        }
        else
        {
            cout << -1 << nl;
        }
    }
    
    return 0;
}