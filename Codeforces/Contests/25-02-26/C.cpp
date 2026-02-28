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
typedef unsigned long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = 64;

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
        ll s,m; cin >> s >> m;

        int sb[64] = {}, mb[64] = {};
        ll aux = 0;
        vector<int> mindex;
        int sindex = -1;
        forn(i,64)
        {
            if(s & (1ull<<i)) 
            {
                sb[63-i] = 1;
                if(sindex == -1) sindex = 63-i;
            }
            if(m & (1ull<<i)) 
            {
                mb[63-i] = 1;
                mindex.pb(63-i);
            }
        }
        sort(mindex.begin(), mindex.end());

        bool flag = (sindex > mindex.back());
        ll n = 0;
        if(!flag)
        {
            int bit;
            forn(i,64)
            {
                int nums = 0;
                int diff = 1;

                auto it = lower_bound(mindex.begin(), mindex.end(), i);
                if (it != mindex.end()) {
                    bit = *it;
                }
                else
                {
                    break;
                }

                if(sb[i] == 1 && (aux & (1ull<<(63-i))) == 0)
                {
                    diff = abs(bit - i);
                    nums += 1ull<<diff;
                    aux += m*nums;
                    n += nums;
                    //cout << n << nl;

                    forr(j1,i+1,64)
                    {
                        if(sb[j1] == 0 && (aux & (1ull<<(63-j1))) == 1)
                        {
                            forr(j2,j1,min(j1+diff+1,64))
                            {
                                int pot = 1;
                                if(sb[j2] == 1 && (aux & (1ull<<(63-j2))) == 0)
                                {
                                    aux -= ((1ull<<(63-j2)))*nums/(2 * (1ull<<pot));
                                }
                                else
                                {
                                    aux -= ((1ull<<(63-j2)))*nums;
                                }
                                pot++;
                            }
                        }
                    }
                }
            }

            cout << n;
        }
        else cout << -1;

        cout << nl;
    }
    
    return 0;
}