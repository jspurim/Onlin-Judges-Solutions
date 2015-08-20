/**
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=9
 * 
 * Greedy: 
 * 	* Consider characters as numbers in Z_26.
 *  * Add an 'a'(0) to both ends of the string.
 *  * Compute the array of differences between consecutives.
 *  * Until all numbers are zero, decrement (mod 26) the smallest non
 *    zero number in this array and increment (mod 26) the largest. 
 *  * Output the number of pairs of increments and decrements.
 */

#include <bits/stdc++.h>
#define DBD for(int i=0;i<s.size()+1;i++){cerr<<d[i]<<" ";}cerr<<endl;
using namespace std;

int a[2000];
int d[2000];
int main(){

	string s;
	while(cin >> s){
		if(s == "*") break;
		a[0] = 0;
		a[s.size()+1]=0;
		for(int i=1;i<=s.size(); i++){
			a[i] = s[i-1]-'a';
		}
		for(int i=0;i<=s.size();i++){
			d[i]= ((a[i+1]-a[i])+26)%26;
		}
		sort(d,d+s.size()+1);
		int l,r;
		l=0;
		r=s.size();
		long long ans = 0;
		//DBD
		while(r>l){
			if(d[l] == 0){
				l++;
				continue;
			}
			if(d[r] == 0){
				r--;
				continue;
			}
			else{
				ans++;
				d[l] = (d[l] +25) %26;
				d[r] = (d[r]+1)%26;
				//DBD
			}
		}
		cout<<ans<<endl;
	}

}
