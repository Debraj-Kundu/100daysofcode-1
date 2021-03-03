#include <bits/stdc++.h>
using namespace std;

class Graph{
  unordered_map<int, list<int>> adj;
public:
  Graph(){}
  void addEdge(int u, int v){
    adj[u].push_back(v);
    //adj[v].push_back(u);
  }

  void dfsHelper(int src, unordered_map<int, bool>& visited){
    visited[src] = true;
    cout << src << " -> ";
    for(auto nbr:adj[src])
      if(!visited[nbr])
        dfsHelper(nbr, visited);
  }

  void dfs(int src){
    unordered_map<int, bool> visited;
    dfsHelper(src, visited);
  }
};

class Node{
public:
  int data;
  Node* left, *right;
  Node(int val){
    data = val;
    left = right = nullptr;
  }
};

Node* lca(Node* root, Node* a, Node* b){
  Node* left, *right;
  if(!root)
    return root;
  if(root == a || root == b)
    return root;
  left = lca(root->left, a, b);
  right = lca(root->right, a, b);
  if(left && right)
    return root;
  else
    return left ? left : right;
}


int main(){

  /* Graph g = Graph();
  g.addEdge(1, 2);g.addEdge(1, 3);g.addEdge(1, 4);
  g.addEdge(4, 5);g.addEdge(2, 5);g.addEdge(2, 4);
  g.dfs(1); */
  Node* root = new Node(1);
  root->left = new Node(2);root->right = new Node(3);
  root->left->left = new Node(4);root->right->left = new Node(5);
  root->left->right = new Node(5);root->right->right = new Node(6);
  cout << lca(root, root->left->left, root->left->right)->data;

  return 0;
}