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
        set<int> A,B;
        int mxa, mxb;
        forn(i,n)
        {
            char c; cin >> c;
            if(c == 'A')
            {
                A.insert(i+1);
                mxa = i+1;
            }
            else 
            {
                B.insert(i+1);
                mxb = i+1;
            }
        }
        mxa == n ? mxa-- : mxa = mxa;
        mxb == n ? mxb-- : mxb = mxb;

        if(A.count(1) == 1 && A.count(n) == 1) cout << "Alice";
        else if(B.count(1) == 1 && B.count(n) == 1) cout << "Bob";
        else if(A.count(1) == 1 && B.count(n) == 1)
        {
            if(B.size() == 1) cout << "Alice";
            else cout << "Bob";
        }
        else
        {
            if(n == 2) cout << "Bob";
            else
            {
                if(mxa > mxb) cout << "Alice";
                else cout << "Bob";
            }
        }

        cout << nl;
    }
    
    return 0;
}