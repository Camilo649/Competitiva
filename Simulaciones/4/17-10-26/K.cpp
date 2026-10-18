#include <bits/stdc++.h>

#define forr(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define forn(i,n) forr(i,0,n)

#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define nl '\n'

typedef long long ll;
typedef long double ld;

using namespace std;

int main()
{
    #ifdef GG
        freopen("../input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k; cin >> k;
    string s; cin >> s;
    int n = SZ(s);

    string output = s;


    if (k == 2){
        int s0 = 0;
        int s1 = 0;
        forn(i, n){
            if ((s[i]-'0') == i % 2){
                s0++;
            }
            else {
                s1++;
            }
        }
        if (s0 < s1){
            cout << s0 << ' ';
            forn (i, n){
                output[i] = '0' + (i+1) % 2;
            }
        }
        else {
            cout << s1 << ' ';
            forn (i, n){
                output[i] = '0' + i % 2;
            }
        }
        cout << output << nl;
    }
    else {
        int i0 = 0;
        int ans = 0;
        forn(i, n+1){
            if (i == n || s[i] != s[i0]){
                ans += (i-i0) / k;
                if ((i-i0)%k != 0){
                    forn(j, (i-i0) / k){
                        output[i0+k*j+(k-1)] = '0' + ((output[i0+k*j+(k-1)] - '0') + 1) % 2;
                    }
                }
                else {
                    forn(j, (i-i0) / k){
                        output[i0+k*j+(k-2)] = '0' + ((output[i0+k*j+(k-2)] - '0') + 1) % 2;
                    }
                }
                i0 = i;
            }
        }
        cout << ans << ' ';
        cout << output << nl;
    }

    return 0;
}