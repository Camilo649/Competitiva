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
 
int solve (vector<int> vec1, vector<int> vec2) {
    int dif1 = 0;
    int dif2 = 0;
    forn(i,26) {
        if(vec1[i] >= vec2[i]) dif1 += (vec1[i] - vec2[i]);
        else dif2 += -1*(vec1[i] - vec2[i]);
    }
    return max(dif1,dif2);
}

unsigned short t;
int n,q,l,r;
string s1,s2;

int main()
{
    #ifdef CAM
        freopen("../input.txt", "r", stdin);
    #endif

    cin >> t;
    while (t--)
    {
        cin >> n >> q >> s1 >> s2;
        vector<vector<int>> v1(n, vector<int>(26, 0));
        vector<vector<int>> v2(n, vector<int>(26, 0));
        v1[0][s1[0]-'a'] = 1;
        v2[0][s2[0]-'a'] = 1;
        for(int i = 1; i<n; ++i){
            v1[i] = v1[i-1];
            v2[i] = v2[i-1];

            v1[i][s1[i] - 'a']++;
            v2[i][s2[i] - 'a']++;
        }
        while (q--)
        {
            cin >> l >> r;

            vector<int> vec1 = v1[r-1];
            vector<int> vec2 = v2[r-1];

            if(l!=1) {
                forn(i,26){
                    vec1[i] -= v1[l-2][i];
                    vec2[i] -= v2[l-2][i];
                }
            }

            //imprime todas las claves y valores de map1
            //cout << "vec1: " << nl;
            //forn(i,26){
            //    cout << vec1[i] << nl;
            //}
            //imprime todas las claves y valores de map2
            //cout << "vec2: " << nl;
            //forn(i,26){
            //    cout << vec2[i] << nl;
            //}

            int ans = solve(vec1,vec2);
            cout << ans << nl;
        }
        
    }
    

    return 0;
}