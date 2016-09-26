#include <bits/stdc++.h>
using namespace std;

bool a[50001];
vector<int> ady[50001];
int din[50000];

int ans = 0;

void check(int k);

void inscribe(int k){
  ans++;
  for(int c : ady[k]){
    din[c]--;
    check(c);
  }
}

void check(int k){
  if(a[k] && din[k] == 0){
    inscribe(k);
  }
}

int main(){
  int n,m;
  cin >> n >> m;
  memset(a, 0, sizeof a);
  memset(din, 0, sizeof din); 
  for(int i=0;i<m;i++){
    int u, v;
    cin >> u >> v;
    u--;v--;
    ady[u].push_back(v);
    din[v]++;
  }
  int k;
  for(int i=0;i<n;i++){
    cin >> k;
    k--;
    a[k] = true;
    check(k);
    cout<<ans<<endl;
  }
}

