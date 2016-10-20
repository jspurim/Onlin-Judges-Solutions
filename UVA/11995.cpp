/*
* Problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3146
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> op;

#define T first
#define V second

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<(x)<<" ";
#define DBL(x) cerr<<#x<<": "<<(x)<<endl;

#else

#define DB(x)
#define DBL(x)
#endif

bool check_st(vector<op> ops){
  stack<int> st;
  for(op o : ops){
    if(o.T == 1) st.push(o.V);
    else{
      if(st.size()==0 || o.V != st.top()) return false;
      st.pop();
    }
  }
  return true;
}

bool check_qu(vector<op> ops){
  queue<int> qu;
  for(op o : ops){
    if(o.T == 1) qu.push(o.V);
    else{
      if(qu.size()==0 || o.V != qu.front()) return false;
      qu.pop();
    }
  }
  return true;
}


bool check_pq(vector<op> ops){
  priority_queue<int> pq;
  for(op o : ops){
    if(o.T == 1) pq.push(o.V);
    else{
      if(pq.size()==0 || o.V != pq.top()) return false;
      pq.pop();
    }
  }
  return true;
}


int main(){
  int n;
  while(cin >> n){
    vector<op> ops;
    int t, v;
    for(int i=0;i<n;i++){
      cin >> t >> v;
      ops.emplace_back(t,v);
    }
    bool st = check_st(ops);
    bool qu = check_qu(ops);
    bool pq = check_pq(ops);
    int s = st+qu+pq; //I know, this is horrible, I'm ashamed of myself.
    if(s == 0){
      cout<<"impossible"<<endl;
    } else if(s>1){
      cout<<"not sure"<<endl;
    } else if (st){
      cout<<"stack"<<endl;
    } else if (qu){
      cout<<"queue"<<endl;
    } else if (pq){
      cout<<"priority queue"<<endl;
    }
  }
}


