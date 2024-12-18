# include <bits/stdc++.h>
# define ll long long
# define nl '\n'
# define fi first
# define se second

using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
    if(a[0] > b[0]) return true;
    if(a[0] < b[0]) return false;

    for(int i=a.size()-1;i>0;--i)
    {
	if(a[i] == b[i]) continue;
	return a[i] > b[i];
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int v;
    cin>>v;

    int n = 10;
    vector<int> a(n, 0);
    for(int i=1;i<=9;++i) cin>>a[i];

    vector<vector<int>> dp(v+1, vector<int>(10, -1));
    
    for(int i=0;i<10;++i)
    {
	dp[0][i] = 0;
    }

    for(int i=0;i<v;++i)
    {
	if(dp[i][0] == -1) continue;

	dp[i][0]++;
	for(int j=1;j<=9;++j)
	{
	    if(i + a[j] > v) continue;

	    dp[i][j]++;
	    if(comp(dp[i], dp[i + a[j]])) dp[i + a[j]] = dp[i];
	    dp[i][j]--;
	}
	dp[i][0]--;
    }

    vector<int> res(10, 0);
    for(int i=0;i<=v;++i)
    {
	if(comp(dp[i], res)) res = dp[i];
    }

    if(res[0] == 0)
    {
	cout << -1 << nl;
	return 0;
    }

    for(int i=9;i>0;--i) for(int j=0;j<res[i];++j) cout << i;
    cout << nl;

    return 0;
}