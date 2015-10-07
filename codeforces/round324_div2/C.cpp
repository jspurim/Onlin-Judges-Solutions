/**
 * Problem: http://codeforces.com/contest/584/problem/C
 */
#include <bits/stdc++.h>

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#else
#define DB(x)
#define DBL(x)
#endif

#define mkp make_pair
#define ll long long
#define pll pair<ll,ll>
#define forn(i,N) for(int (i)=0;(i)<(N);(i)++)

using namespace std;

bool e[100002];

int main(){
	string s, t;
	int n, d;
	cin >> n >> d;
	cin >> s >> t;
	int eq=0;
	int nq=0;
	for(int i=0;i<n;i++){
		if(s[i]==t[i]){
			e[i] = true;
			eq++;
		} else {
			e[i]=false;
			nq++;
		}
	}
	DB(eq) DBL(nq)
	char ans[100002];
	ans[n]=0;
	
	if(d >= nq){
		int de = d-nq;
		for(int i=0;i<n;i++){
			if(e[i] && de){
				ans[i] = (s[i]=='a')?'b':'a';
				de--;
			} else if(e[i]){
				ans[i] = s[i];
			} else {
				for(int j=0;j<3;j++){
					if(s[i] != 'a'+j && t[i] !='a'+j){
						ans[i] = 'a'+j;
						break;
					}
				}
			}
		}
	} else {
		int de = nq-d;
		DB(de)
		if(de*2 > nq){
			cout<<-1<<endl;
			return 0;
		}
		de*=2;
		for(int i=0;i<n;i++){
			if(e[i]){
				ans[i] = s[i];
			} else if(de){
				if(de%2){
					ans[i] = s[i];
				}else{
					ans[i] = t[i];
				}
				de--;
			} else{
				for(int j=0;j<3;j++){
					if(s[i] != 'a'+j && t[i] !='a'+j){
						ans[i] = 'a'+j;
						break;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
