#include <bits/stdc++.h>
using namespace std;

class GraphL{
  int size;
  list<int>* adj;
public:
  GraphL(int size){
    this->size = size;
    adj = new list<int>[this->size];
  }
  void addEdge(int u, int v, bool bidir){
    adj[u].push_back(v);
    if(bidir){
      adj[v].push_back(u);
    }
  }

  void dfsHelper(int src, unordered_map<int, bool> &visited){
    if(visited[src]){
      return;
    }
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
    for(int i=0; i<size; i++){
      for(auto v:adj[i]){
        if(!visited[v]){
          dfsHelper(i, visited);
        }
      }
    }
  }

  void bfs(int s){
    bool *visited = new bool[size];
    for(int i = 0; i < size; i++)
      visited[i] = false;
    list<int> queue;
 
    visited[s] = true;
    queue.push_back(s);
 
    list<int>::iterator i;
 
    while(!queue.empty()){
      s = queue.front();
      cout << s << " ";
      queue.pop_front();
      for (i = adj[s].begin(); i != adj[s].end(); ++i){
        if (!visited[*i]){
          visited[*i] = true;
          queue.push_back(*i);
        }
      }
    }
  }

  void print(){
    for(int i=0; i<size; i++){
      cout << i << "-->";
      for(auto x:adj[i]){
        cout << x << ' ';
      }
      cout<<'\n';
    }
  }
};

int main(){

  GraphL g1(5);
  g1.addEdge(0, 1, false);
  g1.addEdge(0, 2, false);
  g1.addEdge(0, 3, false);
  g1.addEdge(1, 3, false);
  g1.addEdge(1, 4, false);
  g1.bfs(0);

  return 0;
}