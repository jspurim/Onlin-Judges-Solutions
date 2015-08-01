/**
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4272
 * 
 * The idea is to sort the jewells by height. The we take each jewell and
 * query how many jewells are strictly below this one. We choose the left and
 * right limits of this query rectangle by looking for the two nearest
 * jewells of the same color as the selected one and below it.
 * 
 * The trick to implement this is have all data structures only contain
 * data of already processed jewels (hence, below the current one.
 * We use a fenwick tree for the range queries and a set for each color
 * to get the limits of the query we mus make on each step.
 * 
 * Important: All jewels in the same height must be processed before adding
 * them to the fenwick tree or the sets.
 * 
 * Important #2: After we processed all jewells, we must still consider
 * all rectangles of infinite height in the intervals between too jewells
 * of the same color.
 * 
 */

#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<<endl;
#define DBJ(j) cerr<<"("<<j.l<<") "<<j.x<<","<<j.y<<endl;
using namespace std;

struct Jewel{
	int x;
	int y;
	int l;
	
	bool operator<(const Jewel& rhs) const{
		return this->y<rhs.y;
	}
};
#define MAXN 200020

int ft[MAXN], ft_size; 
void update (int pos, int val) {
	for (; pos<=ft_size; pos+=(pos&(-pos))) ft[pos] += val;
}
int query (int pos) {
	int ans = 0;
	for (; pos>0; pos-=(pos&(-pos))) ans += ft[pos];
	return ans;
}
int query (int a, int b) {
	if(b<a){
		return 0;
	}
	return query(b) - query(a-1);
}

int main(){
	int t;
	cin >> t;
	int m, n;
	while (t--){
		memset(ft,0,sizeof ft);
		cin >> n >> m;
		multiset<Jewel> all;
		set<int> coords;
		map<int,int> points;
		set<int> *layer = new set<int>[m];

		for(int i=0;i<n;i++){
			Jewel j;
			cin >>j.x >> j.y>>j.l;
			j.l--;
			coords.insert(j.x);
			all.insert(j);
		}
		int pos=1;
		for(auto coord_x : coords){
			points[coord_x]=pos;
			pos++;
		}
		for(int i=0;i<m;i++){
			layer[i].insert(0);
			layer[i].insert(coords.size()+1);
		}
		ft_size = coords.size()+2;
		

		int l,r;
		int np;
		int ans = 0;
		int last_y = -1;
		vector<Jewel> to_process; 
		for(Jewel j : all){
			if(last_y != j.y){
				
				for(Jewel j2 : to_process){	
					np = points[j2.x];
					layer[j2.l].insert(np);
					update(np,1);
				}
				to_process.clear();
			};

			to_process.push_back(j);
			auto it = layer[j.l].upper_bound(points[j.x]);


			r=(*it)-1;
			it--;
			l=(*it)+1;
			ans = max(ans,query(l,r));

			last_y = j.y;
		}

		for(Jewel j2 : to_process){	
			np = points[j2.x];
			layer[j2.l].insert(np);
			update(np,1);
		}
		//Check rectangles of infinite height in the spaces between 
		//same colered jewells
		for(int i=0;i<m;i++){
			auto it = layer[i].begin();
			auto it2 = layer[i].begin();
			it2++;

			for(;it2!=layer[i].end();it++,it2++){
				l=(*it)+1;
				r=(*it2)-1;

				ans = max(ans,query(l,r));
			}
		}
		
		
		cout<<ans<<endl;

	}
}
