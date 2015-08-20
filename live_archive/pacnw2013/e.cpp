/**
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#define ME(x,r,c) make_pair((x),make_pair((r),(c)))

int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

char M[1010][1010];
unsigned long long d[1010][1010];
long long exitd;
int main(){

	int t;
	cin >> t;
	while(t--){
		map<char, long long> power;
		int k,w,h;
		cin >> k >> w >> h;
		char type; int v;
		for(int i=0;i<k;i++){
			cin >> type >> v;
			power[type] = v;
		}
		
		exitd = 1000000000000000;
		set<pair<long long, pair<int, int> > > edges;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin >> M[i][j];
				d[i][j] = 1000000000000000;
			}
		}
		
		bool found = false;
		for(int i=0;i<h && !found;i++){
			for(int j=0;j<w;j++){
				if(M[i][j] == 'E'){
					edges.insert(ME(0,i,j));
					found = true;
					break;
				}
			}
		}
				
		
		pair<long long, pair<int, int> > edge;
		//DB(exitd) DBL(edges.size())
		while(edges.size()){
			//DB(exitd) DBL(edges.size())
			edge = *edges.begin();
			edges.erase(edge);
			int r,c;
			long long x;
			x = edge.first;
			r = edge.second.first;
			c = edge.second.second;
			//DB(x) DB(r) DB(c) DBL(d[r][c])
			if(x < d[r][c]){
				d[r][c] = x;
				for(int i=0;i<4;i++){
					int ar = r + dr[i];
					int ac = c + dc[i];
					//DB(r) DB(c) DB(ar) DB(ac) DBL(x)
					if(ar<0 || ac< 0 || ar >=h || ac >= w){
						exitd = min(exitd,x);
					} else {
						//DB(r) DB(c) DB(ar) DB(ac) DB(M[ar][ac]) DB(d[ar][ac]) DBL(x)
						if(power[M[ar][ac]]+x < d[ar][ac]){
		
							edges.insert(ME(power[M[ar][ac]]+x,ar,ac));
						}
					}
				}
			}
			
		}
		cout<<exitd<<endl;
		
	}

	return 0;

}
