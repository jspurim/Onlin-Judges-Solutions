#include <bits/stdc++.h>
using namespace std;

#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;

vector<int> a[100001];
vector<int> h;
vector<int> path;
#define PS (path.size())

int n, k1, k2;

bool v[100001];

bool dfs(int c){
  if(v[c]){
    return false;
  }
  v[c] = true;
  if(c == k1){
    path.push_back(c);
    return true;
  } 
  for(int p : a[c]){
    if(dfs(p)){
      path.push_back(c);
      return true;
    }
  } 
  return false;
}

typedef long long ll;

vector<ll> score;

ll calc_score(int t, int nx, int pr){
  ll ans = h[t];
  v[t] = true;
  ll mx=0;
  for(int ady : a[t]){
    if(ady != nx && ady != pr && !v[ady]){
      mx=max(mx,calc_score(ady,-1,-1));
    }
  }
  return ans+mx;
}

vector<ll> ac;

ll rsq(int i, int j){
  return ac[j]-ac[i];
}



ll logs[100001];
ll rmq[2][100001][16];
ll value[2][100001];

void initsptb(){
  logs[0] = logs[1] = 0;
  for(int i=2;i<100001;i++){
    logs[i] = logs[i >> 1]+1;
  }
  for(int k=0;k<2;k++){
    for(int i=0;i<PS;i++){
      rmq[k][i][0] = value[k][i];
    }
    for(int l=1;(1<<l)<PS;l++){
      for(int i=0;i+(1<<l)<=PS;i++){
        rmq[k][i][l] = max(rmq[k][i][l-1], rmq[k][i+(1<<(l-1))][l-1]);
      }
    }
  }
}

ll rm_query(int k, int i, int j){
  int d = j-i;
  int l = logs[d];
  //DB(k) DB(i) DB(j-(1<<l)+1)DB(d) DBL(l)
  //DB(rmq[k][i][l]) DBL(rmq[k][j-(1<<l)+1][l])
  return max(rmq[k][i][l], rmq[k][j-(1<<l)+1][l]);
}

ll f2(int steps);

ll f1(int steps){
  int p1 = steps;
  int p2 = PS-1-steps;
  //DB(PS) DB(p1) DBL(p2)
  //DB(value[0][p1]) DBL(rm_query(1,p1+1,p2))
  ll ans1 = value[0][p1] - rm_query(1,p1+1,p2);
  if(p1 == p2-1) return ans1;
  else return max(ans1, f2(steps));
}

ll f2(int steps){
  int p1 = steps+1;
  int p2 = PS-1-steps;
  ll ans1 = rm_query(0,p1,p2-1) - value[1][p2];
  if(p1 == p2-1) return ans1;
  else return min(ans1, f1(steps+1));
}


int main(){
  memset(v,0,sizeof v);
  cin >> n >> k1 >> k2;
  k1--;
  k2--;
  for(int i=0;i<n;i++){
    int k;
    cin >> k;
    h.push_back(k);
  }
  for(int i=0;i<n-1;i++){
    int u, w;
    cin >> u >> w;
    u--; w--;
    a[u].push_back(w);
    a[w].push_back(u);
  }
  dfs(k2);
  

  vector<ll> score;
  ac.push_back(0);
  ll total = 0;
  for(int t : path){
    //DBL(t)
    total += h[t];
    ac.push_back(total);
  }
  memset(v,0,sizeof v);
  score.push_back(calc_score(path[0], -1, path[1]));
  for(int i=1;i<PS-1;i++){
    score.push_back(calc_score(path[i], path[i-1], path[i+1]));
  }
  score.push_back(calc_score(path[PS-1], -1, path[PS-2]));
  
  for(int i=0;i<PS;i++){
    value[0][i] = rsq(0,i) + score[i];
    value[1][i] = rsq(i+1,PS) + score[i];
    //DB(value[0][i]) DB(value[1][i]) DBL(score[i])
  }
  initsptb();
  int x,y,z;

  cout<<f1(0)<<endl;
  
}
