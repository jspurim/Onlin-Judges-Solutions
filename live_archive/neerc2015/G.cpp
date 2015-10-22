#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<(x)<<" ";
#define DBL(x) cerr<<#x<<": "<<(x)<<endl;

#else

#define DB(x)
#define DBL(x)
#endif

ll a[200010];

struct st_node;

st_node* st;

struct st_node{
	
	int id;
	ll l;
	ll r;
	ll rmq;
	ll rsq;
	ll lazy;
	ll dead;
	
	st_node& lson(){
		return st[id*2];
	}
	
	st_node& rson(){
		return st[id*2+1];
	}
	
	ll len(){
		return r-l+1;
	}
	
	ll count(){
		return len()-dead;
	} 
	
	void build(int id, int l, int r){
		this->id = id;
		this->l = l;
		this->r = r;
		lazy=0;
		dead = 0;
		if(r==l){
			rmq=a[r];
			rsq=a[r];
		} else {
			lson().build(id*2,l,l+((len())/2)-1);
			rson().build(id*2+1,l+((len())/2),r);
			rsq = lson().query_rsq() + rson().query_rsq();
			rmq = min(lson().query_rmq(), rson().query_rmq());
		}
	}
	
	ll query_rsq(){
		if(dead == len()){
			return 0;
		}
		return rsq+lazy*(count());
	}
	
	ll query_rmq(){
		return (dead==len()?LLONG_MAX:rmq+lazy);
	}
	
	ll query_rsq(int x){
		DB(x) DB(l) DBL(r)
		if(x < l) return 0;
		if(x >= r) return query_rsq();
		lson().update(lazy);
		rson().update(lazy);
		rsq = lson().query_rsq() + rson().query_rsq();
		rmq = min(lson().query_rmq(), rson().query_rmq());
		lazy=0;
		return lson().query_rsq(x) + rson().query_rsq(x);
	}
	
	void update(int v){
		if(dead == len()) return;
		lazy += v;
		if(rmq + lazy <= 0){
			if(l==r){
				dead=len();
				return;
			}
			lson().update(lazy);
			rson().update(lazy);
			lazy=0;
			rsq = lson().query_rsq() + rson().query_rsq();
			rmq = min(lson().query_rmq(), rson().query_rmq());
			dead = lson().dead + rson().dead;
		}
	}
} stdata[500100];


struct emp{
	int id;
	int d;
	int r;
	
	emp(int id, int d, int r) : id(id), d(d), r(r) {};
};

bool operator<(const emp& e1, const emp& e2){
	return (e1.d==e2.d)?(e1.id<e2.id):(e1.d<e2.d);
}

int main(){
	st = stdata;
	int n;
	int m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	
	vector<emp> emps;
	st_node& root = st[1];
	root.build(1,0,m-1);
	
	int d,r;
	for(int i=0;i<n;i++){
		cin >> d>>r;
		emps.emplace_back(i,d,r);
	}
	sort(emps.begin(),emps.end());
	int last = 0;
	int v;
	vector<pair<int, int> > ans;
	for(emp ep: emps){
		v = ep.d-last;
		last = ep.d;
		root.update(-v);
		int s=-1;
		int e=m;
		int k;
		while(e-s>1){
			k = (s+e)/2;
			if(k==-1 || k == m) break;
			if(root.query_rsq(k) >= ep.r){
				e=k;
			} else{
				s=k;
			}
		}
		if(root.query_rsq(e) >= ep.r){
			ans.emplace_back(ep.id,e+1);
		} else {
			ans.emplace_back(ep.id,0);
		}
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<n;i++){
		cout<<ans[i].second<<" \n"[i==n-1];
	}
	return 0;
}
