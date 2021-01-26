#include <bits/stdc++.h>
using namespace std;

class GraphL{
public:
  list<int> *adj;
  int size;
  GraphL(int size){
    this->size = size;
    adj = new list<int>[size];
  }
  void add_edge(int u, int v){
    adj[u].push_back(v);
  }

  void dfsHelper(int src, unordered_map<int, bool> &visited){
    if(visited[src])
      return;
    visited[src] = true;
    //cout << src << " ";
    for(auto nbr:adj[src]){
      if(!visited[nbr]){
        dfsHelper(nbr, visited);
      }
    }
  }

  void dfs(int src){
    unordered_map<int, bool> visited;
    dfsHelper(src, visited);
  }

  int connComp(int src){
    unordered_map<int, bool> visited;
    int cnt=0;
    for(int i=0; i<size; i++){
      if(!visited[i]){
        dfsHelper(i, visited);
        cnt++;
      }
    }
    return cnt;
  }

  void bsf(int src){
    unordered_map<int, bool> visited;
    queue<int> qu;
    qu.push(src);
    visited[src] = true;
    list<int>::iterator i;
    while(!qu.empty()){
      src = qu.front();
      cout << src << " ";
      qu.pop();
      for(i = adj[src].begin(); i != adj[src].end(); i++){
        if(!visited[*i]){
          visited[*i] = true;
          qu.push(*i);
        }
      }
    }
  }

};

class GraphH{
public:
  unordered_map<int, list<int>> adj;
  int size;
  GraphH(int size){
    this->size = size;
  }
  void add_edge(int u, int v){
    adj[u].push_back(v);
  }

  void dfsHelper(int src, unordered_map<int, bool> &visited){
    if(visited[src])
      return;
    visited[src] = true;
    //cout << src << " ";
    for(auto nbr:adj[src]){
      if(!visited[nbr]){
        dfsHelper(nbr, visited);
      }
    }
  }

  void dfs(int src){
    unordered_map<int, bool> visited;
    dfsHelper(src, visited);
  }

  int connComp(int src){
    unordered_map<int, bool> visited;
    int cnt=0;
    for(auto x:adj){
      if(!visited[x.first]){
        dfsHelper(x.first, visited);
        cnt++;
      }
    }
    return cnt;
  }

  void bsf(int src){
    unordered_map<int, bool> visited;
    queue<int> qu;
    qu.push(src);
    visited[src] = true;
    list<int>::iterator i;
    while(!qu.empty()){
      src = qu.front();
      cout << src << " ";
      qu.pop();
      for(i = adj[src].begin(); i != adj[src].end(); i++){
        if(!visited[*i]){
          visited[*i] = true;
          qu.push(*i);
        }
      }
    }
  }
};

class GraphV{
public:
  vector<int> *adj;
  int size;
  GraphV(int size){
    this->size = size;
    adj = new vector<int>[size];
  }
  void add_edge(int u, int v){
    adj[u].push_back(v);
  }
  void dfsHelper(int src, unordered_map<int, bool> &visited){
    visited[src] = true;
    cout << src << " ";
    for(auto nbr:adj[src]){
      if(!visited[nbr]){
        dfsHelper(nbr, visited);
      }
    }
  }
  void dfs(int src){
    unordered_map<int, bool> visited;
    dfsHelper(src, visited);
  }
  void bsf(int src){
    queue<int> qu;
    unordered_map<int, bool> visited;
    visited[0] = true;
    qu.push(0);
    while(!qu.empty()){
      int src = qu.front();
      qu.pop();
      cout << src << " ";
      for(auto x:adj[src]){
        if(!visited[x]){
          visited[x] = true;
          qu.push(x);
        }
      }
    }
  }
};

int main(){

  GraphH g1(5);
  g1.add_edge(0, 2);
  g1.add_edge(1, 0);
  g1.add_edge(1, 2);
  g1.add_edge(1, 3);
  g1.add_edge(1, 4);
  g1.add_edge(6, 5);
  cout << g1.connComp(1);

  return 0;
}