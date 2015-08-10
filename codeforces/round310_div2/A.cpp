/*
 * Problem: http://codeforces.com/contest/556/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int  s[1000000];

int main(){
	char c;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> c;
		s[i] = (c=='1'?1:0);
	}
	int ans = n;
	int k=1;
	int cs = s[0];
	for(int i=1;i<n;i++){
		if(k==0){
			cs =s[i];
			k++;
		}
		else{
			if(s[i] != cs){
				ans-=2;
				k--;
			}
			else{
				k++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
