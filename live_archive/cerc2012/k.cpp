/**
 * //Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4276
 * 
 * The idea is selecting one node from each tree as root. Then we remove the 
 * edge going up (relative to the selected root) from each subtree with an even 
 * number of leaves.
 * After that we simply check if the resulting graph is a cicle.
 */

#include <bits/stdc++.h>

using namespace std;

string name[5000];
bool v[5000];
int l[5000];
int de[5000];
set<int> *ady;


//Counts how many leaves are on the subtree rooted at this node.
//Marks the depth of each node with respect to the root.
int leaves(int node, int depth){
	if(v[node])
		return 0;
	de[node] = depth;

	v[node] = true;
	if(ady[node].size() == 1){
		l[node] = 1;
	}
	else{
		int t=0;
		for(auto a : ady[node]){
			t += leaves(a, depth+1);

		}
		l[node] = t;
	}
	return l[node];

}

int main() {
	int t;
	int k,n,m;
	int tn;
	cin >> t;
	while(t--){
		memset(v,0,sizeof v);
		memset(l,0,sizeof l);
		memset(de,0,sizeof l);
		map<string,int> id;
		cin >>k >> n >>m;
		ady = new set<int>[n+m+k+k];
		tn = m+n+(2*k);
		//Name the nodes
		int i=0;
		for(int j=0;j<k;j++,i++){
			name[i] = "AS"+to_string(j+1);
		}
		for(int j=0;j<n;j++,i++){
			name[i] = "AP"+to_string(j+1);
		}	
		for(int j=0;j<k;j++,i++){
			name[i] = "BS"+to_string(j+1);
		}
		for(int j=0;j<m;j++,i++){
			name[i] = "BP"+to_string(j+1);
		}
		for(int i=0; i<tn;i++){
			id[name[i]]=i;
		}
		//Build the trees but not connect them
		string s, d;
		int si, di;
		for(int i=0;i<n+m+k+k-2;i++){
			cin >> s >> d;
			si = id[s];
			di = id[d];
			ady[di].insert(si);
			ady[si].insert(di);
		}
		//Count leaves and select root for both trees
		leaves(k,0);
		leaves(n+k+k,0);
	
		//Remove extra edges
		for(int i=0;i<n+m+k+k;i++){
			if(l[i]%2 == 0){
				for(auto a : ady[i]){
					if(de[a] < de[i]){
						ady[a].erase(i);
						ady[i].erase(a);
						break;
					}
				}
			}
		}
		
		//Connect both trees;
		for(int i=0;i<k;i++){
			cin >> s >> d;
			si = id[s];
			di = id[d];
			ady[di].insert(si);
			ady[si].insert(di);
		}
		
		//Look for a cicle
		vector<string> path;
		bool can = true;
		memset(v,0,sizeof v);
		int last = 0;
		v[0] = true;
		int cur = *ady[0].begin();
		path.push_back(name[0]);
		while(!v[cur]){
			if(ady[cur].size() != 2){
				can = false;
				break;
			}	
			v[cur] = true;
			path.push_back(name[cur]);
			for(auto a: ady[cur]){
				if(a!=last){
					last = cur;
					cur = a;
					break;
				}
			}
		}
		
		//Output
		can = can && cur == 0;
		can = can && path.size() == n+m+k+k;
		if(can){
			cout << "YES";
			for(auto s : path){
				cout << " " << s;
			}
			cout<<endl;
		} else{
			cout << "NO"<<endl;
		}
	}

	return 0;
}
