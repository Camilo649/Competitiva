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

using namespace std;

int maxd(ll N, ll b){
    int d = 0;
    ll k = 1;
    while (k*b <= N){
        k *= b;
        d++;
    }
    return d;
}

ll myPow(int b, int d){
    ll k = 1;
    forn(i, d){
        k *= b;
    }
    return k;
}

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N; cin >> N;
    
    bool exists = false;
    
    for (ll b=2; b*b < N; b++){
        int d1 = 0;
        int d2 = maxd(N, b);
        ll p1 = 1;
        ll p2 = myPow(b, d2);
        bool poli = true;
        //cout << b << ' '<< d1 << ' '<< d2 << ' '<< p1 << ' '<< p2 << ' '<< nl;
        while (d1 < d2){
            if (((N/p1)%b) != ((N/p2)%b)){
                poli = false;
                //cout << 'f' << nl;
                break;
            }

            d1++;
            d2--;
            p1 *= b;
            p2 /= b;
        }
        if (poli){
            exists = true;
            cout << b << ' ';
        }
    }
    
    // k*b + k == N , k<b
    // k*(b + 1) == N
    dforr(k, 1, 1000001){           
        if (N % k == 0){
            ll b = (N / k) - 1;
            if (k < b){
                exists = true;
                cout << b << ' ';
            } 
        }
    }

    if (!exists){
        cout << '*' << nl;
    }
    else {
        cout << nl;
    }
    /*
    forr(b, 2, N+1){

        ll k = 1;
        cout << b << ": ";
        while (k <= N){
            cout << (N / k) % b << ' ';
            k *= b;
        }
        cout << nl;

    }
    */


    return 0;
}