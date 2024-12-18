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
#define CAM
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;
 
int t;

int main()
{
    #ifdef CAM
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> t;
    while (t--)
    {
        int n;
        string f1,f2;
        cin >> n >> f1 >> f2;

        ll count = 0;
        int i = 0;
        while ((i<n) && (f1[i] == 'x') && (f2[i] == 'x')) i++;
        if (i==0) i = 1;    
        for(; i<n-1; ++i){
            if ((f1[i] == '.') && (f2[i] == '.')) {
                if ((f2[i+1] == 'x') && (f2[i-1] == 'x') && (f1[i+1] == '.') && (f1[i-1] == '.'))
                {
                    count++;
                }
                if ((f1[i+1] == 'x') && (f1[i-1] == 'x') && (f2[i+1] == '.') && (f2[i-1] == '.'))
                {
                    count++;
                }
            }
            else if ((f1[i] == 'x') && (f2[i] == '.'))
            {
                if ((f2[i+1] == '.') && (f2[i-1] == 'x') && (f1[i+1] == '.') && (f1[i-1] == '.'))
                {
                    count++;
                }
                if ((f2[i+1] == 'x') && (f2[i-1] == '.') && (f1[i+1] == '.') && (f1[i-1] == '.'))
                {
                    count++;
                }  
            }
            else if ((f1[i] == '.') && (f2[i] == 'x')) {
                if ((f1[i+1] == '.') && (f1[i-1] == 'x') && (f2[i+1] == '.') && (f2[i-1] == '.'))
                {
                    count++;
                }
                if ((f1[i+1] == 'x') && (f1[i-1] == '.') && (f2[i+1] == '.') && (f2[i-1] == '.'))
                {
                    count++;
                }
            }
        }
        cout << count << nl;
    }
    

    return 0;
}