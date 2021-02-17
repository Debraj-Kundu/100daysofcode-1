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

  void dfs(Node* root, int sum, int &ans, int k){
    if(root == nullptr)
      return;
    sum += root->data;
    if(!root->left && !root->right){
      if(sum == k)
        ans = 1;
      return;
    }
    dfs(root->left, sum, ans, k);
    dfs(root->right, sum, ans, k);
  }

  int rootToLeafSum(Node* root, int k){
    int ans = 0;
    dfs(root, 0, ans, k);
    return ans;
  }

  Node* invert(Node* root){
    if(root){
      Node* temp=root, *left=nullptr, *right=nullptr;
      left = invert(root->left);
      right = invert(root->right);
      temp = root->left;
      root->left = root->right;
      root->right = temp;
    }
  }

  void inorer(Node* root){
    if(root){
      inorer(root->left);
      cout << root->data << " ";
      inorer(root->right);
    }
  }
  Node* lca(Node* root, Node* a, Node* b){
    if(!root)
      return root;
    if(root == a || root == b)
      return root;
    Node* left = nullptr, *right = nullptr;
    left = lca(root->left, a, b);
    right = lca(root->right, a, b);
    if(left && right)
      return root;
    else 
      return (left ? left:right);
  }

};

int main(){

  Node* root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  root->left->left = new Node(40);//70
  root->left->right = new Node(50);//80
  root->right->left = new Node(60);//100
  /* root->inorer(root);
  cout<<endl;
  root->invert(root);
  root->inorer(root);
  cout<<endl;
  cout << root->rootToLeafSum(root, 90); */
  /*
       10
   20     30  
40   50  60

      10
   30    20
    60  50  40

  */
  cout << root->lca(root, root->left->left, root->left->right)->data;

  return 0;
}