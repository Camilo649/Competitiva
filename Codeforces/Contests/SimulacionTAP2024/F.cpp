#include <bits/stdc++.h>
     
    using namespace std;
    typedef long long ll;
    typedef pair<ll,ll> ii;
    typedef vector<int> vi;
    typedef vector<ll> vl;
    ll INF = 1e18;
    #define MAXN 100005
    #define pb push_back
    #define mp make_pair
    #define fst first
    #define snd second
    #define fore(i,a,b) for(ll i=a,to=b;i<to;++i)
    #define MILF

    int main() {

        #ifdef MILF
            freopen("../input.txt", "r", stdin);
        #endif

        //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        ll n,t;
        cin>>n>>t;
        vector<long double>prior_v;
        vector<long double>nonprior_v;

        fore(i,0,n){
            char c;
            ll p;
            cin>>c>>p;
            if(c=='P'){
                prior_v.pb(p);
            }else{
                nonprior_v.pb(p);
            }
        }

        ll prior=prior_v.size();
        ll nonprior=nonprior_v.size();

        sort(prior_v.begin(), prior_v.end());
        sort(nonprior_v.begin(), nonprior_v.end());
        double prior_desc=0;
        double nonprior_desc=0;

        long double seconds=0;
        long double min_time=0;
        long double total_down_prior=0;
        long double total_down_nonprior=0;
        while ((prior+nonprior)>0)
        {   
            long double min_prior = INF;
            long double min_nonprior = INF;
            if(prior>0){
                prior_desc=nonprior==0?t:t*0.75;
                long double prior_div = prior_desc/prior;
                min_prior = abs((prior_v[prior_v.size()-prior]-total_down_prior)/prior_div);
            }
            if (nonprior>0){
                nonprior_desc=prior==0?t:t*0.25;
                long double nonprior_div = nonprior_desc/nonprior;
                min_nonprior = abs((nonprior_v[nonprior_v.size()-nonprior]-total_down_nonprior)/nonprior_div);
            }
            //cout<<"minprior "<<min_prior<<" min_non "<<min_nonprior<<"\n";
            min_time = min(min_prior, min_nonprior);
            seconds+=min_time;
            
            total_down_prior += (prior_desc*min_time)/prior;
            total_down_nonprior += (nonprior_desc*min_time)/nonprior;

            if(min_time==min_prior){
                prior--;
            }else{
                nonprior--;
            }
            //cout<<seconds<<" "<<prior<<" "<<nonprior<<"\n";
        }
        cout<<seconds;
        return 0;
    }