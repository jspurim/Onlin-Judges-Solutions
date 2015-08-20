/**
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=365&page=show_problem&problem=2474
 * 
 * Just write the specified celular automaton and execute the indicated number
 * of steps.
 */

#include <bits/stdc++.h>
#define DEB(x) cerr << "# " << #x << " " << x << endl;
#define DB(x) cerr << "# " << #x << " " << x << " ";
using namespace std;
typedef long long ll;

int l[2][500][500];


int dx[4];
int dy[4];

int main(){
	dx[0]=1;
	dy[0]=0;
	
	dx[1]=-1;
	dy[1]=0;
	
	dx[2]=0;
	dy[2]=1;
	
	dx[3]=0;
	dy[3]=-1;
	
	int n, r, c, k;
	while(cin>>n){
		cin >>r>>c>>k;
		if(n+r+c+k == 0){
			break;
		}
		
		
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin >> l[1][i][j];
			}
		}
		
		int x,y;
		for(int it=0;it<k;it++){
			int act = it%2;
			int old = (it+1)%2;

			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					l[act][i][j] = l[old][i][j]; 
					for(int d=0;d<4;d++){
						x=min(max(j+dx[d],0),c-1);
						y=min(max(i+dy[d],0),r-1);
						if(l[old][i][j] == ((l[old][y][x]+1)%n)){
							l[act][i][j] = l[old][y][x];
						}
					}
				}
			}
		}
		
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cout << l[(k+1)%2][i][j]<<" \n"[j == c-1];
			}
		}
	}
	
}
