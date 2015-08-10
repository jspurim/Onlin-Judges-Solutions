/*
 * Problem: http://codeforces.com/contest/569/problem/B 
 * 
 * Leave first ocurrence of each number as is. Add positions with
 * reapeated or out of range numbers to a list;
 * For each not found number, insert it in one of the previously collected
 * list of invalid positions.
 * 
 * Complexity: O(N)
 */

#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<<endl;
using namespace std;

int main(){
	int n;
	cin >>n;
	int a[100010];
	bool b[100010];
	memset(b,0,sizeof b);
	vector<int> r;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(b[a[i]] || a[i] > n){
			r.push_back(i);
		} else{
			b[a[i]] = true;
		}
	}
	int nr = 0;
	for(int i =1;i<=n;i++){
		if(!b[i]){
			a[r[nr]] = i;
			nr++;
		}
	}
	for(int i=0;i<n;i++){
		cout << a[i]<<" \n"[i==(n-1)];
	}
	
	return 0;
}
