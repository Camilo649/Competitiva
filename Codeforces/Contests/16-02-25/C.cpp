#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<ll> pre(n), suf(n);
    if (a[0] > 0)
        pre[0] = a[0];

    for (int i = 1; i < n; i++){
        pre[i] = pre[i - 1];
        if (a[i] > 0)
            pre[i] += a[i];
    }

    if (a[n - 1] < 0)
        suf[n - 1] = -a[n - 1];
    
    for (int i = n - 2; i >= 0; i--){
        suf[i] = suf[i + 1];
        if (a[i] < 0)
            suf[i] -= a[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, pre[i] + suf[i]);
    
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();
}