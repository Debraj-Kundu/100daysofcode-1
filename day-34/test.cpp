#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* left, *right;
  Node(int val){
    data = val;
    left = right = nullptr;
  }

  void inorder(Node* root){
    if(root){
      printf("%d ", root->data);
      inorder(root->left);
      inorder(root->right);
    }
  }

  void dfs(Node* root, int sum, vector<int> &ans){
    if(!root)
      return;
    sum += root->data;
    if(!root->left && !root->right){
      ans.push_back(sum);
      return;
    }
    dfs(root->left, sum, ans);
    dfs(root->right, sum, ans);
  }

  void rootToLeaf(Node* root){
    int sum=0;
    vector<int> ans;
    dfs(root, sum, ans);
    for(auto x:ans){
      cout << x << " ";
    }
  }
};



int main(){

  Node* root = new Node(30);
  root->left = new Node(10);
  root->right = new Node(50);
  root->left->left = new Node(3);
  root->left->right = new Node(16);
  root->right->left = new Node(40);
  root->right->right = new Node(60);
  //root->inorder(root);
  root->rootToLeaf(root);

  return 0;
}