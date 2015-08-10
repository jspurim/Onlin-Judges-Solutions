/*
 * Problem: http://codeforces.com/contest/569/problem/D
 * 
 * This was easy to solve using Bell numbers and dynamic programming.
 * https://en.wikipedia.org/wiki/Bell_number
 * 
 * Complexity: O(N^2)
 * 
 * */

#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<<endl;
using namespace std;


long long d[5000];
long long dc[5000][5000];
long long nCr(int n, int k){
	if(k==0 || k ==n) return 1;
	if(dc[n][k] == -1){
		dc[n][k] = nCr(n-1, k-1) + nCr(n-1,k);
		dc[n][k] %= 1000000007;
	}
	return dc[n][k];
}


//Bell numbers
long long B(int n){

	if(n == 0) return 1;
	if(d[n] == -1){
		d[n] = 0;
		for(int i=0;i<n;i++){
			d[n] += (nCr(n-1,i)%1000000007)*(B(i)%1000000007);
			d[n] %= 1000000007;
		}
	}
	return d[n];
}

int main(){
	int n;
	cin >> n;
	memset(d,-1,sizeof d);
	memset(dc,-1,sizeof dc);
	long long ans = B(n+1)-B(n);
	if(ans <0)
		ans += 1000000007;
	cout<<ans <<endl;
	return 0;
}
