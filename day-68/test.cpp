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
  Node(int x, Node* left, Node* right){
    data = x;
    this->left = left;
    this->right = right;
  }
};

Node* addRow(Node* root, int v, int d){
  if(d == 1)
    return new Node(v, root, nullptr);
  else if(d == 2){
    root->left = new Node(v, root->left, nullptr);
    root->right = new Node(v, nullptr, root->right);
  }
  else{
    if(root->left)
      addRow(root->left, v, d-1);
    if(root->right)
      addRow(root->right, v, d-1);
  }
}

void inorder(Node* root){
  if(root){
    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
  }
}

int main(){

  Node* root = new Node(1);
  root->left = new Node(2);root->right = new Node(3);
  root->left->left = new Node(4);root->right->left = new Node(6);
  root->left->right = new Node(5);root->right->right = new Node(7);
  inorder(root);
  Node* newRoot = addRow(root, 69, 1);
  cout<<endl;
  inorder(newRoot);
  
  return 0;
}