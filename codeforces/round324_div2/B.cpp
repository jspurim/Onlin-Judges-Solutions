/**
 * Problem: http://codeforces.com/contest/584/problem/B
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
#define MOD 1000000007

using namespace std;
long long d[100005];

long long p27[100005];

long long f(int n){
	if(d[n] == -1){
		d[n] = ((7*f(n-1))+(20*p27[n-1]))%MOD;
	}
	return d[n];
}

int main(){
	memset(d,-1,sizeof d);
	p27[0]=1;
	d[1] = 20;
	d[0] = 0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		p27[i] = (p27[i-1]*27)%MOD;
	}
	cout<<f(n)<<endl;
	return 0;
}
