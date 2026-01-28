#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    auto ask = [&](int i, int j) {
        cout << "? " << i << " " << j << endl;

        int ans;
        cin >> ans;
        return ans;
    };

    int j = -1;
    vector<int> val(n + 2); val[n] = 1;
    for(int i = n - 1; i; i--) {
        val[i] = ask(i, i + 1);
        if(val[i] && !val[i + 1]) {
            j = i;
            break;
        }
    }
    if(j == -1) {
        cout << "! " << -1 << endl;
        return;
    }

    // Need to sort [j + 1, n]
    int k = j + 1;
    while(!val[k + 1]) k++;

    // [j + 1, k] - decreasing
    // [k + 1, n] - increasing
    vector<int> order;
    int l = k, r = k + 1;
    while(l > j && r <= n) {
        if(ask(l, r)) order.push_back(l--);
        else order.push_back(r++);
    }
    while(l > j) order.push_back(l--);
    while(r <= n) order.push_back(r++);

    l = 0, r = order.size() - 1;
    while(l <= r) {
        int m = l + r >> 1;
        if(ask(j, order[m])) r = m - 1;
        else l = m + 1;
    }
    assert(l < order.size());

    vector<int> res(n + 1);
    iota(res.begin(), res.end(), 0);
    res[j] = order[l];
    order[l] = j;
    for(int i = j + 1; i <= n; i++) {
        res[i] = order[i - j - 1];
    }

    res.erase(res.begin());
    cout << "! "; for(auto i : res) cout << i << " "; cout << endl;
}

signed main() {
    int ttt = 1;
    cin >> ttt;
    while(ttt--) {
        solve();
    }
}