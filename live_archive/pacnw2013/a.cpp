/**
 * Problem:  https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=622
 */

#include <bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		int d;
		int v,f,c;
		cin >> n>>d;
		int ans = 0;
		for(int i=0;i<n;i++){
			cin >> v >> f>> c;
			if((v*f)>= c*d){
				ans ++;
			}
		}
		cout << ans << endl;
	}
}
