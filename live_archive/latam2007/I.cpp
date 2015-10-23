#include <bits/stdc++.h>
using namespace std;
#define time lkjkjkjkjkjk
#define ll long long
#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<(x)<<" ";
#define DBL(x) cerr<<#x<<": "<<(x)<<endl;

#else

#define DB(x)
#define DBL(x)
#endif

ll wa[100];
ll time[100];
int ac[100];

struct team{
	int id;
	ll p;
	int ac;
	
	team(int id, int ac,  ll p){
		this->id = id;
		this->p = p;
		this->ac = ac;
	}
};

ll cmp(const team& t1, const team& t2){
	if(t1.ac == t2.ac){
		return t2.p - t1.p;
	}
	return t1.ac - t2.ac;
}

bool operator<(const team& t1, const team& t2){
	if(cmp(t1, t2) == 0)
		return t1.id < t2.id;
	return cmp(t1,t2) < 0;
}

int main(){
	int t, p;
	
	while(cin >> t >> p){
		if(t+p == 0){
			break;
		}
		vector<team> normal;
		int a;
		char c;
		string sp;
		for(int i=0;i<t;i++){
			wa[i] = 0;
			time[i] = 0;
			ac[i] = 0;
			for(int j = 0;j<p;j++){
				cin >>a>>c>>sp;
				if(sp[0] == '-'){
				} else {
					wa[i] += a-1;
					time[i] += stoi(sp);
					ac[i]++;
				}
			}
			normal.emplace_back(i, ac[i], time[i] + wa[i]*20);
		}
		
		sort(normal.begin(), normal.end());
		int mn = 20;
		for(int k=20;k>=1;k--){
			vector<team> test;
			for(int i=0;i<t;i++){
				test.emplace_back(i, ac[i], time[i] + wa[i]*k);
			}
			sort(test.begin(),test.end());
			for(int i=0;i<t;i++){
				team a = normal[i];
				team b = test[i];
			}
			bool ok = true;
			for(int i=1;i<t;i++){
				if(test[i].id != normal[i].id){
					ok = false; break;
				}
				if((cmp(normal[i], normal[i-1]) == 0) != (cmp(test[i], test[i-1]) == 0)){
					ok = false; break;
				}
			}
			if(!ok) break;
			mn = k;
		}
		cout<<mn<<" ";
		ll s = 20; ll e = 3000000000ll;
		while((e-s) > 1ll){
			ll k = (e+s)/2ll;
			DBL(k)
			vector<team> test;
			for(int i=0;i<t;i++){
				test.emplace_back(i, ac[i], time[i] + wa[i]*k);
			}
			sort(test.begin(),test.end());
			for(int i=0;i<t;i++){
				team a = normal[i];
				team b = test[i];
				DB(a.id) DB(a.ac) DBL(a.p);
				DB(b.id) DB(b.ac) DBL(b.p);
			}
			bool ok = true;
			for(int i=1;i<t;i++){
				if(test[i].id != normal[i].id){
					ok = false; break;
				}
				if((cmp(normal[i], normal[i-1]) == 0) != (cmp(test[i], test[i-1]) == 0)){
					ok = false; break;
				}
			}
			if(!ok){
				e=k;
			} else {
				s=k;
			}
		}
		if(s >=2000000000){
			cout<<"*"<<endl;
		} else {
			cout<<s<<endl;
		}
	}
	
	
}
