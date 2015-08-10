/*
 * Problem: http://codeforces.com/contest/558/problem/B
 */


#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<<endl;
using namespace std;

map<int,int> first;
map<int,int> last;
map<int,int> times;
set<int> seen;

int main(){
	int n,a;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >>a;
		if(seen.find(a) == seen.end()){
			seen.insert(a);
			first[a] =i;
			last[a]=i;
			times[a]=1;
		} else{
			last[a] = i;
			times[a] = times[a]+1;
		}
	}
	int ml,mr,m,mt;
	mt = 0;
	m= 10000000;
	for(int i: seen){
		if(times[i] > mt){
			mt = times[i];
			ml = first[i];
			mr = last[i];
			m = mr-ml;
		} else if (times[i] == mt && (last[i]-first[i] <m)){
			mt = times[i];
			ml = first[i];
			mr = last[i];
			m = mr-ml;
		}
	}
	cout<<ml+1<<" "<<mr+1<<endl;
	return 0;
}
