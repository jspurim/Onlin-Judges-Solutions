/**
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4528
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(true){
		cin >> n;
		if(n == -1) break;
		set<int> ans;
		ans.insert(1);
		int s = 1;
		for(int i=2;i<sqrt(n);i++){
			if(n%i == 0){
				s += i;
				s += n/i;
				ans.insert(i);
				ans.insert(n/i);
			}
		}
		if(s == n){
			cout<<n<<" = ";
			int o = 1;
			for(auto k : ans){
				cout<<k;
				if(o==ans.size())
					cout<<endl;
				else
					cout<<" + ";
				o++;
			}
		} else {
			cout << n << " is NOT perfect."<<endl;
		}
	}

}
