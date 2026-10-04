#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)

#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin, x.end()
#define pb push_back
#define fst first
#define snd second 
#define nl '\n'

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

using namespace std;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll A; cin >> A;
    ll B; cin >> B;

    ll m = gcd(A, B);
    A /= m;
    B /= m;

    ll b = 1;
    for (ll d=2; d*d*d <= B; d++){
        if (B % d == 0){
            b *= d;
            while (B % d == 0) B /= d;
        }
    }

    if(ceil(sqrtl(B))-sqrtl(B) == 0) b *= sqrtl(B);
    else b *= B;

    if (b > 1)
        cout << b << nl;
    
    else
        cout << 2 << nl;

    return 0;
}