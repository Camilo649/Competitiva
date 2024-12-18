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
 
int solve (unordered_map<char,int> map1, unordered_map<char,int> map2) {
    int dif1 = 0;
    int dif2 = 0;
    for (auto e:map1) {
        if(map2.count(e.first) == 0) dif1 += map1[e.first];
        else if(map1[e.first] > map2[e.first]) dif1 += (map1[e.first] - map2[e.first]);
        else dif2 += -1*(map1[e.first] - map2[e.first]);
    }
    return max(dif1,dif2);
}

int t,n,q,l,r;
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
        while (q--)
        {
            cin >> l >> r;

            unordered_map<char,int> map1;
            unordered_map<char,int> map2;

            for(int i = l-1; i<r; ++i){
                if(map1.count(s1[i]) == 0) map1[s1[i]] = 1;
                else ++map1[s1[i]];
    
                if(map2.count(s2[i]) == 0) map2[s2[i]] = 1;
                else ++map2[s2[i]];
            }

            // imprime todas las claves y valores de map1
            //cout << "map1: " << nl;
            //for(auto e:map1){
            //    cout << e.first << " " << e.second << nl;
            //}
            // imprime todas las claves y valores de map2
            //cout << "map2: " << nl;
            //for(auto e:map2){
            //    cout << e.first << " " << e.second << nl;
            //}

            int ans = solve(map1,map2);
            cout << ans << nl;
        }
        
    }
    

    return 0;
}