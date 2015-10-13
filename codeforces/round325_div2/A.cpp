/**
 * Problem: http://codeforces.com/contest/586/problem/A
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

int main(){
	int n;
	cin >> n;
	int f = -1;
	int l = -1;
	int k;
	int in;
	int a[1000];
	for(int i=0;i<n; i++){
		cin >> k;
		if(k){
			l=i;
			if(f==-1){
				f=i;
			}
			in++;
		}
		a[i] = k;
	}
			int b=0;
	if(f!= -1){
		int j=f;

		while(j<l){
			while(a[j] ==1) j++;
			int z=0;
			if(j>=l) break;
			while(a[j] == 0){
				z++;
				j++;
			}
			if(z>1){
				b+=z;
			} else{
				in+=z;
			}
		}
	}
	if(f==-1) {cout<<0<<endl;
	}else{
		DBL(b)
		cout<<l-f+1-b<<endl;
	}
	return 0;
}
