#include <bits/stdc++.h>

// for's hacia adelante
#define forr(i, a, b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i, n) forr(i, 0, n)
// for's hacia atras
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i, n) dforr(i, 0, n)
// otros
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'
// redefiniciones
typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const int MAXN = -1;

using namespace std;

// Debugging
#ifdef GG
#define DBG 1
#define print(x) cerr << #x << " = " << x << endl
#else
#define DBG 0
#define print(x) cout << x << nl
#endif

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    if (DBG) os << "[";
    for (auto& x : v) os << x << (DBG ? ", " : " ");
    return DBG ? os << "]" : os;
}

template<typename S, typename T> ostream& operator<<(ostream& os, const pair<S, T>& p) {
    return os << (DBG ? "(" : "") << p.fst << (DBG ? ", " : " ") << p.snd << (DBG ? ")" : "");
}

int tests;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s; cin >> s;
    int n = SZ(s);
    int last = -1;
    bool more = false;
    set<char> Vocal; 
    Vocal.insert('A');
    Vocal.insert('E');
    Vocal.insert('I');
    Vocal.insert('O');
    Vocal.insert('U');
    forn(i,n-4)
    {
        if(Vocal.count(s[i]) && Vocal.count(s[i+4]) && s[i] == s[i+4] && 
            s[i+1] == 'G' && s[i+2] == 'A' && s[i+3] == 'S')
        {
            //print(i); print(last);
            if(last != -1 && last != i-4) more = true;
            last = i;
        }
    }

    if(last == -1) cout << "-";
    else if(more) cout << "+";
    else
    {
        string res;
        forn(i,last) res += s[i];
        forr(i,last+4,n) res += s[i];
        cout << res;
    }
    cout << nl;
    
    return 0;
}