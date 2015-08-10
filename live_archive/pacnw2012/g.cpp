/*
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=99999999&category=579&page=show_problem&problem=4241
 */

#include <bits/stdc++.h>
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl;

using namespace std;

int ones;
int current_ones;


long long dc[100][100];


long long nCr(int n, int k){
	if(dc[n][k] == -1){
		if(k==0 || k==n){
			return 1ll;
		}
		dc[n][k] = nCr(n-1,k-1) + nCr(n-1,k);
	}
	return dc[n][k];
}

long long ways(int pos){
	int d = (ones - current_ones)%3;
	int c = (3-d)%3;
	if(!ones) c = 3;
	long long w = 0ll;
	for(int i=c; i<=pos; i+=3){
		w += nCr(pos, i);
	}
	return w;
}

int main(){
	long long n;
	memset(dc,-1,sizeof dc);
	while(cin >> n){
		long long bk = n;
		ones = 0;
		while(bk>0ll){
			if(bk % 2ll)
				ones++;
			bk /=2ll;
		}
		current_ones=0;
		int pos = 0;
		long long ans = 0ll;
		if(ones %3 == 0)ans++;
		for(long long i = 1ll;i<=n;i*=2ll){
			if(n&i){
				ones--;
				ans += ways(pos);
			}
			pos++;
		}
		cout << "Day " << n << ": Level = " << ans << endl;
		
	}
	
}
