/**
 * Problem: http://codeforces.com/contest/586/problem/C
 */
#include <bits/stdc++.h>

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#else
#define DB(x)
#define DBL(x)
#endif

#define mkp make_pair
#define ll long long
#define pll pair<ll,ll>
#define forn(i,N) for(int (i)=0;(i)<(N);(i)++)

using namespace std;

long long v[4000];
long long d[4000];
long long c[4000];

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> v[i] >> d[i]>> c[i];
	}
	vector<int> ans;
	for(int i=0;i<n;i++){
		if(c[i] <0) continue;
		ans.push_back(i);
		long long s = v[i];
		long long h = 0ll;
		for(int j=i+1;j<n;j++){
			if(c[j] < 0ll) continue;
			c[j] -=s;
			c[j] -=h;
			s--;
			s=max(0ll,s);
			if(c[j] < 0ll){
				h+=d[j];
			}
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]+1<<" \n"[i==ans.size()-1];
	}

	return 0;
}
