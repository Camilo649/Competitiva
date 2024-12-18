#include<bits/stdc++.h>
#define forn(i,n) for(int i=0; i<n; i++)
#define ll long long
#define vi vector<int>
#define MAT
using namespace std;
 
int main()
{
    #ifdef MAT
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int sum=0;
        int par=0;
        for(int i = 0; i<s.size(); ++i)
        {
            int aux = (s[i] - '0');
            sum += aux;
            par += !(aux%2);
        }        
        if ((sum % 3 == 0) && par>=2 && s.find('0')!=s.npos)
        {
            cout << "red" << '\n';
        }
        else 
        {
            cout << "cyan" << '\n';
        }
    }
    
    
    return 0;
}