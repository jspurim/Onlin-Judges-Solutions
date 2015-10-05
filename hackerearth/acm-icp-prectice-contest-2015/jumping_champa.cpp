/**
 * Problem: https://www.hackerearth.com/problem/algorithm/jumping-champa-icpc-1/
 */
#include <iostream>
using namespace std;
 
int main()
{
	int t;
	cin >> t;
	long long n, q;
	while(t--){
		cin >> n >> q;
		long long mn = 4000000;
		long long mx = -2;
		long long h;
		for(int i=0;i<n;i++){
			cin >> h;
			mn = min(mn,h);
			mx = max(mx,h);
		}
		cout<<(mx-mn)*q<<endl;
	}
    return 0;
}
