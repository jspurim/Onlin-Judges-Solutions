/**
 * Problem: http://codeforces.com/contest/583/problem/A
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

bool v[50];
bool h[50];


int main(){
	int n;
	cin >> n;
	memset(v,0,sizeof v);
	memset(h,0,sizeof h);
	int rh;
	int rv;
	int d=0;
	bool first = true;
	for(int i=1;i<=n*n;i++){
		cin >> rh >> rv;
		rh--;
		rv--;
		if((!v[rv]) && (!h[rh])){
			if(!first){
				cout<<" ";
			}
			first = false;
			cout<<i;
			v[rv] = true; 
			h[rh] = true;
		}

	}
	cout<<endl;

	return 0;
}
