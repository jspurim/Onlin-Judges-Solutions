/**
 * Problem: https://www.hackerearth.com/acm-icpc-practice-contest/algorithm/sonya-and-the-graph-with-disappearing-edges-icpc-5/
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define DB(x) cerr <<#x<<": " <<x<<" ";
#define DBL(x) cerr <<#x<<": " <<x<<endl;

#else

#define DB(x) 
#define DBL(x) 

#endif
int main()
{
	int n;
	int a[1000];
	int ac[1000];
	map<int, int> l;
	map<int, int> c;
	cin>>n;
	ac[0]=0;
	for(int i=0;i<n;i++){
		cin >>a[i];
		ac[i+1] = ac[i]+a[i];
	}
	int k;
	int mx = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			k=ac[j]-ac[i];
			DB(i) DB(j) DBL(k)
			if(l.find(k) == l.end() || l[k] <= i){
				l[k] = j;
				if(c.find(k) == c.end()){
					c[k]=1;
				} else{
					c[k] = c[k]+1;
				}
				DBL(c[k])
				mx = max(mx,c[k]);
			}
		}
	}
	cout<<mx<<endl;
	vector<int> ans;
	for(map<int,int>::iterator it = c.begin();it!=c.end();it++){
		if(it->second == mx)
			ans.push_back(it->first);
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" \n"[i==ans.size()-1];
	}
    return 0;
}
