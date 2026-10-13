#include <bits/stdc++.h>

#define forr(i,a,b) for(int  i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)

#define dforr(i,a,b) for(int i = (int) b-1; i >= (int) a; --i)
#define dforn(i,n) dforr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

using u64 = uint64_t;

const ld PI = acosl(-1);

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

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    ld  D; cin >> D;

    vector<pair<pair<ld, ld>,pair<ld, ld>>> points(N);
    forn(i, N){
        cin >> points[i].fst.fst >> points[i].fst.snd >> points[i].snd.fst >> points[i].snd.snd;
        points[i].fst.fst /= D;
        points[i].fst.snd /= D;
        points[i].snd.fst /= D;
        points[i].snd.snd /= D;
    }

    vector<tuple<ld,int,int>> ranges;
    forn(i, N){
        ld x1 = points[i].fst.fst;
        ld y1 = points[i].fst.snd;
        ld x2 = points[i].snd.fst;
        ld y2 = points[i].snd.snd;

        ld dx = x2-x1;
        ld dy = y2-y1;
        ld nx = -dy/sqrtl(dx*dx + dy*dy);
        ld ny =  dx/sqrtl(dx*dx + dy*dy);
        ld r = x1*nx + y1*ny;

        if(abs(r)>=1) continue;

        ld r2 = sqrtl(1-r*r);
        ld p1x = r*nx + r2*(-ny);
        ld p1y = r*ny + r2*nx;
        ld p2x = r*nx - r2*(-ny);
        ld p2y = r*ny - r2*nx;
        ld a1 = atan2l(p1y,p1x);
        ld a2 = atan2l(p2y,p2x);
        if(a1<0) a1 += PI*2;
        if(a2<0) a2 += PI*2;

        //cout << a1/PI*2 << ' ' << a2/PI*2 << nl;

        if(a1>a2) swap(a1,a2); // a1 <= a2

        if(a1+PI < a2) swap(a1,a2); // ????

        if(a1 < a2)
        {
            ranges.pb({a1,1,i});
            ranges.pb({a2,-1,i});
        }
        else
        {
            ranges.pb({a1,1,i});
            ranges.pb({PI*2,-1,i});
            ranges.pb({0,1,i});
            ranges.pb({a2,-1,i});
        }
    }

    sort(ALL(ranges));

    // for(auto [v,b,i] : ranges)
    // {
    //     //if(i>=2) continue;
    //     print(v/(PI/2)); print(b); print(i);
    // }

    bool global_sol = false;
    int l = 0, r = N-1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        bool local_sol = false;
        int count = 0;
        bool start = false;

        //print(mid);

        for(auto [v,b,i] : ranges)
        {   
            if(i <= mid)
            {
                if(!start)
                {
                    if(v != 0) break;
                    start = true;
                }
                count += b;
                // print(count);
                // print(v);
                if(v == PI*2) {local_sol = true; break;}
                if(count == 0) break;
            }
        }

        //print(local_sol);

        if(local_sol) global_sol = true;
        if(local_sol) r = mid-1;
        else l = mid+1;
    }

    if(!global_sol) cout << '*';
    else cout << l+1;
    cout << nl;

    return 0;
}