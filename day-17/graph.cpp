#include <bits/stdc++.h>
using namespace std;

class Graph{
  int v;
  map<int, list<int>> adj;
public:
  Graph(int v){
    this->v = v;
  }
  void addEdge(int u, int v, bool bidir){
    adj[u].push_back(v);
    if(bidir){
      adj[v].push_back(u);
    }
  }
  void print(){
    for(auto head:adj){
      cout << head.first << "-->";
      for(auto x:head.second){
        cout<<x<<"->";
      }
      cout<<'\n';
    }
    cout<<"\nx-----------------x\n";
  }

  void dfsHelper(int src, unordered_map<int, bool>& visited){
    if(visited[src]){
      return;
    }
    visited[src] = true;
    //cout << src << "->";
    for(auto nbr:adj[src]){
      if(!visited[nbr]){
        dfsHelper(nbr, visited);
      }
    }
  }

  void dfs(int src){
    unordered_map<int, bool> visited;
    for(auto head:adj){
      cout << head.first << "-->";
      for(auto x:head.second){
        if(!visited[x]){
          dfsHelper(src, visited);
        }
      }
    }
  }

  void visitAllVertices(int src, unordered_map<int, bool>& visited){
    if(visited[src])
      return;
    visited[src] = true;
    for(auto nbr:adj[src]){
      if(!visited[nbr]){
        visitAllVertices(nbr, visited);
      }
    }
  }

  int connectedComp(){
    unordered_map<int, bool> visited;
    int cnt=0;
    for(auto head:adj){
      if(!visited[head.first]){
        visitAllVertices(head.first, visited);
        cnt++;
      }
    }
    return cnt;
  }

  void bfs(int src){
    vector<bool> visited(v, false);
    list<int> qu;
    visited[src] = true;
    qu.push_back(src);
    list<int>::iterator i;
    while(!qu.empty()){
      src = qu.front();
      cout << src << "->";
      qu.pop_front();
      for(i = adj[src].begin(); i!= adj[src].end(); i++){
        if(!visited[*i]){
          qu.push_back(*i);
          visited[*i] = true;
        }
      }
    }
  }
};

int main(){

  Graph g(5);
  g.addEdge(0, 1, false);
  g.addEdge(0, 2, false);
  g.addEdge(1, 3, false);
  g.addEdge(2, 3, false);
  g.addEdge(4, 5, false);
  cout << g.connectedComp();
  
  return 0;
}