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

const int MAXN = 1e5 + 6;
const int INF = 1e9;

using namespace std;
 
bool solve(int k, string &field)
{
    int last_star = -INF;
    int n = field.size();
    forn(i,n)
    {
        int starIdx = -1;
        int packmanIdx = -1;
        while (i<n && field[i] != 'P')
        {
            if(field[i] == '*' && starIdx == -1 && i > last_star) starIdx = i;
            i++;
        }
        if(i == n) break;
        packmanIdx = i;

        if(starIdx == -1)
        {
            // me muevo a la derecha todo lo que peuda
            last_star = min(packmanIdx+k,n);
        }
        else
        {
            int go_left_first = INF;
            int go_right_first = INF;
            int starIdx2 = -1;
            while (i<n)
            {
                if(field[i] == '*' && i > last_star)
                {
                    if(k >= min(2*(packmanIdx - starIdx) + (i - packmanIdx), (packmanIdx - starIdx) + 2*(i - packmanIdx)))
                    {
                        go_left_first = min(go_left_first, 2*(packmanIdx - starIdx) + (i - packmanIdx));
                        go_right_first = min(go_right_first, (packmanIdx - starIdx) + 2*(i - packmanIdx));
                        starIdx2 = i;
                    }
                    else 
                    {
                        break;
                    }
                }
                i++;
            }

            if(min(go_left_first, go_right_first) <= k)
            {
                last_star = min(starIdx2,n);
            }
            else if((packmanIdx - starIdx) <= k)
            {
                // puede comer todo a izquierda
                last_star = packmanIdx;
            }
            else
            {
                break;
            }
            // else
            // {
            //     // me muevo a la izquierda todo lo que peuda
            // }
        }

        i = packmanIdx;
    }   

    int j = n;
    while (j>=0)
    {
        if(field[j] == '*')
        {
            break;
        }
        j--;
    }
    
    return j <= last_star;
 }

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    string field; cin >> field;
    
    int a = 0, b = 2*n + 1;
    int res = 1e9; 
    while (a<=b) {
        int k = (a+b)/2;
        if (solve(k, field)) {b = k-1; res = min(k,res);}
        else a = k+1;
    }

    cout << res << nl;
    
    return 0;
}