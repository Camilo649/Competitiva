# include <bits/stdc++.h>
# define ll long long
# define nl '\n'
# define fi first
# define se second
# define intt long long

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<pair<int, int>> a(n);
    for(auto &e:a) cin>>e.fi>>e.se;
   
    //sort(a.begin(), a.end());

    vector<int> res(n, 0);

    priority_queue<array<int, 2>> pq;

    int j = 0;
    for(int i=1;i<1e7;++i)
    {
	while(j < n && a[j].fi == i)
	{
	    pq.push({a[j].se - a[j].fi, j});
	    ++j;
	}

	if(!pq.empty()) 
	{
	    auto [u, v] = pq.top();
	    pq.pop();

	    res[v] = i;
	}
    }

    for(auto &e:res) cout << e << " ";
    cout << nl;

    return 0;
}