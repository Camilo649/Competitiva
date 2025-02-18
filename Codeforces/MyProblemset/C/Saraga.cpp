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

const int MAXN = 200000;

using namespace std;

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s,t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();
    unordered_map<char,int> pos;
    char letter = 'a';
    while (letter <= 'z')
    {
        pos[letter] = t.rfind(letter);

        if (pos[letter] == m-1)
        {
            int j = m-2;
            while (j >= 0 && (char)t[j] != letter)
            {
                j--;
            }
            j>=0 ? pos[letter] = j : pos[letter] = string::npos;
        }

        letter++;
    }
     
    int i = 0;
    bool flag = false;
    int ls = 0, rs = MAXN, lt = -MAXN, rt = m-1;
    while (i<n-1)
    {
        if (pos[(char)s[i+1]] != string::npos)
        {
            if (i-ls + rt-pos[(char)s[i+1]] < rs-ls + rt-lt)
            {
                rs = i; lt = pos[(char)s[i+1]];
            }
            flag = true;
        }

        i++;
    }
    
    if (flag)
    {
        cout << s.substr(ls,rs-ls+1)+t.substr(lt,rt-lt+1) << nl;
    }
    else
    {
        cout << -1 << nl;
    }
    
    return 0;
}