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

const int MAXN = -1;

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
        int p[n];
        forn(i,n)
        {
            cin >> p[i];
        }

        int i = 0; int j = n-1;
        int last;
        if (p[i] > p[j])
        {
            cout << 'L';
            last = p[i];
            i++;
        }
        else
        {
            cout << 'R';
            last = p[j];
            j--;
        }
        
        bool flag = true;
        while(i<=j)
        {
            if (flag)
            {
                if (last < p[i])
                {
                    cout << 'L';
                    last = p[i];
                    i++;
                    flag = false;
                }
                else if(last < p[j]) {
                    last = p[j];
                    cout << 'R';
                    j--;
                    flag = false;
                }
                else
                {
                    if (p[i] < p[j])
                    {
                        cout << 'L';
                        last = p[i];
                        i++;
                    }
                    else
                    {
                        cout << 'R';
                        last = p[j];
                        j--;
                    }
                }
            }
            else
            {
                if (last > p[i])
                {
                    cout << 'L';
                    last = p[i];
                    i++;
                    flag = true;
                }
                else if(last > p[j]) {
                    last = p[j];
                    cout << 'R';
                    j--;
                    flag = true;
                }
                else
                {
                    if (p[i] > p[j])
                    {
                        cout << 'L';
                        last = p[i];
                        i++;
                    }
                    else
                    {
                        cout << 'R';
                        last = p[j];
                        j--;
                    }
                }
            }
        }

        cout << nl;
    }
    
    return 0;
}