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
  
  void bfs(int src){
    unordered_map<int, bool> visited;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
      int front = q.front();
      q.pop();
      if(!visited[front]){
        cout << front << " -> ";
        visited[src] = true;
      }
      for(auto nbr:adj[front]){
          if(!visited[nbr]){
            q.push(nbr);
          }
      }
    }
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

vector<int> maxLvSum(Node* root){
  queue<Node*> q;
  int maxLv=0,maxSum=0, sum=0, lv=0;
  q.push(root);
  q.push(nullptr);
  while(!q.empty()){
    Node* front = q.front();
    q.pop();
    if(!front){
      if(sum>maxSum){
        maxSum = sum;
        maxLv = lv;
        sum = 0;
        if(!q.empty())
          q.push(nullptr);
        lv++;
      }
      else {
        sum += front->data;
        if(front->left)
          q.push(front->left);
        if(front->right)
          q.push(front->right);
      }
    }
  }
  return {maxSum, maxLv};
}

int main(){

  Graph g = Graph();
  g.addEdge(1, 2);g.addEdge(1, 3);g.addEdge(1, 4);
  g.addEdge(4, 5);g.addEdge(2, 5);g.addEdge(2, 4);
  //g.bfs(1);
  Node* root = new Node(1);
  root->left = new Node(2);root->right = new Node(3);
  root->left->left = new Node(4);root->right->left = new Node(5);
  root->left->right = new Node(5);root->right->right = new Node(6);
  vector<int> ans =  maxLvSum(root);
  cout << ans[0] << " " << ans[1];
  
  return 0;
}