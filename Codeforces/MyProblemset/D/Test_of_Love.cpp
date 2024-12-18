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
 
int t,n,m,k;
string s;

int main()
{
    #ifdef CAM
        freopen("input.txt", "r", stdin);
    #endif

    cin >> t;

    while (t--)
    {
        cin >> n >> m >> k >> s;

        int i = (-1);
        bool flag = false;
        while (i<n)
        {
            int cota = i+m;
            if(cota >= n) break;
            for(int j = i+1; j<=cota; ++j){
                i = j;
                if (s[j] == 'L') break;
            }
            if (s[i] != 'L'){
                if (s[i] == 'C'){
                    flag = true;
                    break;
                }
                else
                {
                    while ((i<n) && (s[i] == 'W'))
                    {
                        --k;
                        ++i;
                    }
                    if((k<0) || s[i] == 'C') {
                        flag = true;
                        break;
                    }
                }
            }
            while ((i<n) && (s[i+1] == 'L')) ++i; 
        }
        if(flag) {cout << "NO" << nl;} 
        else cout << "YES" << nl;
    }
    

    return 0;
}