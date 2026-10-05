#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
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

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k,e; cin >> n >> k >> e;
    int a = e;
    int b = k;
    int c = n - (e+k);

    // forn(a,6)
    // {
    //     forr(b,1,6)
    //     {
    //         forn(c,6)
    //         {
                
    //         }
    //     }
    // }

    //cout << a << " " << b << " " << c << nl;

    if(a!=b && b!=c && a!=c) 
    {
        //cout << "jello" << nl;
        cout << 0;
    }
    else if(a==b && b==c && a==c) {
        //cout << "jello" << nl;
        if(a==1) cout << 2;
        else if (a == 2 || a == 3) cout << 3;
        else if(a == 4) cout << 2;
        else cout << 0;
    }
    else if(a==c)
    {
        //cout << "jello" << nl;
        if(b==1)
        {
            if(a==2) cout << 2;
            else if(a==3 || a==4) cout << 1;
            else cout << 0;
        }
        else if(b==2)
        {
            if(a==1) cout << 1;
            else if(a==3) cout << 2;
            else cout << 0;
        }
        else if(b==3)
        {
            if(a==1 || a==2 || a==4) cout << 1;
            else cout << 0;
        }
        else if(b==4)
        {
            if(a==1 || a==2) cout << 1;
            else cout << 0;
        }
        else if(b>4)
        {
            if(a==1 || a==2) cout << 1;
            else cout << 0;
        }
    }
    else
    {
        //cout << "jello" << nl;
        if(b==c) swap(a,c); // para asumir a==b   
        //cout << a << " " << b << " " << c << nl;  
        if(c>a)
        {
            if(a==1 || a==2) cout << 1;
            else cout << 0;
        }
        else if(c==0)
        {
            if(a==1 || a==2) cout << 1;
            else cout << 0;
        }
        else if(c==1)
        {
            if(a==2) cout << 2;
            else if(a==3 || a==4) cout << 1;
            else cout << 0;
        }
        else if(c==2){
            if(a==3) cout << 2;
            else cout << 0;
        }
        else if(c==3)
        {
            if(a==4) cout << 1;
            else cout << 0;
        }
        else cout << 0;
    }
    cout << nl;

    return 0;
}