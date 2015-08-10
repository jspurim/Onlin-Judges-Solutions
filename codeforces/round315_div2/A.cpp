/*
 * Problem: http://codeforces.com/contest/569/problem/A
 * 
 * Represent the downloaded and listened data as linear functions 
 * D and L over time t.
 * Then L(t) = t and D(t) =  t*(q-1)/q + s
 * Operate matimatically and find the song will stop at time t = s*q. 
 * When the song restarts s*q becomes the new s. Just simulate and count 
 * restarts.
 * 
 * Complexity: O(log t)
 */

#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<<endl;
using namespace std;

int main(){
	int s, t, q;
	int ans = 0;
	cin >> t >> s >> q;
	while(s < t){
		int x = s*q;
		s= x;

		ans++;
	}
	cout << ans<<endl;
	return 0;
}
