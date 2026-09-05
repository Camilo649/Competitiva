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

const int MAXN = 2e5 + 5;

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
    
    cin >> tests;
    
    while (tests--)
    {
        int n; cin >> n;
        int a[n]; forn(i,n) cin >> a[i];

        bitset<MAXN> forbidden;
        int i = 0;
        while (i<n)
        {
            while (i<n && a[i] == -1) i++;
            //print(i); print(a[i]); print(max(i-a[i]+1, 0)); print(min(i+a[i], n));
            forr(j,max(i-a[i]+1, 0),min(i+a[i], n)) forbidden[j]= 1;
            i++;
        }

        // forn(i,n) cout << forbidden[i] << " ";
        // cout << nl;

        int ans[n] = {};
        int l = 0, r = n-1;
        bool ok = true;
        while (l<=r)
        {
            while (l<r && a[l] == -1) l++;
            if(a[l] == -1) break;
            bool valid = false;
            int pos = l-a[l];
            if(pos >= 0 && !forbidden[pos])
            {
                if(a[pos] <= 0) {a[pos] = 0; ans[pos] = 1; valid = true;}
            }
            pos = a[l]+l;
            if(pos < n && !valid && !forbidden[pos])
            {
                if(a[pos] <= 0) {a[pos] = 0; ans[pos] = 1; valid = true;}
            }
            if(!valid) {ok = false; break;}
            l++;

            while(l<r && a[r] == -1) r--;
            if(a[r] == -1) break;
            valid = false;
            pos = a[r]+r;
            if(pos < n && !forbidden[pos])
            {
                if(a[pos] <= 0) {a[pos] = 0; ans[pos] = 1; valid = true;}
            }
            pos = r-a[r];
            if(pos >= 0 && !valid && !forbidden[pos])
            {
                if(a[pos] <= 0) {a[pos] = 0; ans[pos] = 1; valid = true;}
            }
            if(!valid) {ok = false; break;}
            r--;
        }


        vector<int> zero_pos;
        forn(i,n)
        {
            if(a[i] == 0) zero_pos.pb(i);
        }

        int idx = 1;
        while (idx < SZ(zero_pos) && ok)
        {
            int l = zero_pos[idx-1]+1;
            int r = zero_pos[idx];
            int diff = r-l;
            int next = 1;
            forr(i,l,l+diff/2)
            {
                if(a[i] == -1) a[i] = next;
                if(a[i] != next){ok = false; break;}
                next++;
            }
            next = 1;
            dforr(i,l+diff/2,r)
            {
                if(a[i] == -1) a[i] = next;
                if(a[i] != next){ok = false; break;}
                next++;
            }

            idx++;
        }

        if(SZ(zero_pos) >= 1)
        {
            int next = 1;
            dforn(i,zero_pos[0])
            {
                if(a[i] == -1) a[i] = next;
                if(a[i] != next){ok = false; break;}
                next++;
            }

            next = 1;
            forr(i,zero_pos.back()+1,n)
            {
                if(a[i] == -1) a[i] = next;
                if(a[i] != next){ok = false; break;}
                next++;
            }
        }

        if(!ok) {cout << -1 << nl; continue;}
        int count0 = 0; forn(i,n) if(ans[i] == 0) count0++;
        forn(i,n) cout << (count0 == n ? 1 : ans[i]);
        cout << nl;
        
    }
    
    return 0;
}