#include <bits/stdc++.h>

#define fst first
#define snd second
#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset(a,v,size_of(a))
#define forn(i,a,b) for(int i = a; i< b; i++)
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

using namespace std;
typedef long long ll;

#define oper(a,b) a+b
#define NEUT 0
struct STree { // segment tree for min over integers
	vector<int> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, int *a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

bool cmp( const pair<ll,ll> &a, const pair<ll,ll> &b){
    if(a.fst>b.fst) return true;
    if(a.fst<b.fst) return false;
    return a.snd>b.snd;
}

int main(){ 
    ll n,T; cin>>n>>T; 
    vector<pair<ll,ll>> a(n); forn(i,0,n) cin>>a[i].fst, a[i].fst-=i+1, a[i].snd=i, a[i].fst=max(a[i].fst,(ll)0);
    
    sort(ALL(a));
    
    vector<ll> res;
    
    queue<ll> cola;
    STree st(n+5);

    
    forn(i,0,n){
        if(i+1<n && a[i].fst==a[i+1].fst){
            cola.push(a[i].snd);
            //cout<<a[i].fst<<" "<<a[i+1].fst<<'\n';
        }else{
            st.upd(a[i].snd,1);
            while(!cola.empty()){
                st.upd(cola.front(),1);
                cola.pop();
            }
            //cout<<T-a[i].fst<<'\n';
            res.pb(st.query(0,(T-a[i].fst)-1));
            //cout<<a[i].fst<<" "<<st.query(0,(T-a[i].fst)-1)<<'\n';
        }
        
        //forn(j,0,n) cout<<st.query(j,j+1)<<" "; cout<<'\n';
    }
    
    ll rres = 0;
    for(auto i:res){
        rres = max(i,rres);
    }
    
    
    cout<<rres<<'\n';
    
   
    return 0;
}