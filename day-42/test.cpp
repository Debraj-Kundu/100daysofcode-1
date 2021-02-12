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

  void postOrder(Node* root){
    stack<Node*> s;
    Node* prev = nullptr;
    do{
      while(root){
        s.push(root);
        root = root->left;
      }
      while(root == nullptr && !s.empty()){
        root = s.top();
        if(root->right == nullptr || root->right == prev){
          cout << root->data << " ";
          prev = root;
          s.pop();
          root = nullptr;
        }else {
          root = root->right;
        }
      }
    }while(!s.empty());
  }

  void inOrder(Node* root){
    stack<Node*> s;
    while(1){
      while(root){
        s.push(root);
        root = root->left;
      }
      if(s.empty())
        break;
      root = s.top();s.pop();
      cout << root->data << " ";
      root = root->right;
    }
  }

  void preOrder(Node* root){
    stack<Node*> s;
    while(1){
      while(root){
        cout << root->data << " ";
        s.push(root);
        root = root->left;
      }
      if(s.empty())
        break;
      root = s.top();s.pop();
      root = root->right;
    }
  }
  void helper(Node* root, int sum, vector<int> &pathSum){
    if(!root) 
      return;
    sum += root->data;
    if(!root->left && !root->right){
      pathSum.push_back(sum);
      return;
    }
    helper(root->left, sum, pathSum);
    helper(root->right, sum, pathSum);
  }
  void rootToLeafSum(Node* root){
    int sum=0;
    vector<int> pathSum;
    helper(root, sum, pathSum);
    cout << sum << "\n";
    for(auto x:pathSum){
      cout << x << " ";
    }
  }

};

int main(){
  Node* root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  root->left->left = new Node(40);
  root->left->right = new Node(50);
  root->right->left = new Node(60);
  root->rootToLeafSum(root);

  return 0;
}