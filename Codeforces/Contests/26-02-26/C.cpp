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

const int MAXN = 1e6 + 6;

using namespace std;
 
int tests;

bool comp(const vector<int>& a, const vector<int>& b) {
    return lexicographical_compare(
        a.begin(), a.end(),
        b.begin(), b.end()
    );
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
        vector<vector<int>> blog;
        set<int> nums;
        forn(i,n)
        {
            vector<int> post;
            int l; cin >> l;
            forn(j,l)
            {
                int a; cin >> a; post.pb(a); nums.insert(a);
            }
            blog.pb(post);
        }

        bitset<MAXN> added;
        vector<int> Q;
        while (Q.size() != nums.size())
        {
            vector<vector<int>> aux;
            forn(i,n)
            {
                set<int> s; 
                vector<int> v;
                dforn(j,blog[i].size()) 
                { 
                    if(s.count(blog[i][j]) == 0 && added[blog[i][j]] == 0) 
                    { 
                        v.pb(blog[i][j]);
                        s.insert(blog[i][j]); 
                    } 
                }
                if(!v.empty()) aux.pb(v);
            }

            sort(aux.begin(), aux.end(), comp);

            forn(i,aux[0].size())
            {
                Q.pb(aux[0][i]);
                added[aux[0][i]] = 1;
            }
        }

        forn(i,Q.size())
        {
            cout << Q[i] << " ";
        }
        cout << nl;
    }
    
    return 0;
}