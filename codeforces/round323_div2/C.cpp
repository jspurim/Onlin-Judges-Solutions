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
int gcd(int a, int b){
	DB(a) DBL(b)
	if(b == 0){
		return a;
	}
	return gcd(b, a%b);
}

int main(){
	int n;
	cin >> n;
	multiset<int, greater<int> > nums;
	vector<int> ans; 
	int k;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> k;
			nums.insert(k);
		}
	}
	while(nums.size()){
		DBL(nums.size());
		k = (*nums.begin());
		DBL(k)
		ans.push_back(k);
		for(int i=0;i<ans.size()-1;i++){
			int g = gcd(ans[i],k);
			nums.erase(nums.find(g));
			nums.erase(nums.find(g));
		}
		nums.erase(nums.find(k));
		DBL(nums.size());
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" \n"[i==n-1];
	}
	return 0;
}
