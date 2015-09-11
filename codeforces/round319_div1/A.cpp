/**
 * Problem: http://codeforces.com/contest/576/problem/A
 */
#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;

#define mkp make_pair
#define ll long long
#define pll pair<ll,ll>
#define forn(i,N) for(int (i)=0;(i)<(N);(i)++)

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> p;
	for(int i=2;i<1000;i++){
		bool isp = true;
		for(int j=2; j<i;j++){
			if(i%j == 0){
				isp = false;
				break;
			}
		}
		if(isp){
			p.push_back(i);
		}
	}
	
	int sq = sqrt(n);
	vector<int> ans;
	for(int pr : p){
		int a = pr;
		for(int i=0;i<100;i++){
			if(a <= n){
				ans.push_back(a);
				a*=pr;
			} else {
				break;
			}
		}
	}
	
	cout<< ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" \n"[i==ans.size()-1];
	}
	return 0;
}
