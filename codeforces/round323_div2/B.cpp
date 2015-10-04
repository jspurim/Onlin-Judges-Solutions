/**
 * Problem: http://codeforces.com/contest/583/problem/B
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

bool v[1001];
int a[1001];

int main(){
	int n;
	cin >>n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int c=0;
	int d=0;
	memset(v,0,sizeof v);
	while(true){
		for(int i=0;i<n;i++){
			if(!v[i] && a[i] <= d){
				v[i] = true;
				d++;
			}
		}
		if(d==n) break;
		c++;
		for(int i=n-1;i>=0;i--){
			if(!v[i] && a[i] <= d){
				v[i] = true;
				d++;
			}
		}
		if(d==n) break;
		c++;
	}
	cout<<c<<endl;
	return 0;
}
