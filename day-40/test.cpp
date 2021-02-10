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
    //adj[v].push_back(u);
  }

  void dfsHelper(int src, unordered_map<int, bool> &visited){
    visited[src] = true;
		cout << src << "->";

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

  void bfs(int src){
    unordered_map<int, bool> visited;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
      int front = q.front();q.pop();
      if(!visited[front]){
        cout << front << "->";
        visited[front] = true;
      }
      for(auto x:adj[front]){
        if(!visited[x]){
          q.push(x);
        }
      }
    }
  }
};

int main(){

  Graph g(5);
  g.add_edge(1, 2);
  g.add_edge(1, 3);
  g.add_edge(4, 2);
  g.add_edge(2, 4);
  g.add_edge(2, 5);
  g.add_edge(3, 5);
  g.add_edge(4, 5);
  g.add_edge(4, 5);
  g.add_edge(4, 6);
  g.add_edge(5, 6);
  g.bfs(1);

  return 0;
}