/**
 * Problem: https://www.hackerearth.com/acm-icpc-practice-contest/algorithm/exchanging-letters-icpc-7/
 */

#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define DB(x) cerr <<#x<<": " <<x<<" ";
#define DBL(x) cerr <<#x<<": " <<x<<endl;

#else

#define DB(x) 
#define DBL(x) 

#endif

#define ll long long

long long d[4100][4100];

long long nCr(long long n, long long k){
	if(n==k || n==0 || k==0) return 1;
	if(d[n][k] == -1){
		d[n][k] = (nCr(n-1,k-1) + nCr(n-1,k))%1000000007;
	}
	return d[n][k];
}

const ll MOD = 1000000007ll;
	ll DP[2100][2100];
	ll nCk(int n, int k){
	if(DP[n][k] == -1){
	if(n == k || k == 0 || n == 0) DP[n][k] = 1ll;
	else DP[n][k] = (nCk(n-1, k-1) + nCk(n-1, k)) % MOD;
	}
	return DP[n][k];
}


int main()
{
    int n, k, t;
    cin >> n>>k>>t;
    int ac = 0;
    int q;
    memset(d,-1,sizeof d);
    for(int i=0;i<k;i++){
    	cin >> q;
    	ac += q;
    }
    int d = abs(t-ac);
    if(d > k){
    	cout<<0<<endl;
    	return 0;
    } 
    if(k%2 != d%2){
    	cout<<0<<endl;
    	return 0;
    }
    DBL(d)
    int p = d+((k-d)/2);
    DB(p)
    DBL(k)
    cout<<nCr(k,p)<<endl;
   
}
