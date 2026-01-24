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

const int MAXN = 2e5+6;

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
        int n,m,k; cin >> n >> m >> k;
        int a[n]; forn(i,n) cin >> a[i];
        int b[m+2]; forn(j,m) cin >> b[j+1];
        b[0] = -1e9-6, b[m+1] = 1e9+6;
        sort(a, a+n);
        sort(b, b+m+2);
        string s; cin >> s;

        vector<pair<int,int>> death_pos_left(n);
        vector<pair<int,int>> death_pos_right(n);
        int l = 0, r = 1;
        forn(i,n)
        {
            while (a[i]>b[r])
            {
                l++; r++;
            }
            death_pos_left[i] = {abs(b[l]-a[i]),i};
            death_pos_right[i] = {b[r]-a[i],i};
        }
        sort(death_pos_left.rbegin(), death_pos_left.rend());
        sort(death_pos_right.rbegin(), death_pos_right.rend());

        int cuando_mueren[n];
        forn(i,n) cuando_mueren[i] = MAXN;

        int step = 0;
        //bitset<MAXN> alive;
        //alive.set();
        forn(i,k)
        {
            int curr_pos = death_pos_left.back().fst;

            if(s[i] == 'L')
            {
                step++;
            }
            else
            {
                step--;
            }
            
            while(!death_pos_left.empty() && curr_pos == step)
            {
                cuando_mueren[death_pos_left.back().snd] = i;
                death_pos_left.pop_back();
                curr_pos = death_pos_left.back().fst;
            }
        }

        step = 0;
        forn(i,k)
        {
            int curr_pos = death_pos_right.back().fst;

            if(s[i] == 'R')
            {
                step++;
            }
            else
            {
                step--;
            }
            
            while(!death_pos_right.empty() && curr_pos == step)
            {
                cuando_mueren[death_pos_right.back().snd] = min(i,cuando_mueren[death_pos_right.back().snd]);
                death_pos_right.pop_back();
                curr_pos = death_pos_right.back().fst;
            }
        }

        int deaths[k] = {};
        forn(i,n)
        {
            if(cuando_mueren[i] != MAXN) deaths[cuando_mueren[i]]++;
        }

        int total_deaths = 0;
        forn(i,k)
        {
            total_deaths += deaths[i];
            cout << n-total_deaths << " ";
        }
        
        cout << nl;
    }
    
    return 0;
}