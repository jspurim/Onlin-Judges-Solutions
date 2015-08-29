/**
 * Problem: http://www.spoj.com/problems/BANDW/
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
	string s, p;
	while(cin >> s >> p){
		if(s == "*") break;
		int i = 0;
		int ans = 0;
		while(i<s.size()){
			if(s[i] != p[i]){
				ans++;
				while(s[i] != p[i])
					i++;
				i--;
			}
			i++;
		}
		cout << ans<<endl;
	}
}
