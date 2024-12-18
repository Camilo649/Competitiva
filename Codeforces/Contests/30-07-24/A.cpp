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
        string s;
        cin >> s;

        char res[s.size() + 1];
        res[0] = s[0];
        int j = 0;
        for (int i = 0; i<s.size(); ++i){
            res[j] = s[i];
            if((s[i] == s[i+1]) && (i == j) && (i<s.size())) {
                ++j;
                res[j] = (s[i] != 'z') ? 'z' : 'a';
            }
            ++j;
        }
        if(j==s.size()) res[s.size()] = (s[s.size()-1] != 'z') ? 'z' : 'a';

        forn(i,s.size()+1){
            cout << res[i];
        }
        cout << nl;
    }
    

    return 0;
}