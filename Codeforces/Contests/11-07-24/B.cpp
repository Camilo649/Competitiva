# include <bits/stdc++.h>
# define ll long long
# define nl '\n'
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
 
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n, k;
	cin>>n>>k;
 
	vector<int> a(k);
	
	int pos = -1, maximo = 0;
	for(auto &e:a) cin>>e;
 
	for(int i=0;i<k;++i)
	{
	    if(maximo < a[i])
	    {
		maximo = a[i];
		pos = i;
	    }
	}
 
	ll res = 0;
	for(int i=0;i<k;++i)
	{
	    if(i == pos) continue;
	    res += a[i] * 2 - 1;
	}
 
	cout << res << nl;
    }
    
    return 0;
}