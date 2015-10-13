#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#else
#define DB(x);
#define DBL(x);
#endif

vector<int> P;
bool v[100];
int factors[50];
int N;

int dp[100][1<<13];
int r[100][1<<13];
int nextm[100][1<<13];
int a[100];

int f(int n, int m){
	if(n==N) return 0;
	if(dp[n][m] == -1){
		int ans = 1000000000;
		int candidate;
		for(int i=1;i<=40;i++){
			if(m & factors[i]) continue;
			candidate = abs(a[n]-i) + f(n+1,(m|factors[i]));
			if(candidate < ans){
				ans=candidate;
				r[n][m]=i;
				nextm[n][m] = (m|factors[i]);

			}
		}
		dp[n][m] = ans;
	}
	return dp[n][m];
}



int main(){
	memset(v,1,sizeof v);
	v[0] = v[1] = false;
	for(int i=0;i<100;i++){
		if(!v[i]) continue;
		for(int j=i+i;j<100;j+=i){
			v[j]=false;
		}
		P.push_back(i);
		DBL(P.back());
	}
	
	
	for(int i=1;i<=40;i++){
		factors[i] = 0;
		for(int j=0;j<14;j++){
			if(i%P[j]==0){
				factors[i] |= (1<<j);
			}
		}
		DB(i) DBL(factors[i])
	}
	
	int t;
	int c=0;
	while(true){
		memset(dp, -1, sizeof dp);
		c++;
		cin >> N;
		if(N==0) break;
		for(int i=0;i<N;i++) cin>>a[i];
		int m=0;
		f(0,0);
		cout<<"Case #"<<c<<": ";
		for(int i=0;i<N;i++){
			cout<<r[i][m]<<" \n"[i==N-1];
			m=nextm[i][m];
			DB(m)
		} 
	}
}
