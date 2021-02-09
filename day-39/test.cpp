#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
  int v;
  unordered_map<int, list<int>> adj;
  Graph(int v){
    this->v = v;
  }
  void add_edge(int u, int v){
    adj[u].push_back(v);
    /* adj[v].push_back(u); */
  }

  void dfsHelper(int src, unordered_map<int, bool> &visited){
    visited[src] = true;
		cout << src << " -> ";

		for (auto nbr : adj[src]){
			if (!visited[nbr]){
				dfsHelper(nbr, visited);
			}
		}
  }

  void dfs(int src){
    unordered_map<int, bool> visited;
    dfsHelper(src, visited);
  }
};

int main(){

  Graph g(5);
  g.add_edge(1, 0);
  g.add_edge(1, 2);
  g.add_edge(1, 5);
  g.add_edge(3, 5);
  g.add_edge(4, 5);
  g.add_edge(1, 3);
  g.dfs(3);

  return 0;
}