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

bool check(string s, string t)
{
    if(t == s.substr(0,t.size())) return false;
    forn(i,t.size())
    {
        if(s[i] == ')' && t[i] == '(') return true;
        if(t[i] == ')' && s[i] == '(') return false;
    }

    return true;
}

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
        string s; cin >> s;
        
        // int open_brackets = 0;
        // int close_brackets = n/2;
        // int i = 0;
        // while(i<n && open_brackets < close_brackets)
        // {
        //     if(s[i] == '(') open_brackets++;
        //     else close_brackets--;
        //     i++;
        // }

        int first_close = -1;
        int last_open = -1;
        forn(i,n)
        {
            if(first_close == -1 && s[i] == ')') first_close = i;
            if(s[i] == '(') last_open = i;
        }

        string t;
        forn(i,n)
        {
            if(i == first_close || i == last_open) continue;
            t += s[i];
        }
        if(!check(s,t)) cout << -1;
        else cout << t.size();
        cout << nl;
    }
    
    return 0;
}