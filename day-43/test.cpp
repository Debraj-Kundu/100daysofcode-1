#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* left, *right;
  Node(int v){
    data = v;
    left = right = nullptr;
  }

  void dfs(Node* root, int sum, bool &ans){
    if(root || sum >= 0){
      return;
    }
    sum -= root->data;
    if(sum == 0){
      ans = true;
      return;
    }
    dfs(root->left, sum, ans);
    dfs(root->right, sum, ans);
  }

  bool rootToLeafSum(Node* root, int sum){
    bool ans = false;
    dfs(root, sum, ans);
    return ans;
  }

};

int main(){

  Node* root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  root->left->left = new Node(40);
  root->left->right = new Node(50);
  root->right->left = new Node(60);
  cout << root->rootToLeafSum(root, 70);

  return 0;
}