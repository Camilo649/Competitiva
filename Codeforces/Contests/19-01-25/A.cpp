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
 
int t;

int s1 (int a[])
{
    int a2 = a[0] + a[1];
    int f = 1;
    if (a2 + a[1] == a[2])
    {
        f++;/* code */
    }
    if (a2 + a[2] == a[3])
    {
        f++;/* code */
    }
    return f;
}

int s2 (int a[])
{
    int a2 = a[2] - a[1];
    int f = 1;
    if (a[1] + a[0] == a2)
    {
        f++;/* code */
    }
    if (a2 + a[2] == a[3])
    {
        f++;/* code */
    }
    return f;
}

int s3 (int a[])
{
    int a2 = a[3] - a[2];
    int f = 1;
    if (a[0] + a[1] == a2)
    {
        f++;/* code */
    }
    if (a2 + a[1] == a[2])
    {
        f++;/* code */
    }
    return f;
}

int main()
{
    #ifdef MILF
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--)
    {
        int a[4];
        forn(i,4)
        {
            cin>>a[i];
        }

        cout << max(max(s1(a),s2(a)),s3(a)) << nl;
    }
        

    return 0;
}