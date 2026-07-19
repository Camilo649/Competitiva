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
        int n,k,p,m; cin >> n >> k >> p >> m; p--;
        priority_queue <pair<int,int>> hand;
        queue <pair<int,int>> deck;
        forn(i,k)
        {
            int a; cin >> a;
            if(i == p) hand.push({1,-a});
            else hand.push({0,-a});
        }
        forr(i,k,n)
        {
            int a; cin >> a;
            if(i == p) deck.push({1,-a});
            else deck.push({0,-a});
        }

        ll ans = 0;
        while (m >= -hand.top().snd)
        {
            if(hand.top().fst == 1) ans++;
            m -= -hand.top().snd;
            deck.push(hand.top());
            hand.pop();
            hand.push(deck.front());
            deck.pop();
        }

        cout << ans << nl;
    }
    
    return 0;
}