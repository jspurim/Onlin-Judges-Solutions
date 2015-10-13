/**
 * Problem: http://codeforces.com/contest/586/problem/D
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

int dp[1000][3];
bool m[1000][3];
int n;

bool f(int p, int l){

	if(p>=n)
		return 1;
	if(l<0)
		return 0;
	if(l>2)
		return 0;
	if(!m[p][l]) dp[p][l] = 0;
	if(!m[p+1][l]) dp[p][l] = 0;
	if(dp[p][l] == -1){
		bool can = 0;
		bool ok;
		for(int i=-1;i<=1;i++){
			if((l+i >=0) && ((l+i)<=2) && (m[p+1][l+i]) && (m[p+2][l+i]) && (m[p+3][l+i])){
				bool ok = f(p+3,l+i);
				if(ok){
					can = 1;
				}
			}
		}
		dp[p][l] = can;
	}
	return dp[p][l];
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int k;
		memset(dp, -1, sizeof dp);
		cin >> n >> k;
		int start;
		//DB(n) DBL(k)
		for(int i=0;i<3;i++){
			string s;
			cin >> s;
			for(int j=0;j<n;j++){
				if(s[j] == 's'){
					start = i;
					m[j][i] = 1;
					continue;
				}
				m[j][i] = (s[j] == '.');
			}
			for(int j=n;j<n+100;j++){
				m[j][i]=1;
			}
		}
		cout<<(f(0,start)?("YES"):("NO"))<<endl;
	}
	return 0;
}
