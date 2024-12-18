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
        string s;
        cin >> n >> s;
        int dercount = 1;
        s[0] = '(';
        for(int i = 1; i<n-1; i++){
            if (i%2 == 0)
            {
                if((dercount <= 1) && (s[i+1] == ')') && (i!=n-2)){
                    s[i] = '(';
                    ++dercount;
                }
                else
                {
                    if (dercount > 0) {
                        s[i] = ')';
                        dercount--;
                    }
                    else {
                        s[i] = '(';
                        ++dercount;
                    }
                }
            }
            else
            {
                if(s[i] == '(') dercount++;
                else dercount--;
            }
        }

        //forn(i,n){
        //   cout << s[i];
        //}
        //cout << nl;

        dercount = 0;
        ll cost = 0;
        ll offset = 0;
        int cuandoAplicarOfsset = 0;
        forn(i,n){
            if(s[i] == '(') dercount++;
            else
            {
                ll seguidos = 0;
                while ((dercount>0)&&(s[i]==')'))
                {
                    if(cuandoAplicarOfsset >= (dercount - seguidos)) {
                        cost += 1 + offset;
                        cuandoAplicarOfsset--;
                    }
                    else
                    {
                        cost += 1 + 2*seguidos;
                    }
                    offset += 2;
                    seguidos++;
                    dercount--;
                    i++;
                }
                if(dercount == 0) offset = 0;
                else cuandoAplicarOfsset = dercount;
                ++dercount;
            }
        }
        cout << cost << nl;
    }
    

    return 0;
}