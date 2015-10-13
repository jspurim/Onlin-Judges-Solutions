/**
 * Problem: http://codeforces.com/contest/586/problem/B
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

int u[100];
int l[100];
int c[100];

int main(){
	int n;
	cin >> n;
	u[0] = 0;
	int k;
	for(int i=1;i<n;i++){
		cin >> k;
		u[i] = u[i-1] + k;
	}
	l[n-1] = 0;
	for(int i=0;i<n-1;i++){
		cin>>l[i];
	}
	for(int i=n-2;i>=0;i--){
		l[i] += l[i+1];

	}
	for(int i=0;i<n;i++){
		cin >> c[i];
		
	}
	int mn=INT_MAX;
	int smn=INT_MAX;
	int ans;
	for(int i=0; i<n;i++){
		ans = c[i] + u[i] +l[i];
		DB(i) DB(c[i]) DB(u[i]) DB(l[i]) DBL(ans)
		if(ans <= mn){
			smn = mn;
			mn = ans;
		} else if(ans<= smn){
			smn=ans;
		}
	}
	cout<<mn+smn<<endl;
	return 0;
}
