/**
 * Problem: http://lightoj.com/volume_showproblem.php?problem=1400
 */

#include <bits/stdc++.h>

using namespace std;

#define MAXN 101

//Gale Shapley stable matching algorithm.
//O(n^2). 
//Asumes acceptors and proposers numbered from 1 to n.

int A[MAXN][MAXN];         //A[i][j] is the order of preference
                           //of the j proposor for the i acceptor 
int P[MAXN][MAXN];         //P[i][j] is the jth preferer acceptor
                           //for proposor i.
int LP[MAXN];
int ans[MAXN];
int best[MAXN];
int n;

void stable_matching(){
  memset(LP, 0, sizeof LP);
  memset(ans, 0, sizeof ans);

  memset(best, 0, sizeof best);
  bool end=false;
  while(!end){
    end = true;
    for(int p=1;p<=n;p++){
      if(ans[p] != 0) continue;
      end=false;
      int a = P[p][LP[p]++];
      if(( best[a] == 0) || (A[a][p] < A[a][best[a]]) ){
        ans[best[a]] = 0;
        ans[p] = a;
        best[a] = p;
      }
    }
  }
}


int main(){

  int t;
  cin>>t;
  for(int c=1;c<=t;c++){
    

    cin>>n;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        int k;
        cin>>k;
        k-=n;
        A[i][k]=j;
      }
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        cin >> P[i][j];
      }
    }
    
    stable_matching();
    cout<<"Case "<<c<<": ";
    for(int i=1;i<=n;i++){
      cout<<"("<<ans[i]<<" "<<i+n<<")"<<" \n"[i==n];
    }

  }

  return 0;
}
